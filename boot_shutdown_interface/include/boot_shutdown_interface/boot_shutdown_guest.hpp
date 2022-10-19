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

#ifndef BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_GUEST_HPP_
#define BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_GUEST_HPP_

#include "boot_shutdown_interface/service/boot_shutdown_interface.hpp"

#include <rclcpp/rclcpp.hpp>

#include <boot_shutdown_api_msgs/msg/ecu_state.hpp>
#include <boot_shutdown_api_msgs/srv/execute_shutdown.hpp>
#include <boot_shutdown_api_msgs/srv/prepare_shutdown.hpp>

#include <string>

namespace boot_shutdown_interface
{
using boot_shutdown_api_msgs::msg::EcuState;
using boot_shutdown_api_msgs::srv::ExecuteShutdown;
using boot_shutdown_api_msgs::srv::PrepareShutdown;

class BootShutdownGuest : public rclcpp::Node
{
public:
  /**
   * @brief Constructor
   * @param [in] node_name Name of the node
   * @param [in] options Options associated with this node
   */
  explicit BootShutdownGuest(const rclcpp::NodeOptions & options);

private:
  rclcpp::Publisher<EcuState>::SharedPtr pub_ecu_state_;  //!< @brief Publisher to notify ECU state
  rclcpp::Service<PrepareShutdown>::SharedPtr
    srv_prepare_shutdown_;  //!< @brief Service to prepare shutdown
  rclcpp::Service<ExecuteShutdown>::SharedPtr
    srv_execute_shutdown_;              //!< @brief Service to execute shutdown
  rclcpp::TimerBase::SharedPtr timer_;  //!< @brief Timer to notify ECU state

  std::string ecu_name_;                 //!< @brief Name of ECU
  unsigned int startup_timeout_;         //!< @brief Timeout time to wait for startup completion
  unsigned int prepare_shutdown_time_;   //!< @brief Time taken for preparing for shutdown
  unsigned int execute_shutdown_time_;   //!< @brief Time taken for executing shutdown
  std::string socket_path_;              //!< @brief Path of UNIX domain socket
  EcuState ecu_state_;                   //!< @brief Current ECU state
  rclcpp::Time startup_time_;            //!< @brief Startup time
  rclcpp::Time preparation_start_time_;  //!< @brief Start time from preparing for shutdown
  int socket_;                           //!< @brief Socket to communicate with boot/shutdown service

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
   * @brief Send request to boot/shutdown service
   * @param [in] request request to boot/shutdown service
   */
  void sendRequest(Request request);

  /**
   * @brief Get status from boot/shutdown service
   * @param [in] request request to boot/shutdown service
   * @param [out] status status from boot/shutdown service
   */
  void getStatus(Request request, bool & status);

  /**
   * @brief Connect to boot/shutdown service
   * @return true on success, false on error
   */
  bool connectService();

  /**
   * @brief Send data to boot/shutdown service
   * @param [in] request request to boot/shutdown service
   * @return true on success, false on error
   */
  bool sendData(Request request);

  /**
   * @brief Receive data from boot/shutdown service
   * @param [out] status status from boot/shutdown service
   */
  void receiveData(bool & status);

  /**
   * @brief Close connection with boot/shutdown service
   */
  void closeConnection();
};

}  // namespace boot_shutdown_interface

#endif  // BOOT_SHUTDOWN_INTERFACE__BOOT_SHUTDOWN_GUEST_HPP_
