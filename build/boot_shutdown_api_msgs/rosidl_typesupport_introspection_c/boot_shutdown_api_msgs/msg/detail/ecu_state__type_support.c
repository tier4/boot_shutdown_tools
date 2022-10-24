// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__rosidl_typesupport_introspection_c.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__functions.h"
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.h"


// Include directives for member types
// Member `name`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `power_off_time`
#include "builtin_interfaces/msg/time.h"
// Member `power_off_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void EcuState__rosidl_typesupport_introspection_c__EcuState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  boot_shutdown_api_msgs__msg__EcuState__init(message_memory);
}

void EcuState__rosidl_typesupport_introspection_c__EcuState_fini_function(void * message_memory)
{
  boot_shutdown_api_msgs__msg__EcuState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember EcuState__rosidl_typesupport_introspection_c__EcuState_message_member_array[4] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuState, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuState, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "power_off_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__msg__EcuState, power_off_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers EcuState__rosidl_typesupport_introspection_c__EcuState_message_members = {
  "boot_shutdown_api_msgs__msg",  // message namespace
  "EcuState",  // message name
  4,  // number of fields
  sizeof(boot_shutdown_api_msgs__msg__EcuState),
  EcuState__rosidl_typesupport_introspection_c__EcuState_message_member_array,  // message members
  EcuState__rosidl_typesupport_introspection_c__EcuState_init_function,  // function to initialize message memory (memory has to be allocated)
  EcuState__rosidl_typesupport_introspection_c__EcuState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t EcuState__rosidl_typesupport_introspection_c__EcuState_message_type_support_handle = {
  0,
  &EcuState__rosidl_typesupport_introspection_c__EcuState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, msg, EcuState)() {
  EcuState__rosidl_typesupport_introspection_c__EcuState_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!EcuState__rosidl_typesupport_introspection_c__EcuState_message_type_support_handle.typesupport_identifier) {
    EcuState__rosidl_typesupport_introspection_c__EcuState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &EcuState__rosidl_typesupport_introspection_c__EcuState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
