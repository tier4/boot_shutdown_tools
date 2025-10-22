// Copyright 2022-2025 TIER IV, Inc.
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

#include "boot_shutdown_communication/service_client.hpp"
#include "boot_shutdown_communication/topic_subscriber.hpp"
#include "topic_condition_evaluator/topic_condition_evaluator.hpp"

#include <rclcpp/rclcpp.hpp>

#include "boot_shutdown_internal_msgs/ecu_state_message.pb.h"
#include "boot_shutdown_internal_msgs/execute_shutdown_service.pb.h"
#include "boot_shutdown_internal_msgs/prepare_shutdown_service.pb.h"
#include <boot_shutdown_api_msgs/msg/ecu_state.hpp>
#include <boot_shutdown_api_msgs/msg/ecu_state_summary.hpp>
#include <boot_shutdown_api_msgs/msg/shutdown_ready_state.hpp>
#include <boot_shutdown_api_msgs/srv/execute_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/prepare_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/shutdown.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <boost/asio.hpp>

#include <deque>

namespace boot_shutdown_manager
{
using boot_shutdown_api_msgs::msg::EcuState;
using boot_shutdown_api_msgs::msg::EcuStateSummary;
using boot_shutdown_api_msgs::msg::ShutdownReadyState;
using boot_shutdown_api_msgs::srv::Shutdown;

using boot_shutdown_communication::ServiceClient;
using boot_shutdown_communication::TopicSubscriber;
using boot_shutdown_internal_msgs::msg::EcuStateMessage;
using boot_shutdown_internal_msgs::msg::EcuStateType;
using boot_shutdown_internal_msgs::srv::ExecuteShutdownService;
using boot_shutdown_internal_msgs::srv::PrepareShutdownService;

using topic_condition_evaluator::ConditionNotification;

struct EcuClient
{
  EcuStateMessage ecu_state;
  TopicSubscriber<EcuStateMessage>::SharedPtr sub_ecu_state;
  ServiceClient<ExecuteShutdownService>::SharedPtr cli_execute;
  ServiceClient<PrepareShutdownService>::SharedPtr cli_prepare;
  bool primary;
  bool skip_shutdown;
};

class BootShutdownManager : public rclcpp::Node
{
public:
  BootShutdownManager();
  ~BootShutdownManager();

private:
  rclcpp::Publisher<EcuStateSummary>::SharedPtr pub_ecu_state_summary_;
  rclcpp::Publisher<ShutdownReadyState>::SharedPtr pub_shutdown_ready_state_;
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

  boost::asio::io_context io_context_;
  std::thread io_thread_;
  unsigned short topic_port_;
  int service_timeout_;
  double aggregation_timeout_sec_;
  std::atomic<bool> shutdown_ready_{true};

  topic_condition_evaluator::TopicConditionEvaluator topic_condition_evaluator_;

  void onShutdownService(
    Shutdown::Request::SharedPtr request, Shutdown::Response::SharedPtr response);
  void onForceShutdownService(
    Shutdown::Request::SharedPtr request, Shutdown::Response::SharedPtr response);

  void onTimer();
  bool isRunning() const;
  bool isReady() const;
  void executeShutdown();

  rclcpp::Time convertToRclcppTime(const google::protobuf::Timestamp & proto_time);

  void onConditionNotification(const ConditionNotification & notification);
};

}  // namespace boot_shutdown_manager

#endif  // BOOT_SHUTDOWN_MANAGER__BOOT_SHUTDOWN_MANAGER_HPP_
