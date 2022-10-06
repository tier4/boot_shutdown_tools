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

#include "boot_shutdown_interface/boot_shutdown_interface_core.hpp"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

namespace boot_shutdown_interface
{

BootShutdownInterface::BootShutdownInterface()
: Node("boot_shutdown"),
  ecu_name_(declare_parameter("ecu_name", std::string("ecu"))),
  startup_timeout_(declare_parameter("startup_timeout", 300)),
  preparation_timeout_(declare_parameter("preparation_timeout", 60)),
  // Artificial delay for debugging
  preparation_delay_(declare_parameter("debug.preparation_delay", 5))
{
  using namespace std::literals::chrono_literals;
  using std::placeholders::_1;
  using std::placeholders::_2;

  ecu_state_.name = ecu_name_;
  ecu_state_.state = EcuState::STARTUP;
  startup_time_ = get_clock()->now();

  srv_prepare_shutdown_ = create_service<PrepareShutdown>(
    "~/service/prepare_shutdown", std::bind(
      &BootShutdownInterface::onPrepareShutdown, this, _1,
      _2),
    rmw_qos_profile_default);

  srv_execute_shutdown_ = create_service<ExecuteShutdown>(
    "~/service/execute_shutdown", std::bind(
      &BootShutdownInterface::onExecuteShutdown, this, _1,
      _2),
    rmw_qos_profile_default);

  pub_ecu_state_ =
    create_publisher<EcuState>("~/output/ecu_state", rclcpp::QoS{1});

  timer_ = rclcpp::create_timer(
    this, get_clock(), 1s, std::bind(&BootShutdownInterface::onTimer, this));
}

void BootShutdownInterface::onPrepareShutdown(
  PrepareShutdown::Request::SharedPtr, PrepareShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "shutdown preparing...");

  // Clear pagecache, dentries, and inodes.
  preparation_child_ = boost::process::child(
    "/bin/sh", "-c",
    fmt::format("sync; echo 3 > /proc/sys/vm/drop_caches; sleep {}", preparation_delay_));

  ecu_state_.state = EcuState::SHUTDOWN_PREPARING;
  preparation_start_time_ = get_clock()->now();

  response->status.success = true;
  response->power_off_time =
    builtin_interfaces::msg::Time(get_clock()->now() + rclcpp::Duration(preparation_delay_, 0));
}

void BootShutdownInterface::onExecuteShutdown(
  ExecuteShutdown::Request::SharedPtr, ExecuteShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "shutdown executing...");

  // Shutdown
  // Avoid using "now" and delay shutdown to publish ecu_state
  shutdown_child_ = boost::process::child("/bin/sh", "-c", fmt::format("shutdown -h now"));

  auto power_off_time = builtin_interfaces::msg::Time(get_clock()->now());
  ecu_state_.power_off_time = power_off_time;
  response->status.success = true;
  response->power_off_time = power_off_time;
}

void BootShutdownInterface::onTimer()
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

bool BootShutdownInterface::isRunning()
{
  // implement process to check for startup
  return true;
}

bool BootShutdownInterface::isStartupTimeout()
{
  return (get_clock()->now() - startup_time_) > rclcpp::Duration(startup_timeout_, 0);
}

bool BootShutdownInterface::isPreparationTimeout()
{
  return (get_clock()->now() - preparation_start_time_) > rclcpp::Duration(preparation_timeout_, 0);
}

bool BootShutdownInterface::isReady()
{
  return !(preparation_child_.running());
}

}  // namespace boot_shutdown_interface
