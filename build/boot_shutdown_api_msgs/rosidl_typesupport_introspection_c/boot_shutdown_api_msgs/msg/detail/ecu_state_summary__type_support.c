// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__rosidl_typesupport_introspection_c.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__functions.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.h"


// Include directives for member types
// Member `summary`
// Member `details`
#include "boot_shutdown_api_msgs/msg/ecu_state.h"
// Member `summary`
// Member `details`
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  boot_shutdown_api_msgs__msg__EcuStateSummary__init(message_memory);
}

void EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_fini_function(void * message_memory)
{
  boot_shutdown_api_msgs__msg__EcuStateSummary__fini(message_memory);
}

size_t EcuStateSummary__rosidl_typesupport_introspection_c__size_function__EcuState__details(
  const void * untyped_member)
{
  const boot_shutdown_api_msgs__msg__EcuState__Sequence * member =
    (const boot_shutdown_api_msgs__msg__EcuState__Sequence *)(untyped_member);
  return member->size;
}

const void * EcuStateSummary__rosidl_typesupport_introspection_c__get_const_function__EcuState__details(
  const void * untyped_member, size_t index)
{
  const boot_shutdown_api_msgs__msg__EcuState__Sequence * member =
    (const boot_shutdown_api_msgs__msg__EcuState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * EcuStateSummary__rosidl_typesupport_introspection_c__get_function__EcuState__details(
  void * untyped_member, size_t index)
{
  boot_shutdown_api_msgs__msg__EcuState__Sequence * member =
    (boot_shutdown_api_msgs__msg__EcuState__Sequence *)(untyped_member);
  return &member->data[index];
}

bool EcuStateSummary__rosidl_typesupport_introspection_c__resize_function__EcuState__details(
  void * untyped_member, size_t size)
{
  boot_shutdown_api_msgs__msg__EcuState__Sequence * member =
    (boot_shutdown_api_msgs__msg__EcuState__Sequence *)(untyped_member);
  boot_shutdown_api_msgs__msg__EcuState__Sequence__fini(member);
  return boot_shutdown_api_msgs__msg__EcuState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_member_array[2] = {
  {
    "summary",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuStateSummary, summary),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "details",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuStateSummary, details),  // bytes offset in struct
    NULL,  // default value
    EcuStateSummary__rosidl_typesupport_introspection_c__size_function__EcuState__details,  // size() function pointer
    EcuStateSummary__rosidl_typesupport_introspection_c__get_const_function__EcuState__details,  // get_const(index) function pointer
    EcuStateSummary__rosidl_typesupport_introspection_c__get_function__EcuState__details,  // get(index) function pointer
    EcuStateSummary__rosidl_typesupport_introspection_c__resize_function__EcuState__details  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_members = {
  "boot_shutdown_api_msgs__msg",  // message namespace
  "EcuStateSummary",  // message name
  2,  // number of fields
  sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary),
  EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_member_array,  // message members
  EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_init_function,  // function to initialize message memory (memory has to be allocated)
  EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_type_support_handle = {
  0,
  &EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, msg, EcuStateSummary)() {
  EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, msg, EcuState)();
  EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, msg, EcuState)();
  if (!EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_type_support_handle.typesupport_identifier) {
    EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &EcuStateSummary__rosidl_typesupport_introspection_c__EcuStateSummary_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
