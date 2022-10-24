// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace boot_shutdown_api_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void EcuStateSummary_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) boot_shutdown_api_msgs::msg::EcuStateSummary(_init);
}

void EcuStateSummary_fini_function(void * message_memory)
{
  auto typed_message = static_cast<boot_shutdown_api_msgs::msg::EcuStateSummary *>(message_memory);
  typed_message->~EcuStateSummary();
}

size_t size_function__EcuStateSummary__details(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<boot_shutdown_api_msgs::msg::EcuState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EcuStateSummary__details(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<boot_shutdown_api_msgs::msg::EcuState> *>(untyped_member);
  return &member[index];
}

void * get_function__EcuStateSummary__details(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<boot_shutdown_api_msgs::msg::EcuState> *>(untyped_member);
  return &member[index];
}

void resize_function__EcuStateSummary__details(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<boot_shutdown_api_msgs::msg::EcuState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EcuStateSummary_message_member_array[2] = {
  {
    "summary",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<boot_shutdown_api_msgs::msg::EcuState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuStateSummary, summary),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "details",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<boot_shutdown_api_msgs::msg::EcuState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuStateSummary, details),  // bytes offset in struct
    nullptr,  // default value
    size_function__EcuStateSummary__details,  // size() function pointer
    get_const_function__EcuStateSummary__details,  // get_const(index) function pointer
    get_function__EcuStateSummary__details,  // get(index) function pointer
    resize_function__EcuStateSummary__details  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EcuStateSummary_message_members = {
  "boot_shutdown_api_msgs::msg",  // message namespace
  "EcuStateSummary",  // message name
  2,  // number of fields
  sizeof(boot_shutdown_api_msgs::msg::EcuStateSummary),
  EcuStateSummary_message_member_array,  // message members
  EcuStateSummary_init_function,  // function to initialize message memory (memory has to be allocated)
  EcuStateSummary_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EcuStateSummary_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EcuStateSummary_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace boot_shutdown_api_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<boot_shutdown_api_msgs::msg::EcuStateSummary>()
{
  return &::boot_shutdown_api_msgs::msg::rosidl_typesupport_introspection_cpp::EcuStateSummary_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, boot_shutdown_api_msgs, msg, EcuStateSummary)() {
  return &::boot_shutdown_api_msgs::msg::rosidl_typesupport_introspection_cpp::EcuStateSummary_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
