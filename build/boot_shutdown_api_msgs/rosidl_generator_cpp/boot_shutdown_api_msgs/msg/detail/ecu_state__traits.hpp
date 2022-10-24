// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__TRAITS_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__TRAITS_HPP_

#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'power_off_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const boot_shutdown_api_msgs::msg::EcuState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    value_to_yaml(msg.message, out);
    out << "\n";
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

inline std::string to_yaml(const boot_shutdown_api_msgs::msg::EcuState & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<boot_shutdown_api_msgs::msg::EcuState>()
{
  return "boot_shutdown_api_msgs::msg::EcuState";
}

template<>
inline const char * name<boot_shutdown_api_msgs::msg::EcuState>()
{
  return "boot_shutdown_api_msgs/msg/EcuState";
}

template<>
struct has_fixed_size<boot_shutdown_api_msgs::msg::EcuState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<boot_shutdown_api_msgs::msg::EcuState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<boot_shutdown_api_msgs::msg::EcuState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__TRAITS_HPP_
