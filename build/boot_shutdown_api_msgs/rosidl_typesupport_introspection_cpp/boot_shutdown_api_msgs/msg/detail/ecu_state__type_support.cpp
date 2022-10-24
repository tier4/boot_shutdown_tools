// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.hpp"
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

void EcuState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) boot_shutdown_api_msgs::msg::EcuState(_init);
}

void EcuState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<boot_shutdown_api_msgs::msg::EcuState *>(message_memory);
  typed_message->~EcuState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EcuState_message_member_array[4] = {
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuState, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuState, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuState, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "power_off_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs::msg::EcuState, power_off_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EcuState_message_members = {
  "boot_shutdown_api_msgs::msg",  // message namespace
  "EcuState",  // message name
  4,  // number of fields
  sizeof(boot_shutdown_api_msgs::msg::EcuState),
  EcuState_message_member_array,  // message members
  EcuState_init_function,  // function to initialize message memory (memory has to be allocated)
  EcuState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EcuState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EcuState_message_members,
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
get_message_type_support_handle<boot_shutdown_api_msgs::msg::EcuState>()
{
  return &::boot_shutdown_api_msgs::msg::rosidl_typesupport_introspection_cpp::EcuState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, boot_shutdown_api_msgs, msg, EcuState)() {
  return &::boot_shutdown_api_msgs::msg::rosidl_typesupport_introspection_cpp::EcuState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
