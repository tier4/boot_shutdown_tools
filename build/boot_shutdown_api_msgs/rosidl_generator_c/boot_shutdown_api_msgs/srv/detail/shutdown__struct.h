// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_H_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Shutdown in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__srv__Shutdown_Request
{
  uint8_t structure_needs_at_least_one_member;
} boot_shutdown_api_msgs__srv__Shutdown_Request;

// Struct for a sequence of boot_shutdown_api_msgs__srv__Shutdown_Request.
typedef struct boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence
{
  boot_shutdown_api_msgs__srv__Shutdown_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "autoware_adapi_v1_msgs/msg/detail/response_status__struct.h"

// Struct defined in srv/Shutdown in the package boot_shutdown_api_msgs.
typedef struct boot_shutdown_api_msgs__srv__Shutdown_Response
{
  autoware_adapi_v1_msgs__msg__ResponseStatus status;
} boot_shutdown_api_msgs__srv__Shutdown_Response;

// Struct for a sequence of boot_shutdown_api_msgs__srv__Shutdown_Response.
typedef struct boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence
{
  boot_shutdown_api_msgs__srv__Shutdown_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_H_
