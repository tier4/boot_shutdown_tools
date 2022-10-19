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

#ifndef BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
#define BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_

#include "boot_shutdown_interface/service/boot_shutdown_interface.hpp"

#include <mutex>

namespace boot_shutdown_interface {

class BootShutdownService {
public:
  /**
   * @brief Constructor
   * @param[in] socket_path Path of UNIX domain socket
   */
  explicit BootShutdownService(const std::string &socket_path);

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
   * @brief Handle messsage
   * @param[in] buffer pointer to data received
   */
  void handleMessage(const char *buffer);

  /**
   * @brief Prepare for shutdown
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

  std::string socket_path_; //!< @brief Path of UNIX domain socket
  int port_;                //!< @brief Port number to access l2ping service
  int socket_;              //!< @brief Socket to communicate with ros node
  int connection_;   //!< @brief Accepted socket for the incoming connection
  std::mutex mutex_; //!< @brief Mutex guard for the flag
  bool is_ready_;    //!< @brief Ready to execute shutdown
};

} // namespace boot_shutdown_interface

#endif // BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
