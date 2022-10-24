// Copyright 2022 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "boot_shutdown_interface/boot_shutdown_guest.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <sys/socket.h>
#include <sys/un.h>

namespace boot_shutdown_interface {

BootShutdownGuest::BootShutdownGuest(const rclcpp::NodeOptions &options)
    : Node("boot_shutdown_guest", options),
      ecu_name_(declare_parameter("ecu_name", std::string("ecu"))),
      startup_timeout_(declare_parameter("startup_timeout", 180)),
      prepare_shutdown_time_(declare_parameter("prepare_shutdown_time", 180)),
      execute_shutdown_time_(declare_parameter("execute_shutdown_time", 180)),
      socket_path_(declare_parameter("socket_path", SOCKET_PATH)), socket_(-1) {
  using namespace std::literals::chrono_literals;
  using std::placeholders::_1;
  using std::placeholders::_2;

  ecu_state_.name = ecu_name_;
  ecu_state_.state = EcuState::STARTUP;
  startup_time_ = get_clock()->now();

  srv_prepare_shutdown_ = create_service<PrepareShutdown>(
      "~/service/prepare_shutdown",
      std::bind(&BootShutdownGuest::onPrepareShutdown, this, _1, _2),
      rmw_qos_profile_default);

  srv_execute_shutdown_ = create_service<ExecuteShutdown>(
      "~/service/execute_shutdown",
      std::bind(&BootShutdownGuest::onExecuteShutdown, this, _1, _2),
      rmw_qos_profile_default);

  pub_ecu_state_ =
      create_publisher<EcuState>("~/output/ecu_state", rclcpp::QoS{1});

  timer_ = rclcpp::create_timer(this, get_clock(), 1s,
                                std::bind(&BootShutdownGuest::onTimer, this));
}

void BootShutdownGuest::onPrepareShutdown(
    PrepareShutdown::Request::SharedPtr,
    PrepareShutdown::Response::SharedPtr response) {
  RCLCPP_INFO(get_logger(), "Preparing for shutdown ...");

  sendRequest(PREPARE_SHUTDOWN);

  ecu_state_.state = EcuState::SHUTDOWN_PREPARING;
  preparation_start_time_ = get_clock()->now();

  response->status.success = true;
  response->power_off_time =
      get_clock()->now() + rclcpp::Duration(prepare_shutdown_time_, 0);
}

void BootShutdownGuest::onExecuteShutdown(
    ExecuteShutdown::Request::SharedPtr,
    ExecuteShutdown::Response::SharedPtr response) {
  RCLCPP_INFO(get_logger(), "Executing shutdown ...");

  sendRequest(EXECUTE_SHUTDOWN);

  ecu_state_.power_off_time =
      get_clock()->now() + rclcpp::Duration(execute_shutdown_time_, 0);
  response->status.success = true;
  response->power_off_time = ecu_state_.power_off_time;
}

void BootShutdownGuest::onTimer() {
  if (ecu_state_.state == EcuState::STARTUP) {
    if (isRunning()) {
      ecu_state_.state = EcuState::RUNNING;
    } else if (isStartupTimeout()) {
      ecu_state_.state = EcuState::STARTUP_TIMEOUT;
    }
  } else if (ecu_state_.state == EcuState::SHUTDOWN_PREPARING) {
    if (isReady()) {
      ecu_state_.state = EcuState::SHUTDOWN_READY;
    } else if (isPreparationTimeout()) {
      ecu_state_.state = EcuState::SHUTDOWN_TIMEOUT;
    }
  }

  pub_ecu_state_->publish(ecu_state_);
}

bool BootShutdownGuest::isRunning() {
  // implement process to check for startup
  return true;
}

bool BootShutdownGuest::isStartupTimeout() {
  return (get_clock()->now() - startup_time_) >
         rclcpp::Duration(startup_timeout_, 0);
}

bool BootShutdownGuest::isPreparationTimeout() {
  return (get_clock()->now() - preparation_start_time_) >
         rclcpp::Duration(prepare_shutdown_time_, 0);
}

bool BootShutdownGuest::isReady() {
  bool status = true;
  getStatus(Request::IS_READY_TO_SHUTDOWN, status);
  return status;
}

void BootShutdownGuest::sendRequest(Request request) {
  // Connect to boot/shutdown service
  if (!connectService()) {
    closeConnection();
    return;
  }

  // Send data to boot/shutdown service
  if (!sendData(request)) {
    closeConnection();
    return;
  }

  // Close connection with boot/shutdown service
  closeConnection();
}

void BootShutdownGuest::getStatus(Request request, bool &status) {
  // Connect to boot/shutdown service
  if (!connectService()) {
    closeConnection();
    return;
  }

  // Send data to boot/shutdown service
  if (!sendData(request)) {
    closeConnection();
    return;
  }

  // Receive data from boot/shutdown service
  receiveData(status);

  // Close connection with boot/shutdown service
  closeConnection();
}

bool BootShutdownGuest::connectService() {
  // Create a new socket
  socket_ = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_ < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to create a new socket. %s",
                 strerror(errno));
    return false;
  }

  sockaddr_un addr = {};
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, socket_path_.c_str(), sizeof(addr.sun_path) - 1);

  int ret = connect(socket_, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to connect. %s", strerror(errno));
    close(socket_);
    return false;
  }

  return true;
}

bool BootShutdownGuest::sendData(Request request) {
  std::ostringstream out_stream;
  boost::archive::text_oarchive archive(out_stream);
  archive &request;

  int ret = write(socket_, out_stream.str().c_str(), out_stream.str().length());
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to write N bytes of BUF to FD. %s",
                 strerror(errno));
    return false;
  }

  return true;
}

void BootShutdownGuest::receiveData(bool &status) {
  char buffer[1024]{};
  uint8_t request_id = Request::NONE;

  int ret = recv(socket_, buffer, sizeof(buffer) - 1, 0);
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to recv. %s", strerror(errno));
    return;
  }
  // No data received
  if (ret == 0) {
    RCLCPP_ERROR(get_logger(), "No data received.");
    return;
  }

  // Restore device status list
  try {
    std::istringstream in_stream(buffer);
    boost::archive::text_iarchive archive(in_stream);
    archive >> request_id; // No checking id
    archive >> status;
  } catch (const std::exception &e) {
    RCLCPP_ERROR(get_logger(), "Failed to restore message. %s\n", e.what());
  }
}

void BootShutdownGuest::closeConnection() {
  // Close the file descriptor FD
  close(socket_);
}

} // namespace boot_shutdown_interface

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(boot_shutdown_interface::BootShutdownGuest)
