// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "boot_shutdown_api_msgs/msg/rosidl_typesupport_c__visibility_control.h"
#include "boot_shutdown_api_msgs/srv/detail/shutdown__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Shutdown_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Shutdown_Request_type_support_ids_t;

static const _Shutdown_Request_type_support_ids_t _Shutdown_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Shutdown_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Shutdown_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Shutdown_Request_type_support_symbol_names_t _Shutdown_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, Shutdown_Request)),
  }
};

typedef struct _Shutdown_Request_type_support_data_t
{
  void * data[2];
} _Shutdown_Request_type_support_data_t;

static _Shutdown_Request_type_support_data_t _Shutdown_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Shutdown_Request_message_typesupport_map = {
  2,
  "boot_shutdown_api_msgs",
  &_Shutdown_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Shutdown_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Shutdown_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Shutdown_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Shutdown_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, boot_shutdown_api_msgs, srv, Shutdown_Request)() {
  return &::boot_shutdown_api_msgs::srv::rosidl_typesupport_c::Shutdown_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "boot_shutdown_api_msgs/srv/detail/shutdown__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Shutdown_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Shutdown_Response_type_support_ids_t;

static const _Shutdown_Response_type_support_ids_t _Shutdown_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Shutdown_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Shutdown_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Shutdown_Response_type_support_symbol_names_t _Shutdown_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, Shutdown_Response)),
  }
};

typedef struct _Shutdown_Response_type_support_data_t
{
  void * data[2];
} _Shutdown_Response_type_support_data_t;

static _Shutdown_Response_type_support_data_t _Shutdown_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Shutdown_Response_message_typesupport_map = {
  2,
  "boot_shutdown_api_msgs",
  &_Shutdown_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Shutdown_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Shutdown_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Shutdown_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Shutdown_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_boot_shutdown_api_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, boot_shutdown_api_msgs, srv, Shutdown_Response)() {
  return &::boot_shutdown_api_msgs::srv::rosidl_typesupport_c::Shutdown_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "boot_shutdown_api_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Shutdown_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Shutdown_type_support_ids_t;

static const _Shutdown_type_support_ids_t _Shutdown_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Shutdown_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Shutdown_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Shutdown_type_support_symbol_names_t _Shutdown_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, boot_shutdown_api_msgs, srv, Shutdown)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, boot_shutdown_api_msgs, srv, Shutdown)),
  }
};

typedef struct _Shutdown_type_support_data_t
{
  void * data[2];
} _Shutdown_type_support_data_t;

static _Shutdown_type_support_data_t _Shutdown_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Shutdown_service_typesupport_map = {
  2,
  "boot_shutdown_api_msgs",
  &_Shutdown_service_typesupport_ids.typesupport_identifier[0],
  &_Shutdown_service_typesupport_symbol_names.symbol_name[0],
  &_Shutdown_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Shutdown_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Shutdown_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_boot_shutdown_api_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, boot_shutdown_api_msgs, srv, Shutdown)() {
  return &::boot_shutdown_api_msgs::srv::rosidl_typesupport_c::Shutdown_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
