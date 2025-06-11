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

#ifndef BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
#define BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_

#include "boot_shutdown_communication/service_server.hpp"
#include "boot_shutdown_communication/topic_publisher.hpp"
#include "boot_shutdown_common/parameter.hpp"

#include "boot_shutdown_internal_msgs/ecu_state_message.pb.h"
#include "boot_shutdown_internal_msgs/execute_shutdown_service.pb.h"
#include "boot_shutdown_internal_msgs/prepare_shutdown_service.pb.h"

#include <boost/asio.hpp>

#include <mutex>

namespace boot_shutdown_service
{

using boot_shutdown_common::Parameter;
using boot_shutdown_communication::ServiceServer;
using boot_shutdown_communication::TopicPublisher;
using boot_shutdown_internal_msgs::msg::EcuStateMessage;
using boot_shutdown_internal_msgs::msg::EcuStateType;
using boot_shutdown_internal_msgs::srv::ExecuteShutdownService;
using boot_shutdown_internal_msgs::srv::PrepareShutdownService;

class BootShutdownService
{
public:
  explicit BootShutdownService(const std::string & config_yaml_path);
  BootShutdownService(const BootShutdownService&) = delete;
  BootShutdownService(BootShutdownService&&) = delete;
  BootShutdownService& operator=(const BootShutdownService&) = delete;
  BootShutdownService& operator=(BootShutdownService&&) = delete;
  bool initialize();
  void run();
  void shutdown();

private:
  static void signalHandler(int signum);

  void onPrepareShutdown(const PrepareShutdownService & request, PrepareShutdownService & response);
  void onExecuteShutdown(const ExecuteShutdownService & request, ExecuteShutdownService & response);

  void startTimer();
  void onTimer(const boost::system::error_code & error_code);

  void publish_ecu_state_message();
  void prepareShutdown();
  void executeShutdown();

  bool isRunning() const;
  bool isStartupTimeout() const;
  bool isPreparationTimeout() const;
  bool isReady() const;

  void setTimestamp(
    google::protobuf::Timestamp * timestamp,
    const std::chrono::system_clock::time_point & time_point);

  std::string config_yaml_path_;
  Parameter parameter_{config_yaml_path_};

  std::vector<std::string> topic_address_;
  unsigned short topic_port_;

  unsigned short prepare_shutdown_port_;
  unsigned short execute_shutdown_port_;

  std::vector<std::string> prepare_shutdown_command_;
  unsigned int startup_timeout_;
  unsigned int prepare_shutdown_time_;
  unsigned int execute_shutdown_time_;

  boost::asio::io_context io_context_;

  ServiceServer<PrepareShutdownService>::SharedPtr srv_prepare_shutdown_;
  ServiceServer<ExecuteShutdownService>::SharedPtr srv_execute_shutdown_;

  std::vector<TopicPublisher<EcuStateMessage>::SharedPtr> pub_ecu_state_;
  EcuStateMessage ecu_state_;
  boost::asio::steady_timer timer_;
  std::mutex ecu_state_mutex_;

  mutable std::mutex mutex_;
  bool is_ready_;

  std::chrono::system_clock::time_point startup_time_;
  std::chrono::system_clock::time_point prepare_shutdown_start_time_;

  static BootShutdownService * instance;
};

}  // namespace boot_shutdown_service

#endif  // BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
