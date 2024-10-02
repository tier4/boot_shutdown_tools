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

#include <mutex>

namespace boot_shutdown_service
{

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

  std::string config_yaml_path_;  //!< @brief Configuration yaml file path
  std::mutex mutex_;              //!< @brief Mutex guard for the flag
  bool is_ready_;                 //!< @brief Ready to execute shutdown

  int timeout_duration_;
  unsigned short service_port_;
  unsigned short publisher_port_;
};

}  // namespace boot_shutdown_service

#endif  // BOOT_SHUTDOWN__SERVICE__BOOT_SHUTDOWN_SERVICE_HPP_
