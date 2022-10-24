// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from boot_shutdown_api_msgs:srv/ExecuteShutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__BUILDER_HPP_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__BUILDER_HPP_

#include "boot_shutdown_api_msgs/srv/detail/execute_shutdown__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace boot_shutdown_api_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::boot_shutdown_api_msgs::srv::ExecuteShutdown_Request>()
{
  return ::boot_shutdown_api_msgs::srv::ExecuteShutdown_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace boot_shutdown_api_msgs


namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecuteShutdown_Response_power_off_time
{
public:
  explicit Init_ExecuteShutdown_Response_power_off_time(::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response & msg)
  : msg_(msg)
  {}
  ::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response power_off_time(::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response::_power_off_time_type arg)
  {
    msg_.power_off_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response msg_;
};

class Init_ExecuteShutdown_Response_status
{
public:
  Init_ExecuteShutdown_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteShutdown_Response_power_off_time status(::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteShutdown_Response_power_off_time(msg_);
  }

private:
  ::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::boot_shutdown_api_msgs::srv::ExecuteShutdown_Response>()
{
  return boot_shutdown_api_msgs::srv::builder::Init_ExecuteShutdown_Response_status();
}

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__EXECUTE_SHUTDOWN__BUILDER_HPP_
