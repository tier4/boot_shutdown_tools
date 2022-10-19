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

#ifndef BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_INTERFACE_HPP_
#define BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_INTERFACE_HPP_

namespace boot_shutdown_interface
{

  static constexpr char SOCKET_PATH[] = "/tmp/boot_shutdown";

  enum Request
  {
    NONE = 0,
    PREPARE_SHUTDOWN,
    EXECUTE_SHUTDOWN,
    IS_READY_TO_SHUTDOWN,
  };

} // namespace boot_shutdown_interface

#endif // BOOT_SHUTDOWN_INTERFACE__SERVICE__BOOT_SHUTDOWN_INTERFACE_HPP_
