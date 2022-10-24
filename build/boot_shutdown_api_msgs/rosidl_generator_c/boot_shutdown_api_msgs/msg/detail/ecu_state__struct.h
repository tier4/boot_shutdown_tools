// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_H_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'UNKNOWN'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__UNKNOWN = 0
};

/// Constant 'STARTUP'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__STARTUP = 1
};

/// Constant 'RUNNING'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__RUNNING = 2
};

/// Constant 'SHUTDOWN_PREPARING'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__SHUTDOWN_PREPARING = 3
};

/// Constant 'SHUTDOWN_READY'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__SHUTDOWN_READY = 4
};

/// Constant 'STARTUP_TIMEOUT'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__STARTUP_TIMEOUT = 1001
};

/// Constant 'SHUTDOWN_TIMEOUT'.
enum
{
  boot_shutdown_api_msgs__msg__EcuState__SHUTDOWN_TIMEOUT = 1002
};

// Include directives for member types
// Member 'name'
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'power_off_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/EcuState in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__msg__EcuState
{
  uint16_t state;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String message;
  builtin_interfaces__msg__Time power_off_time;
} boot_shutdown_api_msgs__msg__EcuState;

// Struct for a sequence of boot_shutdown_api_msgs__msg__EcuState.
typedef struct boot_shutdown_api_msgs__msg__EcuState__Sequence
{
  boot_shutdown_api_msgs__msg__EcuState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__msg__EcuState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_H_
