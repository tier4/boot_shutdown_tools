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

#ifndef BOOT_SHUTDOWN_COMMUNICATION__UTILITY_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__UTILITY_HPP_

#include "google/protobuf/timestamp.pb.h"

namespace boot_shutdown_communication
{

template <typename MessageType>
void set_header(MessageType & message, const std::string & topic_name)
{
  auto * header = message.mutable_header();
  header->set_name(topic_name);

  const auto now = std::chrono::system_clock::now();
  const auto seconds =
    std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
  const auto nanos =
    std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count() %
    1000000000;

  google::protobuf::Timestamp * timestamp = header->mutable_stamp();
  timestamp->set_seconds(seconds);
  timestamp->set_nanos(nanos);
}

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__UTILITY_HPP_