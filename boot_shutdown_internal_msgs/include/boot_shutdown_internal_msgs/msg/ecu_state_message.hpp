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

#ifndef BOOT_SHUTDOWN_INTERNAL_MSGS_ECU_STATE_MESSAGE_HPP_
#define BOOT_SHUTDOWN_INTERNAL_MSGS_ECU_STATE_MESSAGE_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <chrono>
#include <sstream>

namespace boot_shutdown_internal_msgs
{

namespace msg
{

enum EcuState {
  UNKNOWN = 0,
  STARTUP = 1,
  RUNNING = 2,
  SHUTDOWN_PREPARING = 3,
  SHUTDOWN_READY = 4,
  STARTUP_TIMEOUT = 1001,
  SHUTDOWN_TIMEOUT = 1002,
};

class EcuStateMessage
{
public:
  EcuStateMessage() = default;
  EcuStateMessage(
    EcuState state, const std::string & message,
    std::chrono::system_clock::time_point power_off_time)
  : state_(state), message_(message), power_off_time_(power_off_time)
  {
  }

  template <class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & state_;
    ar & message_;
    if (Archive::is_loading::value) {
      long long ms_since_epoch;
      ar & ms_since_epoch;
      power_off_time_ =
        std::chrono::system_clock::time_point(std::chrono::milliseconds(ms_since_epoch));
    } else {
      auto ms_since_epoch =
        std::chrono::duration_cast<std::chrono::milliseconds>(power_off_time_.time_since_epoch())
          .count();
      ar & ms_since_epoch;
    }
  }

  EcuState state_;
  std::string message_;
  std::chrono::system_clock::time_point power_off_time_;
};

}  // namespace msg

}  // namespace boot_shutdown_internal_msgs

#endif  // BOOT_SHUTDOWN_INTERNAL_MSGS_ECU_STATE_MESSAGE_HPP_
