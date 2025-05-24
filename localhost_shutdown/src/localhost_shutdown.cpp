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

namespace localhost_shutdown
{

LocalhostShutdown::LocalhostShutdown(const std::string & config_yaml_path)
: config_yaml_path_(config_yaml_path),
  topic_port_(parameter_.declare_parameter("topic_port", 10000)),
  service_address_(parameter_.declare_parameter("service_address", std::string("127.0.0.1"))),
  service_timeout_(parameter_.declare_parameter("service_timeout", 1)),
  preparation_timeout_(parameter_.declare_parameter("preparation_timeout", 60)),
  prepare_shutdown_port_(parameter_.declare_parameter("prepare_shutdown_port", 10001)),
  execute_shutdown_port_(parameter_.declare_parameter("execute_shutdown_port", 10002)),
  timer_(io_context_)
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

  sub_ecu_state_ = TopicSubscriber<EcuStateMessage>::create_subscription(
    fmt::format("/{}/get/ecu_state", hostname), io_context_, topic_port_,
    [this](const EcuStateMessage & message) {
      std::lock_guard<std::mutex> lock(ecu_state_mutex_);
      ecu_state_ = message;
    });
}

void LocalhostShutdown::run()
{
  prepareShutdown();
  prepare_shutdown_timeout_time_ =
    std::chrono::steady_clock::now() + std::chrono::seconds(preparation_timeout_);
  startTimer();

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

void LocalhostShutdown::startTimer()
{
  timer_.expires_after(std::chrono::seconds(1));
  timer_.async_wait([this](const boost::system::error_code & error_code) { onTimer(error_code); });
}

void LocalhostShutdown::onTimer(const boost::system::error_code & error_code)
{
  if (!error_code) {
    EcuStateMessage ecu_state;
    {
      std::lock_guard<std::mutex> lock(ecu_state_mutex_);
      ecu_state = ecu_state_;
    }
    if (ecu_state.state() == EcuStateType::SHUTDOWN_READY) {
      std::cout << "Shutdown is ready, shutdown." << std::endl;
      executeShutdown();
      return;
    }
    if (std::chrono::steady_clock::now() >= prepare_shutdown_timeout_time_) {
      std::cerr << "Shutdown timeout reached, forcing shutdown." << std::endl;
      executeShutdown();
      return;
    }
    startTimer();
  } else {
    std::cerr << "Timer error: " << error_code.message() << std::endl;
  }
}

}  // namespace localhost_shutdown
