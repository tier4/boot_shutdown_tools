// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from boot_shutdown_api_msgs:srv/PrepareShutdown.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__rosidl_typesupport_introspection_c.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__functions.h"
#include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  boot_shutdown_api_msgs__srv__PrepareShutdown_Request__init(message_memory);
}

void PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_fini_function(void * message_memory)
{
  boot_shutdown_api_msgs__srv__PrepareShutdown_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__srv__PrepareShutdown_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_members = {
  "boot_shutdown_api_msgs__srv",  // message namespace
  "PrepareShutdown_Request",  // message name
  1,  // number of fields
  sizeof(boot_shutdown_api_msgs__srv__PrepareShutdown_Request),
  PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_member_array,  // message members
  PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_type_support_handle = {
  0,
  &PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Request)() {
  if (!PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_type_support_handle.typesupport_identifier) {
    PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PrepareShutdown_Request__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__rosidl_typesupport_introspection_c.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__functions.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__struct.h"


// Include directives for member types
// Member `status`
#include "autoware_adapi_v1_msgs/msg/response_status.h"
// Member `status`
#include "autoware_adapi_v1_msgs/msg/detail/response_status__rosidl_typesupport_introspection_c.h"
// Member `power_off_time`
#include "builtin_interfaces/msg/time.h"
// Member `power_off_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  boot_shutdown_api_msgs__srv__PrepareShutdown_Response__init(message_memory);
}

void PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_fini_function(void * message_memory)
{
  boot_shutdown_api_msgs__srv__PrepareShutdown_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(boot_shutdown_api_msgs__srv__PrepareShutdown_Response, status),  // bytes offset in struct
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
    offsetof(boot_shutdown_api_msgs__srv__PrepareShutdown_Response, power_off_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_members = {
  "boot_shutdown_api_msgs__srv",  // message namespace
  "PrepareShutdown_Response",  // message name
  2,  // number of fields
  sizeof(boot_shutdown_api_msgs__srv__PrepareShutdown_Response),
  PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_member_array,  // message members
  PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_type_support_handle = {
  0,
  &PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Response)() {
  PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autoware_adapi_v1_msgs, msg, ResponseStatus)();
  PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_type_support_handle.typesupport_identifier) {
    PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PrepareShutdown_Response__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/prepare_shutdown__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_members = {
  "boot_shutdown_api_msgs__srv",  // service namespace
  "PrepareShutdown",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_Request_message_type_support_handle,
  NULL  // response message
  // boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_Response_message_type_support_handle
};

static rosidl_service_type_support_t boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_type_support_handle = {
  0,
  &boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_boot_shutdown_api_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown)() {
  if (!boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_type_support_handle.typesupport_identifier) {
    boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, PrepareShutdown_Response)()->data;
  }

  return &boot_shutdown_api_msgs__srv__detail__prepare_shutdown__rosidl_typesupport_introspection_c__PrepareShutdown_service_type_support_handle;
}
