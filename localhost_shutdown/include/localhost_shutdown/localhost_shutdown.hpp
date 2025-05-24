// Copyright 2022 The Autoware Contributors
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

#ifndef LOCALHOST_SHUTDOWN__LOCALHOST_SHUTDOWN_HPP_
#define LOCALHOST_SHUTDOWN__LOCALHOST_SHUTDOWN_HPP_

#include "boot_shutdown_communication/service_client.hpp"
#include "boot_shutdown_communication/topic_subscriber.hpp"
#include "boot_shutdown_common/parameter.hpp"

#include "boot_shutdown_internal_msgs/ecu_state_message.pb.h"
#include "boot_shutdown_internal_msgs/execute_shutdown_service.pb.h"
#include "boot_shutdown_internal_msgs/prepare_shutdown_service.pb.h"

#include <boost/asio.hpp>

#include <mutex>

namespace localhost_shutdown
{

using boot_shutdown_common::Parameter;
using boot_shutdown_communication::ServiceClient;
using boot_shutdown_communication::TopicSubscriber;
using boot_shutdown_internal_msgs::msg::EcuStateMessage;
using boot_shutdown_internal_msgs::msg::EcuStateType;
using boot_shutdown_internal_msgs::srv::ExecuteShutdownService;
using boot_shutdown_internal_msgs::srv::PrepareShutdownService;

class LocalhostShutdown
{
public:
  explicit LocalhostShutdown(const std::string & config_yaml_path);
  void initialize();
  void run();

protected:
  void prepareShutdown();
  void executeShutdown();

  void startTimer();
  void onTimer(const boost::system::error_code & error_code);

  std::string config_yaml_path_;
  Parameter parameter_{config_yaml_path_};

  unsigned short topic_port_;

  std::string service_address_;
  int service_timeout_;
  int preparation_timeout_;
  unsigned short prepare_shutdown_port_;
  unsigned short execute_shutdown_port_;

  boost::asio::io_context io_context_;

  ServiceClient<ExecuteShutdownService>::SharedPtr cli_execute_;
  ServiceClient<PrepareShutdownService>::SharedPtr cli_prepare_;

  EcuStateMessage ecu_state_;
  TopicSubscriber<EcuStateMessage>::SharedPtr sub_ecu_state_;

  std::chrono::steady_clock::time_point prepare_shutdown_timeout_time_;
  boost::asio::steady_timer timer_;
  std::mutex ecu_state_mutex_;
};

}  // namespace localhost_shutdown

#endif  // LOCALHOST_SHUTDOWN__LOCALHOST_SHUTDOWN_HPP_
