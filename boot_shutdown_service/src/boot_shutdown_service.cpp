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

#include <yaml-cpp/yaml.h>

namespace boot_shutdown_service
{

BootShutdownService::BootShutdownService(const std::string & config_yaml_path)
: config_yaml_path_(config_yaml_path)
{
}

bool BootShutdownService::initialize()
{
  try {
    YAML::Node config = YAML::LoadFile(config_yaml_path_);
            
    timeout_duration_ = config["timeout_duration"].as<int>();
    service_port_ = config["service_port"].as<unsigned short>();
    publisher_port_ = config["publisher_port"].as<unsigned short>();
  } catch (const YAML::Exception &e) {
    std::cerr << "Error loading YAML file: " << e.what() << std::endl;
    return false;
  }

  return true;
}

void BootShutdownService::shutdown() {}

void BootShutdownService::run()
{
}

void BootShutdownService::prepareShutdown()
{
  is_ready_ = false;

  std::cout << "Preparing shutdown..." << std::endl;

  std::vector<std::string> commands;

  std::thread thread([this, commands] {
    for (const auto & command : commands) {
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

}  // namespace boot_shutdown_service
