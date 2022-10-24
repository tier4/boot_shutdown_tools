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

namespace boot_shutdown_interface
{

BootShutdownInterface::BootShutdownInterface(const rclcpp::NodeOptions & options)
: Node("boot_shutdown", options),
  ecu_name_(declare_parameter("ecu_name", std::string("ecu"))),
  startup_timeout_(declare_parameter("startup_timeout", 180)),
  prepare_shutdown_time_(declare_parameter("prepare_shutdown_time", 1)),
  execute_shutdown_time_(declare_parameter("execute_shutdown_time", 13))
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

  auto qos = rclcpp::QoS{1};
  if (declare_parameter(
      "topic_config.transient_local",
      static_cast<rclcpp::ParameterValue>(false)).get<bool>())
  {
    qos.transient_local();
  }
  if (declare_parameter(
      "topic_config.best_effort",
      static_cast<rclcpp::ParameterValue>(false)).get<bool>())
  {
    qos.best_effort();
  }

  sub_topic_ = create_generic_subscription(
    declare_parameter("topic_config.name", rclcpp::PARAMETER_STRING).get<std::string>(),
    declare_parameter("topic_config.type", rclcpp::PARAMETER_STRING).get<std::string>(),
    qos, std::bind(&BootShutdownInterface::onTopic, this, std::placeholders::_1));

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
    "sync; echo 3 > /proc/sys/vm/drop_caches");

  ecu_state_.state = EcuState::SHUTDOWN_PREPARING;
  prepare_shutdown_start_time_ = get_clock()->now();

  response->status.success = true;
  response->power_off_time = prepare_shutdown_start_time_ + rclcpp::Duration(
    prepare_shutdown_time_ + execute_shutdown_time_, 0);
}

void BootShutdownInterface::onExecuteShutdown(
  ExecuteShutdown::Request::SharedPtr, ExecuteShutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "shutdown executing...");

  // Shutdown
  // Avoid using "now" and delay shutdown to publish ecu_state
  shutdown_child_ = boost::process::child("/bin/sh", "-c", "shutdown -h now");

  ecu_state_.power_off_time = get_clock()->now() + rclcpp::Duration(execute_shutdown_time_, 0);
  response->status.success = true;
  response->power_off_time = ecu_state_.power_off_time;
}

void BootShutdownInterface::onTopic(
  [[maybe_unused]] const std::shared_ptr<rclcpp::SerializedMessage> msg)
{
  if (ecu_state_.state == EcuState::STARTUP) {
    ecu_state_.state = EcuState::RUNNING;
  }
}

void BootShutdownInterface::onTimer()
{
  if (ecu_state_.state == EcuState::STARTUP) {
    if (isStartupTimeout()) {
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
  return !(preparation_child_.running());
}

}  // namespace boot_shutdown_interface

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(boot_shutdown_interface::BootShutdownInterface)
