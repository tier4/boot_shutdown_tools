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

#include "boot_shutdown_interface/boot_shutdown_interface.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

#include <sys/socket.h>
#include <sys/un.h>

#include <climits>
#include <regex>

namespace boot_shutdown_interface
{
BootShutdownInterface::BootShutdownInterface(const rclcpp::NodeOptions & options)
: Node("boot_shutdown", options),
  startup_timeout_(declare_parameter("startup_timeout", 180)),
  prepare_shutdown_time_(declare_parameter("prepare_shutdown_time", 1)),
  execute_shutdown_time_(declare_parameter("execute_shutdown_time", 13)),
  commands_(declare_parameter("additional_prepare_shutdown_command", std::vector<std::string>())),
  socket_path_(declare_parameter("socket_path", boot_shutdown_service::SOCKET_PATH)),
  socket_(-1)
{
  using namespace std::literals::chrono_literals;
  using std::placeholders::_1;
  using std::placeholders::_2;

  // Get hostname
  char hostname[HOST_NAME_MAX + 1];
  gethostname(hostname, sizeof(hostname));

  ecu_state_.name = hostname;
  ecu_state_.state = EcuState::STARTUP;
  startup_time_ = get_clock()->now();

  srv_prepare_shutdown_ = create_service<PrepareShutdown>(
    "~/service/prepare_shutdown",
    std::bind(&BootShutdownInterface::onPrepareShutdown, this, _1, _2), rmw_qos_profile_default);

  srv_execute_shutdown_ = create_service<ExecuteShutdown>(
    "~/service/execute_shutdown",
    std::bind(&BootShutdownInterface::onExecuteShutdown, this, _1, _2), rmw_qos_profile_default);

  pub_ecu_state_ = create_publisher<EcuState>("~/output/ecu_state", rclcpp::QoS{1});

  try {
    createTopicChecker();
  } catch (const std::exception & e) {
    RCLCPP_INFO(
      get_logger(), "topic config is not set, set ecu state to running, ERROR: %s", e.what());
    topic_received_ = true;
  }

  timer_ =
    rclcpp::create_timer(this, get_clock(), 1s, std::bind(&BootShutdownInterface::onTimer, this));
}

void BootShutdownInterface::createTopicChecker()
{
  auto qos = rclcpp::QoS{1};
  if (declare_parameter("topic_config.transient_local", static_cast<rclcpp::ParameterValue>(false))
        .get<bool>()) {
    qos.transient_local();
  }
  if (declare_parameter("topic_config.best_effort", static_cast<rclcpp::ParameterValue>(false))
        .get<bool>()) {
    qos.best_effort();
  }

  sub_topic_ = create_generic_subscription(
    declare_parameter("topic_config.name", rclcpp::PARAMETER_STRING).get<std::string>(),
    declare_parameter("topic_config.type", rclcpp::PARAMETER_STRING).get<std::string>(), qos,
    std::bind(&BootShutdownInterface::onTopic, this, std::placeholders::_1));
}

void BootShutdownInterface::onPrepareShutdown(
  PrepareShutdown::Request::SharedPtr, PrepareShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "Preparing Shutdown...");

  sendPrepareShutdownRequest();

  ecu_state_.state = EcuState::SHUTDOWN_PREPARING;
  prepare_shutdown_start_time_ = get_clock()->now();

  ecu_state_.power_off_time = prepare_shutdown_start_time_ +
                             rclcpp::Duration(prepare_shutdown_time_ + execute_shutdown_time_, 0);
  response->status.success = true;
  response->power_off_time = ecu_state_.power_off_time;
}

void BootShutdownInterface::onExecuteShutdown(
  ExecuteShutdown::Request::SharedPtr, ExecuteShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "Executing shutdown...");

  sendExecuteShutdownRequest();

  response->status.success = true;
  response->power_off_time = get_clock()->now() + rclcpp::Duration(execute_shutdown_time_, 0);
}

void BootShutdownInterface::onTopic(
  [[maybe_unused]] const std::shared_ptr<rclcpp::SerializedMessage> msg)
{
  topic_received_ = true;
}

void BootShutdownInterface::onTimer()
{
  // allow recover from timeout
  if (ecu_state_.state == EcuState::STARTUP || ecu_state_.state == EcuState::STARTUP_TIMEOUT) {
    if (isRunning()) {
      ecu_state_.state = EcuState::RUNNING;
    } else if (isStartupTimeout()) {
      ecu_state_.state = EcuState::STARTUP_TIMEOUT;
    }
  } else if (
    ecu_state_.state == EcuState::SHUTDOWN_PREPARING ||
    ecu_state_.state == EcuState::SHUTDOWN_TIMEOUT) {
    if (isReady()) {
      ecu_state_.state = EcuState::SHUTDOWN_READY;
    } else if (isPreparationTimeout()) {
      ecu_state_.state = EcuState::SHUTDOWN_TIMEOUT;
    }
  }

  pub_ecu_state_->publish(ecu_state_);
}

bool BootShutdownInterface::isRunning() { return topic_received_; }

bool BootShutdownInterface::isStartupTimeout()
{
  return (get_clock()->now() - startup_time_) > rclcpp::Duration(startup_timeout_, 0);
}

bool BootShutdownInterface::isPreparationTimeout()
{
  return (get_clock()->now() - prepare_shutdown_start_time_) >
         rclcpp::Duration(prepare_shutdown_time_, 0);
}

bool BootShutdownInterface::isReady()
{
  bool status = true;
  getStatus(boot_shutdown_service::IS_READY_TO_SHUTDOWN, status);
  return status;
}

void BootShutdownInterface::sendPrepareShutdownRequest()
{
  // Connect to boot/shutdown service
  if (!connectService()) {
    closeConnection();
    return;
  }

  // Send data to boot/shutdown service
  if (!sendDataWithParameters(boot_shutdown_service::PREPARE_SHUTDOWN, commands_)) {
    closeConnection();
    return;
  }

  // Close connection with boot/shutdown service
  closeConnection();
}

void BootShutdownInterface::sendExecuteShutdownRequest()
{
  // Connect to boot/shutdown service
  if (!connectService()) {
    closeConnection();
    return;
  }

  // Send data to boot/shutdown service
  if (!sendData(boot_shutdown_service::EXECUTE_SHUTDOWN)) {
    closeConnection();
    return;
  }

  // Close connection with boot/shutdown service
  closeConnection();
}

void BootShutdownInterface::getStatus(boot_shutdown_service::Request request, bool & status)
{
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

bool BootShutdownInterface::connectService()
{
  // Create a new socket
  socket_ = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_ < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to create a new socket. %s", strerror(errno));
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

bool BootShutdownInterface::sendData(boot_shutdown_service::Request request)
{
  std::ostringstream out_stream;
  boost::archive::text_oarchive archive(out_stream);
  archive & request;

  int ret = write(socket_, out_stream.str().c_str(), out_stream.str().length());
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to write N bytes of BUF to FD. %s", strerror(errno));
    return false;
  }

  return true;
}

bool BootShutdownInterface::sendDataWithParameters(
  boot_shutdown_service::Request request, std::vector<std::string> & parameters)
{
  std::ostringstream out_stream;
  boost::archive::text_oarchive archive(out_stream);
  archive & request;
  archive & parameters;

  int ret = write(socket_, out_stream.str().c_str(), out_stream.str().length());
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to write N bytes of BUF to FD. %s", strerror(errno));
    return false;
  }

  return true;
}

void BootShutdownInterface::receiveData(bool & status)
{
  char buffer[1024]{};
  uint8_t request_id = boot_shutdown_service::Request::NONE;

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
    archive >> request_id;
    archive >> status;
  } catch (const std::exception & e) {
    RCLCPP_ERROR(get_logger(), "Failed to restore message. %s\n", e.what());
  }
}

void BootShutdownInterface::closeConnection()
{
  // Close the file descriptor FD
  close(socket_);
}

}  // namespace boot_shutdown_interface

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(boot_shutdown_interface::BootShutdownInterface)
