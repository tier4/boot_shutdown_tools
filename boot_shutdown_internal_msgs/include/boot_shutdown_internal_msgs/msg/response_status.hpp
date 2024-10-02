// Copyright 2024 TIER IV, Inc.
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

#ifndef BOOT_SHUTDOWN_INTERNAL_MSGS_REPOSNSE_STATUS_HPP_
#define BOOT_SHUTDOWN_INTERNAL_MSGS_REPOSNSE_STATUS_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <chrono>
#include <sstream>

namespace boot_shutdown_internal_msgs
{

namespace msg
{

enum Code {
  SERVICE_UNKNOWN = 50000,
  SERVICE_UNREADY = 50001,
  SERVICE_TIMEOUT = 50002,
  TRANSFORM_ERROR = 50003,
  PARAMETER_ERROR = 50004,
  DEPRECATED = 60000,
  NO_EFFECT = 60001,
};

class ResponseStatus
{
public:
  ResponseStatus() = default;
  ResponseStatus(bool success, Code code, const std::string & message)
  : success_(success), code_(code), message_(message)
  {
  }

  template <class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & success_;
    ar & code_;
    ar & message_;
  }

  bool success_;
  Code code_;
  std::string message_;
};

}  // namespace msg

}  // namespace boot_shutdown_internal_msgs

#endif  // BOOT_SHUTDOWN_INTERNAL_MSGS_REPOSNSE_STATUS_HPP_
