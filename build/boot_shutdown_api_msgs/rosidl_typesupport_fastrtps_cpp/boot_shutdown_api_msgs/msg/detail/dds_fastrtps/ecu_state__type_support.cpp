// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace boot_shutdown_api_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
cdr_serialize(
  const boot_shutdown_api_msgs::msg::EcuState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: state
  cdr << ros_message.state;
  // Member: name
  cdr << ros_message.name;
  // Member: message
  cdr << ros_message.message;
  // Member: power_off_time
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.power_off_time,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  boot_shutdown_api_msgs::msg::EcuState & ros_message)
{
  // Member: state
  cdr >> ros_message.state;

  // Member: name
  cdr >> ros_message.name;

  // Member: message
  cdr >> ros_message.message;

  // Member: power_off_time
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.power_off_time);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
get_serialized_size(
  const boot_shutdown_api_msgs::msg::EcuState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: state
  {
    size_t item_size = sizeof(ros_message.state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);
  // Member: power_off_time

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.power_off_time, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
max_serialized_size_EcuState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: power_off_time
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _EcuState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::msg::EcuState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EcuState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<boot_shutdown_api_msgs::msg::EcuState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EcuState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::msg::EcuState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EcuState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_EcuState(full_bounded, 0);
}

static message_type_support_callbacks_t _EcuState__callbacks = {
  "boot_shutdown_api_msgs::msg",
  "EcuState",
  _EcuState__cdr_serialize,
  _EcuState__cdr_deserialize,
  _EcuState__get_serialized_size,
  _EcuState__max_serialized_size
};

static rosidl_message_type_support_t _EcuState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EcuState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace boot_shutdown_api_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<boot_shutdown_api_msgs::msg::EcuState>()
{
  return &boot_shutdown_api_msgs::msg::typesupport_fastrtps_cpp::_EcuState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, msg, EcuState)() {
  return &boot_shutdown_api_msgs::msg::typesupport_fastrtps_cpp::_EcuState__handle;
}

#ifdef __cplusplus
}
#endif
