// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/srv/detail/shutdown__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "boot_shutdown_api_msgs/srv/detail/shutdown__struct.h"
#include "boot_shutdown_api_msgs/srv/detail/shutdown__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Shutdown_Request__ros_msg_type = boot_shutdown_api_msgs__srv__Shutdown_Request;

static bool _Shutdown_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Shutdown_Request__ros_msg_type * ros_message = static_cast<const _Shutdown_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _Shutdown_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Shutdown_Request__ros_msg_type * ros_message = static_cast<_Shutdown_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t get_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Shutdown_Request__ros_msg_type * ros_message = static_cast<const _Shutdown_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Shutdown_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t max_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _Shutdown_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Shutdown_Request = {
  "boot_shutdown_api_msgs::srv",
  "Shutdown_Request",
  _Shutdown_Request__cdr_serialize,
  _Shutdown_Request__cdr_deserialize,
  _Shutdown_Request__get_serialized_size,
  _Shutdown_Request__max_serialized_size
};

static rosidl_message_type_support_t _Shutdown_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Shutdown_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Request)() {
  return &_Shutdown_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/shutdown__struct.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/shutdown__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "autoware_adapi_v1_msgs/msg/detail/response_status__functions.h"  // status

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_boot_shutdown_api_msgs
size_t get_serialized_size_autoware_adapi_v1_msgs__msg__ResponseStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_boot_shutdown_api_msgs
size_t max_serialized_size_autoware_adapi_v1_msgs__msg__ResponseStatus(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autoware_adapi_v1_msgs, msg, ResponseStatus)();


using _Shutdown_Response__ros_msg_type = boot_shutdown_api_msgs__srv__Shutdown_Response;

static bool _Shutdown_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Shutdown_Response__ros_msg_type * ros_message = static_cast<const _Shutdown_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, autoware_adapi_v1_msgs, msg, ResponseStatus
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->status, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Shutdown_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Shutdown_Response__ros_msg_type * ros_message = static_cast<_Shutdown_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, autoware_adapi_v1_msgs, msg, ResponseStatus
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->status))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t get_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Shutdown_Response__ros_msg_type * ros_message = static_cast<const _Shutdown_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status

  current_alignment += get_serialized_size_autoware_adapi_v1_msgs__msg__ResponseStatus(
    &(ros_message->status), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Shutdown_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t max_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: status
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_autoware_adapi_v1_msgs__msg__ResponseStatus(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Shutdown_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_boot_shutdown_api_msgs__srv__Shutdown_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Shutdown_Response = {
  "boot_shutdown_api_msgs::srv",
  "Shutdown_Response",
  _Shutdown_Response__cdr_serialize,
  _Shutdown_Response__cdr_deserialize,
  _Shutdown_Response__get_serialized_size,
  _Shutdown_Response__max_serialized_size
};

static rosidl_message_type_support_t _Shutdown_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Shutdown_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Response)() {
  return &_Shutdown_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "boot_shutdown_api_msgs/srv/shutdown.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Shutdown__callbacks = {
  "boot_shutdown_api_msgs::srv",
  "Shutdown",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Response)(),
};

static rosidl_service_type_support_t Shutdown__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Shutdown__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown)() {
  return &Shutdown__handle;
}

#if defined(__cplusplus)
}
#endif
