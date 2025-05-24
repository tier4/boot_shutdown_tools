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

#ifndef BOOT_SHUTDOWN__COMMON__PARAMETER_HPP_
#define BOOT_SHUTDOWN__COMMON__PARAMETER_HPP_

#include <yaml-cpp/yaml.h>

#include <iostream>
#include <string>
#include <unordered_map>

namespace boot_shutdown_common
{

class Parameter
{
public:
  Parameter(const std::string & file_path) { loadConfig(file_path); }

  template <typename T>
  T declare_parameter(const std::string & name, const T & default_value)
  {
    if (parameters_.find(name) != parameters_.end()) {
      return parameters_[name].as<T>();
    } else {
       parameters_[name] = default_value;
      return default_value;
    }
  }

private:
  void loadConfig(const std::string & file_path)
  {
    try {
      YAML::Node config = YAML::LoadFile(file_path);

      for (const auto & key : config) {
        parameters_[key.first.as<std::string>()] = key.second;
      }
    } catch (const YAML::Exception & e) {
      std::cerr << "Error loading YAML file: " << e.what() << std::endl;
    }
  }

  std::unordered_map<std::string, YAML::Node> parameters_;
};

}  // namespace boot_shutdown_common

#endif  // BOOT_SHUTDOWN__COMMON__PARAMETER_HPP_
