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

#ifndef BOOT_SHUTDOWN__SERVICE__LOCALHOST_SHUTDOWN_HPP_
#define BOOT_SHUTDOWN__SERVICE__LOCALHOST_SHUTDOWN_HPP_

#include "boot_shutdown_communication/service_client.hpp"

#include "boot_shutdown_internal_msgs/execute_shutdown_service.pb.h"
#include "boot_shutdown_internal_msgs/prepare_shutdown_service.pb.h"

#include <boost/asio.hpp>

namespace boot_shutdown_service
{

using boot_shutdown_communication::ServiceClient;
using boot_shutdown_internal_msgs::srv::ExecuteShutdownService;
using boot_shutdown_internal_msgs::srv::PrepareShutdownService;

class LocalhostShutdown
{
public:
  LocalhostShutdown();
  void initialize();
  void run();

protected:
  void prepareShutdown();
  void executeShutdown();

  std::string service_address_;
  int service_timeout_;
  unsigned short prepare_shutdown_port_;
  unsigned short execute_shutdown_port_;

  ServiceClient<ExecuteShutdownService>::SharedPtr cli_execute_;
  ServiceClient<PrepareShutdownService>::SharedPtr cli_prepare_;

  boost::asio::io_context io_context_;
};

}  // namespace boot_shutdown_service

#endif  // BOOT_SHUTDOWN__SERVICE__LOCALHOST_SHUTDOWN_HPP_
