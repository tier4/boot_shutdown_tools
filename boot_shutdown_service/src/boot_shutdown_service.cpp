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

#include "boot_shutdown_service/boot_shutdown_service.hpp"

#include <boost/process.hpp>

#include <iostream>

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <yaml-cpp/yaml.h>

namespace boot_shutdown_service
{

BootShutdownService::BootShutdownService(const std::string & config_yaml_path)
: config_yaml_path_(config_yaml_path),
  server_port_(parameter_.declare_parameter("server_port", 10000)),
  publisher_port_(parameter_.declare_parameter("publisher_port", 10001)),
  startup_timeout_(parameter_.declare_parameter("startup_timeout", 180)),
  prepare_shutdown_time_(parameter_.declare_parameter("prepare_shutdown_time", 1)),
  execute_shutdown_time_(parameter_.declare_parameter("execute_shutdown_time", 13)),
  prepare_shutdown_command_(
    parameter_.declare_parameter("prepare_shutdown_command", std::vector<std::string>())),
  timer_(io_context_)
{
}

bool BootShutdownService::initialize()
{
  char hostname[HOST_NAME_MAX + 1];
  gethostname(hostname, sizeof(hostname));

  using std::placeholders::_1;
  using std::placeholders::_2;

  srv_prepare_shutdown_ = ServiceServer<PrepareShutdownService>::create_service(
    fmt::format("/api/{}/prepare_shutdown", hostname), io_context_, server_port_,
    std::bind(&BootShutdownService::onPrepareShutdown, this, _1, _2));
  srv_execute_shutdown_ = ServiceServer<ExecuteShutdownService>::create_service(
    fmt::format("/api/{}/execute_shutdown", hostname), io_context_, server_port_,
    std::bind(&BootShutdownService::onExecuteShutdown, this, _1, _2));

  pub_ecu_state_ = TopicPublisher<EcuStateMessage>::create_publisher(
    fmt::format("/{}/get/ecu_state", hostname), io_context_, publisher_port_);

  startTimer();

  return true;
}

void BootShutdownService::shutdown() {}

void BootShutdownService::run()
{
  io_context_.run();
}

void BootShutdownService::prepareShutdown()
{
  is_ready_ = false;

  std::cout << "Preparing shutdown..." << std::endl;

  std::thread thread([this] {
    for (const auto & command : prepare_shutdown_command_) {
      if (!command.empty()) {
        std::cout << "Executing '"<< command << "'" << std::endl;
        boost::process::child c("/bin/sh", "-c", command);
        c.wait();
      }
    }
    {
      boost::process::child c("/bin/sh", "-c", "sync; echo 3 > /proc/sys/vm/drop_caches;");
      c.wait();
    }

    std::lock_guard<std::mutex> lock(mutex_);
    is_ready_ = true;
  });

  thread.detach();
}

void BootShutdownService::executeShutdown()
{
  std::cout << "Executing shutdown..." << std::endl;

  std::thread thread([this] {
    boost::process::child c("/bin/sh", "-c", "shutdown -h now");
    c.wait();
  });

  thread.detach();
}

void BootShutdownService::isReadyToShutdown()
{
  bool is_ready = false;
  {
    std::lock_guard<std::mutex> lock(mutex_);
    is_ready = is_ready_;
  }
}

oid BootShutdownService::onPrepareShutdown(
  const PrepareShutdownService & request, PrepareShutdownService & response)
{
  prepareShutdown();
}

void BootShutdownService::onExecuteShutdown(
  const ExecuteShutdownService & request, ExecuteShutdownService & response)
{
  executeShutdown();
}

void BootShutdownService::startTimer()
{
  timer_.expires_after(std::chrono::seconds(1));
  timer_.async_wait([this](const boost::system::error_code & error_code) { onTimer(error_code); });
}

void BootShutdownService::onTimer(const boost::system::error_code & error_code)
{
  if (!error_code) {
    pub_ecu_state_->publish(ecu_state_);
    startTimer();
  } else {
    std::cerr << "Timer error: " << error_code.message() << std::endl;
  }
}

}  // namespace boot_shutdown_service
