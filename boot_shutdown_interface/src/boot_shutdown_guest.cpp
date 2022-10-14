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

namespace boot_shutdown_interface
{

BootShutdownGuest::BootShutdownGuest(const rclcpp::NodeOptions & options)
: Node("boot_shutdown_guest", options),
  ecu_name_(declare_parameter("ecu_name", std::string("ecu"))),
  startup_timeout_(declare_parameter("startup_timeout", 180)),
  prepare_shutdown_time_(declare_parameter("prepare_shutdown_time", 180)),
  execute_shutdown_time_(declare_parameter("execute_shutdown_time", 180))
{
  using namespace std::literals::chrono_literals;
  using std::placeholders::_1;
  using std::placeholders::_2;

  ecu_state_.name = ecu_name_;
  ecu_state_.state = EcuState::STARTUP;
  startup_time_ = get_clock()->now();

  srv_prepare_shutdown_ = create_service<PrepareShutdown>(
    "~/service/prepare_shutdown", std::bind(&BootShutdownGuest::onPrepareShutdown, this, _1, _2),
    rmw_qos_profile_default);

  srv_execute_shutdown_ = create_service<ExecuteShutdown>(
    "~/service/execute_shutdown", std::bind(&BootShutdownGuest::onExecuteShutdown, this, _1, _2),
    rmw_qos_profile_default);

  pub_ecu_state_ = create_publisher<EcuState>("~/output/ecu_state", rclcpp::QoS{1});

  timer_ =
    rclcpp::create_timer(this, get_clock(), 1s, std::bind(&BootShutdownGuest::onTimer, this));
}

void BootShutdownGuest::onPrepareShutdown(
  PrepareShutdown::Request::SharedPtr, PrepareShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "Preparing for shutdown ...");

  sendRequestToHost(PREPARE_SHUTDOWN);

  ecu_state_.state = EcuState::SHUTDOWN_PREPARING;
  preparation_start_time_ = get_clock()->now();

  response->status.success = true;
  response->power_off_time = get_clock()->now() + rclcpp::Duration(prepare_shutdown_time_, 0);
}

void BootShutdownGuest::onExecuteShutdown(
  ExecuteShutdown::Request::SharedPtr, ExecuteShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "Executing shutdown ...");

  sendRequestToHost(EXECUTE_SHUTDOWN);

  ecu_state_.power_off_time = get_clock()->now() + rclcpp::Duration(execute_shutdown_time_, 0);
  response->status.success = true;
  response->power_off_time = ecu_state_.power_off_time;
}

void BootShutdownGuest::onTimer()
{
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

bool BootShutdownGuest::isRunning()
{
  // implement process to check for startup
  return true;
}

bool BootShutdownGuest::isStartupTimeout()
{
  return (get_clock()->now() - startup_time_) > rclcpp::Duration(startup_timeout_, 0);
}

bool BootShutdownGuest::isPreparationTimeout()
{
  return (get_clock()->now() - preparation_start_time_) > rclcpp::Duration(prepare_shutdown_time_, 0);
}

bool BootShutdownGuest::isReady() { return !(preparation_child_.running()); }

bool BootShutdownGuest::sendRequestToHost(Request request)
{
  // Create a new socket
  int sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to create a new socket. %s\n", strerror(errno));
    return false;
  }

  sockaddr_un addr = {};
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "/tmp/boot_shutdown", sizeof(addr.sun_path) - 1);

  int ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    close(sock);
    return false;
  }

  std::ostringstream oss;
  boost::archive::text_oarchive oa(oss);
  oa & request;

  ret = write(sock, oss.str().c_str(), oss.str().length());
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to write N bytes of BUF to FD. %s\n", strerror(errno));
    return false;
  }

  // Close the file descriptor FD
  ret = close(sock);
  if (ret < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to close socket. %s\n", strerror(errno));
    return false;
  }

  return true;
}

}  // namespace boot_shutdown_interface

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(boot_shutdown_interface::BootShutdownGuest)
