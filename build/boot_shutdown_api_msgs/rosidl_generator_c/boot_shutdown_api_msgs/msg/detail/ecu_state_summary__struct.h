// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_H_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'summary'
// Member 'details'
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.h"

// Struct defined in msg/EcuStateSummary in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__msg__EcuStateSummary
{
  boot_shutdown_api_msgs__msg__EcuState summary;
  boot_shutdown_api_msgs__msg__EcuState__Sequence details;
} boot_shutdown_api_msgs__msg__EcuStateSummary;

// Struct for a sequence of boot_shutdown_api_msgs__msg__EcuStateSummary.
typedef struct boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence
{
  boot_shutdown_api_msgs__msg__EcuStateSummary * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_H_
