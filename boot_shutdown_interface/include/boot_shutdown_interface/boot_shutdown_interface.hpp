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

#include <boot_shutdown_service/boot_shutdown_common.hpp>
#include <rclcpp/rclcpp.hpp>

#include <boot_shutdown_api_msgs/msg/ecu_state.hpp>
#include <boot_shutdown_api_msgs/srv/execute_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/prepare_shutdown.hpp>
#include <std_msgs/msg/string.hpp>

#include <memory>
#include <string>

namespace boot_shutdown_interface
{
using boot_shutdown_api_msgs::msg::EcuState;
using boot_shutdown_api_msgs::srv::ExecuteShutdown;
using boot_shutdown_api_msgs::srv::PrepareShutdown;

class BootShutdownInterface : public rclcpp::Node
{
public:
  /**
   * @brief Constructor
   * @param [in] options Options associated with this node
   */
  explicit BootShutdownInterface(const rclcpp::NodeOptions & options);

private:
  rclcpp::Publisher<EcuState>::SharedPtr pub_ecu_state_;  //!< @brief Publisher to notify ECU state
  rclcpp::GenericSubscription::SharedPtr
    sub_topic_;  //!< @brief Subscriber to check if ECU is running
  rclcpp::Service<PrepareShutdown>::SharedPtr
    srv_prepare_shutdown_;  //!< @brief Service to prepare shutdown
  rclcpp::Service<ExecuteShutdown>::SharedPtr
    srv_execute_shutdown_;              //!< @brief Service to execute shutdown
  rclcpp::TimerBase::SharedPtr timer_;  //!< @brief Timer to notify ECU state

  unsigned int startup_timeout_;        //!< @brief Timeout time to wait for startup completion
  unsigned int prepare_shutdown_time_;  //!< @brief Time taken for preparing shutdown
  unsigned int execute_shutdown_time_;  //!< @brief Time taken for executing shutdown
  std::vector<std::string> commands_;   //!< @brief List of additional prepare shutdown command

  EcuState ecu_state_;                        //!< @brief Current ECU state
  rclcpp::Time startup_time_;                 //!< @brief Startup time
  rclcpp::Time prepare_shutdown_start_time_;  //!< @brief Start time from preparing shutdown
  std::string socket_path_;                   //!< @brief Path of UNIX domain socket
  int socket_;           //!< @brief Socket to communicate with boot-shutdown service
  bool topic_received_;  //!< @brief A flag to receive topic or not

  /**
   * @brief Check topic_config parameter in yaml
   */
  void createTopicChecker();

  /**
   * @brief Callback for the service request to prepare for shutdown
   * @param [in] request Service request
   * @param [in] response Service response
   */
  void onPrepareShutdown(
    PrepareShutdown::Request::SharedPtr request, PrepareShutdown::Response::SharedPtr response);

  /**
   * @brief Callback for the service request to execute shutdown
   * @param [in] request Service request
   * @param [in] response Service response
   */
  void onExecuteShutdown(
    ExecuteShutdown::Request::SharedPtr request, ExecuteShutdown::Response::SharedPtr response);

  /**
   * @brief Callback to check if ECU is running
   * @param [in] message Topic to monitor
   */
  void onTopic(const std::shared_ptr<rclcpp::SerializedMessage> message);

  /**
   * @brief Timer callback to notify ECU state
   */
  void onTimer();

  /**
   * @brief Check if startup completion
   * @return true on running, false on not running
   */
  bool isRunning();

  /**
   * @brief Check if startup timer expired
   * @return true on timer expired, false on not expired
   */
  bool isStartupTimeout();

  /**
   * @brief Check if shutdown preparation timer expired
   * @return true on timer expired, false on not expired
   */
  bool isPreparationTimeout();

  /**
   * @brief Check if shutdown is ready
   * @return true on shutdown ready, false on not ready
   */
  bool isReady();

  /**
   * @brief Send request to boot-shutdown service
   */
  void sendPrepareShutdownRequest();

  /**
   * @brief Send request to boot-shutdown service
   */
  void sendExecuteShutdownRequest();

  /**
   * @brief Get status from boot-shutdown service
   * @param [in] request Request to boot-shutdown service
   * @param [out] status Status from boot-shutdown service
   */
  void getStatus(boot_shutdown_service::Request request, bool & status);

  /**
   * @brief Connect to boot-shutdown service
   * @return true on success, false on error
   */
  bool connectService();

  /**
   * @brief Send data to boot-shutdown service
   * @param [in] request Request to boot-shutdown service
   * @return true on success, false on error
   */
  bool sendData(boot_shutdown_service::Request request);

  /**
   * @brief Send data to boot-shutdown service with parameters
   * @param [in] request Request to boot-shutdown service
   * @param [in] parameters List of parameters
   * @return true on success, false on error
   */
  bool sendDataWithParameters(
    boot_shutdown_service::Request request, std::vector<std::string> & parameters);

  /**
   * @brief Receive data from boot-shutdown service
   * @param [out] status Status from boot-shutdown service
   */
  void receiveData(bool & status);

  /**
   * @brief Close connection with boot-shutdown service
   */
  void closeConnection();
};

}  // namespace boot_shutdown_interface

#endif  // BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_INTERFACE_HPP_
