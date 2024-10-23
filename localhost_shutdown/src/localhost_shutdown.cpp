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

#include "localhost_shutdown/localhost_shutdown.hpp"

#include <iostream>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

namespace boot_shutdown_service
{

LocalhostShutdown::LocalhostShutdown()
: service_address_(std::string("127.0.0.1")),
  service_timeout_(1),
  prepare_shutdown_port_(10001),
  execute_shutdown_port_(10002)
{
}

void LocalhostShutdown::initialize()
{
  char hostname[HOST_NAME_MAX + 1];
  gethostname(hostname, sizeof(hostname));

  std::replace(hostname, hostname + sizeof(hostname), '-', '_');

  const std::string prepare_service_name = fmt::format("/api/{}/prepare_shutdown", hostname);
  const std::string execute_service_name = fmt::format("/api/{}/execute_shutdown", hostname);

  cli_execute_ = ServiceClient<ExecuteShutdownService>::create_client(
    execute_service_name, io_context_, service_address_, execute_shutdown_port_, service_timeout_);
  cli_prepare_ = ServiceClient<PrepareShutdownService>::create_client(
    prepare_service_name, io_context_, service_address_, prepare_shutdown_port_, service_timeout_);
}

void LocalhostShutdown::run()
{
  prepareShutdown();
  executeShutdown();
  io_context_.run();
}

void LocalhostShutdown::prepareShutdown()
{
  try {
    PrepareShutdownService req;
    auto resp = cli_prepare_->call(req);
  } catch (const std::runtime_error & e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred." << std::endl;
  }
}

void LocalhostShutdown::executeShutdown()
{
  try {
    ExecuteShutdownService req;
    auto resp = cli_execute_->call(req);
  } catch (const std::runtime_error & e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred." << std::endl;
  }
}

}  // namespace boot_shutdown_service
