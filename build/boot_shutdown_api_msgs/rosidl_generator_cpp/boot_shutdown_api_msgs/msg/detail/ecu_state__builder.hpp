// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__BUILDER_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__BUILDER_HPP_

#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace boot_shutdown_api_msgs
{

namespace msg
{

namespace builder
{

class Init_EcuState_power_off_time
{
public:
  explicit Init_EcuState_power_off_time(::boot_shutdown_api_msgs::msg::EcuState & msg)
  : msg_(msg)
  {}
  ::boot_shutdown_api_msgs::msg::EcuState power_off_time(::boot_shutdown_api_msgs::msg::EcuState::_power_off_time_type arg)
  {
    msg_.power_off_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuState msg_;
};

class Init_EcuState_message
{
public:
  explicit Init_EcuState_message(::boot_shutdown_api_msgs::msg::EcuState & msg)
  : msg_(msg)
  {}
  Init_EcuState_power_off_time message(::boot_shutdown_api_msgs::msg::EcuState::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_EcuState_power_off_time(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuState msg_;
};

class Init_EcuState_name
{
public:
  explicit Init_EcuState_name(::boot_shutdown_api_msgs::msg::EcuState & msg)
  : msg_(msg)
  {}
  Init_EcuState_message name(::boot_shutdown_api_msgs::msg::EcuState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_EcuState_message(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuState msg_;
};

class Init_EcuState_state
{
public:
  Init_EcuState_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EcuState_name state(::boot_shutdown_api_msgs::msg::EcuState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_EcuState_name(msg_);
  }

private:
  ::boot_shutdown_api_msgs::msg::EcuState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::boot_shutdown_api_msgs::msg::EcuState>()
{
  return boot_shutdown_api_msgs::msg::builder::Init_EcuState_state();
}

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__BUILDER_HPP_
