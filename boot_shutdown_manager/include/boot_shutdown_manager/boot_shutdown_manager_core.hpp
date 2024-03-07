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

#ifndef BOOT_SHUTDOWN_MANAGER__BOOT_SHUTDOWN_MANAGER_HPP_
#define BOOT_SHUTDOWN_MANAGER__BOOT_SHUTDOWN_MANAGER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <boot_shutdown_api_msgs/msg/ecu_state.hpp>
#include <boot_shutdown_api_msgs/msg/ecu_state_summary.hpp>
#include <boot_shutdown_api_msgs/srv/execute_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/prepare_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/shutdown.hpp>

#include <deque>

namespace boot_shutdown_manager
{
using boot_shutdown_api_msgs::msg::EcuState;
using boot_shutdown_api_msgs::msg::EcuStateSummary;
using boot_shutdown_api_msgs::srv::ExecuteShutdown;
using boot_shutdown_api_msgs::srv::PrepareShutdown;
using boot_shutdown_api_msgs::srv::Shutdown;

struct EcuClient
{
  EcuState::SharedPtr ecu_state;
  rclcpp::Subscription<EcuState>::SharedPtr sub_ecu_state;
  rclcpp::Client<ExecuteShutdown>::SharedPtr cli_execute;
  rclcpp::Client<PrepareShutdown>::SharedPtr cli_prepare;
  bool primary;
  bool skip_shutdown;
};

class BootShutdownManager : public rclcpp::Node
{
public:
  BootShutdownManager();

private:
  rclcpp::Publisher<EcuStateSummary>::SharedPtr pub_ecu_state_summary_;
  rclcpp::Service<Shutdown>::SharedPtr srv_shutdown;
  rclcpp::Service<Shutdown>::SharedPtr srv_force_shutdown_;
  rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr cli_webauto_;

  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::CallbackGroup::SharedPtr callback_group_;

  EcuStateSummary ecu_state_summary_;
  std::deque<std::pair<std::string, std::shared_ptr<EcuClient>>> ecu_client_queue_;
  rclcpp::Time last_transition_stamp_;
  double update_rate_;
  double startup_timeout_;
  double preparation_timeout_;
  bool is_shutting_down;
  bool is_force_shutdown_;

  void onShutdownService(
    Shutdown::Request::SharedPtr request, Shutdown::Response::SharedPtr response);
  void onForceShutdownService(
    Shutdown::Request::SharedPtr request, Shutdown::Response::SharedPtr response);

  void onTimer();
  bool isRunning() const;
  bool isReady() const;
  void executeShutdown();
};

}  // namespace boot_shutdown_manager

#endif  // BOOT_SHUTDOWN_MANAGER__BOOT_SHUTDOWN_MANAGER_HPP_
