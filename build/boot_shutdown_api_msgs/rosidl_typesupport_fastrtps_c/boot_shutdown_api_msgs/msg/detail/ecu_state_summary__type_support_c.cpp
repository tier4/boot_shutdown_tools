// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__functions.h"
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

#include "boot_shutdown_api_msgs/msg/detail/ecu_state__functions.h"  // details, summary

// forward declare type support functions
size_t get_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuState)();


using _EcuStateSummary__ros_msg_type = boot_shutdown_api_msgs__msg__EcuStateSummary;

static bool _EcuStateSummary__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EcuStateSummary__ros_msg_type * ros_message = static_cast<const _EcuStateSummary__ros_msg_type *>(untyped_ros_message);
  // Field name: summary
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->summary, cdr))
    {
      return false;
    }
  }

  // Field name: details
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuState
      )()->data);
    size_t size = ros_message->details.size;
    auto array_ptr = ros_message->details.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _EcuStateSummary__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EcuStateSummary__ros_msg_type * ros_message = static_cast<_EcuStateSummary__ros_msg_type *>(untyped_ros_message);
  // Field name: summary
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->summary))
    {
      return false;
    }
  }

  // Field name: details
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuState
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->details.data) {
      boot_shutdown_api_msgs__msg__EcuState__Sequence__fini(&ros_message->details);
    }
    if (!boot_shutdown_api_msgs__msg__EcuState__Sequence__init(&ros_message->details, size)) {
      fprintf(stderr, "failed to create array for field 'details'");
      return false;
    }
    auto array_ptr = ros_message->details.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t get_serialized_size_boot_shutdown_api_msgs__msg__EcuStateSummary(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EcuStateSummary__ros_msg_type * ros_message = static_cast<const _EcuStateSummary__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name summary

  current_alignment += get_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
    &(ros_message->summary), current_alignment);
  // field.name details
  {
    size_t array_size = ros_message->details.size;
    auto array_ptr = ros_message->details.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EcuStateSummary__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_boot_shutdown_api_msgs__msg__EcuStateSummary(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_boot_shutdown_api_msgs
size_t max_serialized_size_boot_shutdown_api_msgs__msg__EcuStateSummary(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: summary
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
        full_bounded, current_alignment);
    }
  }
  // member: details
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_boot_shutdown_api_msgs__msg__EcuState(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _EcuStateSummary__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_boot_shutdown_api_msgs__msg__EcuStateSummary(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_EcuStateSummary = {
  "boot_shutdown_api_msgs::msg",
  "EcuStateSummary",
  _EcuStateSummary__cdr_serialize,
  _EcuStateSummary__cdr_deserialize,
  _EcuStateSummary__get_serialized_size,
  _EcuStateSummary__max_serialized_size
};

static rosidl_message_type_support_t _EcuStateSummary__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EcuStateSummary,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, msg, EcuStateSummary)() {
  return &_EcuStateSummary__type_support;
}

#if defined(__cplusplus)
}
#endif
