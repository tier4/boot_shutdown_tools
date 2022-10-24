// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from boot_shutdown_api_msgs:srv/ExecuteShutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__TRAITS_HPP_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__TRAITS_HPP_

#include "boot_shutdown_api_msgs/srv/detail/execute_shutdown__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const boot_shutdown_api_msgs::srv::ExecuteShutdown_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const boot_shutdown_api_msgs::srv::ExecuteShutdown_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>()
{
  return "boot_shutdown_api_msgs::srv::ExecuteShutdown_Request";
}

template<>
inline const char * name<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>()
{
  return "boot_shutdown_api_msgs/srv/ExecuteShutdown_Request";
}

template<>
struct has_fixed_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'status'
#include "autoware_adapi_v1_msgs/msg/detail/response_status__traits.hpp"
// Member 'power_off_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const boot_shutdown_api_msgs::srv::ExecuteShutdown_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status:\n";
    to_yaml(msg.status, out, indentation + 2);
  }

  // member: power_off_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_off_time:\n";
    to_yaml(msg.power_off_time, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const boot_shutdown_api_msgs::srv::ExecuteShutdown_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>()
{
  return "boot_shutdown_api_msgs::srv::ExecuteShutdown_Response";
}

template<>
inline const char * name<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>()
{
  return "boot_shutdown_api_msgs/srv/ExecuteShutdown_Response";
}

template<>
struct has_fixed_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>
  : std::integral_constant<bool, has_fixed_size<autoware_adapi_v1_msgs::msg::ResponseStatus>::value && has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>
  : std::integral_constant<bool, has_bounded_size<autoware_adapi_v1_msgs::msg::ResponseStatus>::value && has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<boot_shutdown_api_msgs::srv::ExecuteShutdown>()
{
  return "boot_shutdown_api_msgs::srv::ExecuteShutdown";
}

template<>
inline const char * name<boot_shutdown_api_msgs::srv::ExecuteShutdown>()
{
  return "boot_shutdown_api_msgs/srv/ExecuteShutdown";
}

template<>
struct has_fixed_size<boot_shutdown_api_msgs::srv::ExecuteShutdown>
  : std::integral_constant<
    bool,
    has_fixed_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>::value &&
    has_fixed_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>::value
  >
{
};

template<>
struct has_bounded_size<boot_shutdown_api_msgs::srv::ExecuteShutdown>
  : std::integral_constant<
    bool,
    has_bounded_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>::value &&
    has_bounded_size<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>::value
  >
{
};

template<>
struct is_service<boot_shutdown_api_msgs::srv::ExecuteShutdown>
  : std::true_type
{
};

template<>
struct is_service_request<boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>
  : std::true_type
{
};

template<>
struct is_service_response<boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__TRAITS_HPP_
