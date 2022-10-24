// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from boot_shutdown_api_msgs:srv/ExecuteShutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__STRUCT_H_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ExecuteShutdown in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__srv__ExecuteShutdown_Request
{
  uint8_t structure_needs_at_least_one_member;
} boot_shutdown_api_msgs__srv__ExecuteShutdown_Request;

// Struct for a sequence of boot_shutdown_api_msgs__srv__ExecuteShutdown_Request.
typedef struct boot_shutdown_api_msgs__srv__ExecuteShutdown_Request__Sequence
{
  boot_shutdown_api_msgs__srv__ExecuteShutdown_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__srv__ExecuteShutdown_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "autoware_adapi_v1_msgs/msg/detail/response_status__struct.h"
// Member 'power_off_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in srv/ExecuteShutdown in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__srv__ExecuteShutdown_Response
{
  autoware_adapi_v1_msgs__msg__ResponseStatus status;
  builtin_interfaces__msg__Time power_off_time;
} boot_shutdown_api_msgs__srv__ExecuteShutdown_Response;

// Struct for a sequence of boot_shutdown_api_msgs__srv__ExecuteShutdown_Response.
typedef struct boot_shutdown_api_msgs__srv__ExecuteShutdown_Response__Sequence
{
  boot_shutdown_api_msgs__srv__ExecuteShutdown_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__srv__ExecuteShutdown_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__STRUCT_H_
