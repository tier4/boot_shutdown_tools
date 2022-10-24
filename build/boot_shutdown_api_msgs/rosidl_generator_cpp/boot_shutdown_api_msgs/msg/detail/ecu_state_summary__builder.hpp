// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__BUILDER_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__BUILDER_HPP_

#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace boot_shutdown_api_msgs
{

namespace msg
{

namespace builder
{

class Init_EcuStateSummary_details
{
public:
  explicit Init_EcuStateSummary_details(::boot_shutdown_api_msgs::msg::EcuStateSummary & msg)
  : msg_(msg)
  {}
  ::boot_shutdown_api_msgs::msg::EcuStateSummary details(::boot_shutdown_api_msgs::msg::EcuStateSummary::_details_type arg)
  {
    msg_.details = std::move(arg);
    return std::move(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuStateSummary msg_;
};

class Init_EcuStateSummary_summary
{
public:
  Init_EcuStateSummary_summary()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EcuStateSummary_details summary(::boot_shutdown_api_msgs::msg::EcuStateSummary::_summary_type arg)
  {
    msg_.summary = std::move(arg);
    return Init_EcuStateSummary_details(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuStateSummary msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::boot_shutdown_api_msgs::msg::EcuStateSummary>()
{
  return boot_shutdown_api_msgs::msg::builder::Init_EcuStateSummary_summary();
}

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__BUILDER_HPP_
