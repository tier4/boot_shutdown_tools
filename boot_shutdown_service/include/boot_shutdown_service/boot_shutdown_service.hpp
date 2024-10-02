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

#ifndef BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
#define BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_

#include "boot_shutdown_service/parameter.hpp"
#include "boot_shutdown_udp/service_server.hpp"
#include "boot_shutdown_udp/topic_publisher.hpp"

#include "boot_shutdown_internal_msgs/msg/ecu_state_message.hpp"
#include "boot_shutdown_internal_msgs/srv/execute_shutdown_service.hpp"
#include "boot_shutdown_internal_msgs/srv/prepare_shutdown_service.hpp"

#include <boost/asio.hpp>

#include <mutex>

namespace boot_shutdown_service
{

using boot_shutdown_internal_msgs::msg::EcuState;
using boot_shutdown_internal_msgs::msg::EcuStateMessage;
using boot_shutdown_internal_msgs::srv::ExecuteShutdownService;
using boot_shutdown_internal_msgs::srv::PrepareShutdownService;
using boot_shutdown_udp::ServiceServer;
using boot_shutdown_udp::TopicPublisher;

class BootShutdownService
{
public:
  /**
   * @brief Constructor
   * @param[in] config_yaml_path Configuration yaml file path
   */
  explicit BootShutdownService(const std::string & config_yaml_path);

  /**
   * @brief Initialization
   * @return true on success, false on error
   */
  bool initialize();

  /**
   * @brief Shutdown
   */
  void shutdown();

  /**
   * @brief Main loop
   */
  void run();

protected:
  /**
   * @brief Prepare shutdown
   */
  void prepareShutdown();

  /**
   * @brief Execute shutdown
   */
  void executeShutdown();

  /**
   * @brief Return if ready to execute shutdown or not
   */
  void isReadyToShutdown();

  void onPrepareShutdown(const PrepareShutdownService & request, PrepareShutdownService & response);
  void onExecuteShutdown(const ExecuteShutdownService & request, ExecuteShutdownService & response);

  void startTimer();
  void onTimer(const boost::system::error_code & error_code);

  std::string config_yaml_path_;
  Parameter parameter_{config_yaml_path_};

  unsigned short server_port_;
  unsigned short publisher_port_;
  std::vector<std::string> prepare_shutdown_command_;
  unsigned int startup_timeout_;
  unsigned int prepare_shutdown_time_;
  unsigned int execute_shutdown_time_;

  boost::asio::io_context io_context_;

  ServiceServer<PrepareShutdownService>::SharedPtr srv_prepare_shutdown_;
  ServiceServer<ExecuteShutdownService>::SharedPtr srv_execute_shutdown_;

  TopicPublisher<EcuStateMessage>::SharedPtr pub_ecu_state_;
  EcuStateMessage ecu_state_;
  boost::asio::steady_timer timer_;

  std::mutex mutex_;
  bool is_ready_;
};

}  // namespace boot_shutdown_service

#endif  // BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
