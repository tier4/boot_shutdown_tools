// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from boot_shutdown_api_msgs:srv/PrepareShutdown.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__rosidl_typesupport_fastrtps_cpp.hpp"
#include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__struct.hpp"

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

namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
cdr_serialize(
  const boot_shutdown_api_msgs::srv::PrepareShutdown_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  boot_shutdown_api_msgs::srv::PrepareShutdown_Request & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
get_serialized_size(
  const boot_shutdown_api_msgs::srv::PrepareShutdown_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
max_serialized_size_PrepareShutdown_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _PrepareShutdown_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::srv::PrepareShutdown_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PrepareShutdown_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<boot_shutdown_api_msgs::srv::PrepareShutdown_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PrepareShutdown_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::srv::PrepareShutdown_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PrepareShutdown_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PrepareShutdown_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _PrepareShutdown_Request__callbacks = {
  "boot_shutdown_api_msgs::srv",
  "PrepareShutdown_Request",
  _PrepareShutdown_Request__cdr_serialize,
  _PrepareShutdown_Request__cdr_deserialize,
  _PrepareShutdown_Request__get_serialized_size,
  _PrepareShutdown_Request__max_serialized_size
};

static rosidl_message_type_support_t _PrepareShutdown_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PrepareShutdown_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<boot_shutdown_api_msgs::srv::PrepareShutdown_Request>()
{
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, srv, PrepareShutdown_Request)() {
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace autoware_adapi_v1_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const autoware_adapi_v1_msgs::msg::ResponseStatus &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  autoware_adapi_v1_msgs::msg::ResponseStatus &);
size_t get_serialized_size(
  const autoware_adapi_v1_msgs::msg::ResponseStatus &,
  size_t current_alignment);
size_t
max_serialized_size_ResponseStatus(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace autoware_adapi_v1_msgs

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
cdr_serialize(
  const boot_shutdown_api_msgs::srv::PrepareShutdown_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: status
  autoware_adapi_v1_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.status,
    cdr);
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
  boot_shutdown_api_msgs::srv::PrepareShutdown_Response & ros_message)
{
  // Member: status
  autoware_adapi_v1_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.status);

  // Member: power_off_time
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.power_off_time);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
get_serialized_size(
  const boot_shutdown_api_msgs::srv::PrepareShutdown_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: status

  current_alignment +=
    autoware_adapi_v1_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.status, current_alignment);
  // Member: power_off_time

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.power_off_time, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_boot_shutdown_api_msgs
max_serialized_size_PrepareShutdown_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: status
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        autoware_adapi_v1_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ResponseStatus(
        full_bounded, current_alignment);
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

static bool _PrepareShutdown_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::srv::PrepareShutdown_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PrepareShutdown_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<boot_shutdown_api_msgs::srv::PrepareShutdown_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PrepareShutdown_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const boot_shutdown_api_msgs::srv::PrepareShutdown_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PrepareShutdown_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PrepareShutdown_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _PrepareShutdown_Response__callbacks = {
  "boot_shutdown_api_msgs::srv",
  "PrepareShutdown_Response",
  _PrepareShutdown_Response__cdr_serialize,
  _PrepareShutdown_Response__cdr_deserialize,
  _PrepareShutdown_Response__get_serialized_size,
  _PrepareShutdown_Response__max_serialized_size
};

static rosidl_message_type_support_t _PrepareShutdown_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PrepareShutdown_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<boot_shutdown_api_msgs::srv::PrepareShutdown_Response>()
{
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, srv, PrepareShutdown_Response)() {
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _PrepareShutdown__callbacks = {
  "boot_shutdown_api_msgs::srv",
  "PrepareShutdown",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, srv, PrepareShutdown_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, srv, PrepareShutdown_Response)(),
};

static rosidl_service_type_support_t _PrepareShutdown__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PrepareShutdown__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_boot_shutdown_api_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<boot_shutdown_api_msgs::srv::PrepareShutdown>()
{
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, boot_shutdown_api_msgs, srv, PrepareShutdown)() {
  return &boot_shutdown_api_msgs::srv::typesupport_fastrtps_cpp::_PrepareShutdown__handle;
}

#ifdef __cplusplus
}
#endif
