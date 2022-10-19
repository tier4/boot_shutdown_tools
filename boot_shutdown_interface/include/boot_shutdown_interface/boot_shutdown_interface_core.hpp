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

#ifndef BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_INTERFACE_HPP_
#define BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_INTERFACE_HPP_

#include <rclcpp/rclcpp.hpp>

#include <boot_shutdown_api_msgs/msg/ecu_state.hpp>
#include <boot_shutdown_api_msgs/srv/execute_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/prepare_shutdown.hpp>

#include <boost/process.hpp>

#include <string>

namespace boot_shutdown_interface {
using boot_shutdown_api_msgs::msg::EcuState;
using boot_shutdown_api_msgs::srv::ExecuteShutdown;
using boot_shutdown_api_msgs::srv::PrepareShutdown;

class BootShutdownInterface : public rclcpp::Node {
public:
  BootShutdownInterface();

private:
  rclcpp::Publisher<EcuState>::SharedPtr pub_ecu_state_;
  rclcpp::Service<PrepareShutdown>::SharedPtr srv_prepare_shutdown_;
  rclcpp::Service<ExecuteShutdown>::SharedPtr srv_execute_shutdown_;
  rclcpp::TimerBase::SharedPtr timer_;

  std::string ecu_name_;
  unsigned int startup_timeout_;
  unsigned int preparation_timeout_;
  unsigned int preparation_delay_;
  EcuState ecu_state_;
  rclcpp::Time startup_time_;
  rclcpp::Time preparation_start_time_;
  boost::process::child preparation_child_;
  boost::process::child shutdown_child_;

  void onPrepareShutdown(PrepareShutdown::Request::SharedPtr request,
                         PrepareShutdown::Response::SharedPtr response);
  void onExecuteShutdown(ExecuteShutdown::Request::SharedPtr request,
                         ExecuteShutdown::Response::SharedPtr response);
  void onTimer();
  bool isRunning();
  bool isStartupTimeout();
  bool isPreparationTimeout();
  bool isReady();
};

} // namespace boot_shutdown_interface

#endif // BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_INTERFACE_HPP_
