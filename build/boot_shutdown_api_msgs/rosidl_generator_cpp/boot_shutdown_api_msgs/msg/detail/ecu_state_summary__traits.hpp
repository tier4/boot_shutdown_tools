// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__TRAITS_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__TRAITS_HPP_

#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'summary'
// Member 'details'
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const boot_shutdown_api_msgs::msg::EcuStateSummary & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: summary
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "summary:\n";
    to_yaml(msg.summary, out, indentation + 2);
  }

  // member: details
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.details.size() == 0) {
      out << "details: []\n";
    } else {
      out << "details:\n";
      for (auto item : msg.details) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const boot_shutdown_api_msgs::msg::EcuStateSummary & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<boot_shutdown_api_msgs::msg::EcuStateSummary>()
{
  return "boot_shutdown_api_msgs::msg::EcuStateSummary";
}

template<>
inline const char * name<boot_shutdown_api_msgs::msg::EcuStateSummary>()
{
  return "boot_shutdown_api_msgs/msg/EcuStateSummary";
}

template<>
struct has_fixed_size<boot_shutdown_api_msgs::msg::EcuStateSummary>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<boot_shutdown_api_msgs::msg::EcuStateSummary>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<boot_shutdown_api_msgs::msg::EcuStateSummary>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__TRAITS_HPP_
