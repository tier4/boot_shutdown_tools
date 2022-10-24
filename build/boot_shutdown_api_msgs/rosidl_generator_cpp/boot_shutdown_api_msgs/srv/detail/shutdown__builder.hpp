// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__BUILDER_HPP_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__BUILDER_HPP_

#include "boot_shutdown_api_msgs/srv/detail/shutdown__struct.hpp"
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
auto build<::boot_shutdown_api_msgs::srv::Shutdown_Request>()
{
  return ::boot_shutdown_api_msgs::srv::Shutdown_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace boot_shutdown_api_msgs


namespace boot_shutdown_api_msgs
{

namespace srv
{

namespace builder
{

class Init_Shutdown_Response_status
{
public:
  Init_Shutdown_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::boot_shutdown_api_msgs::srv::Shutdown_Response status(::boot_shutdown_api_msgs::srv::Shutdown_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::boot_shutdown_api_msgs::srv::Shutdown_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::boot_shutdown_api_msgs::srv::Shutdown_Response>()
{
  return boot_shutdown_api_msgs::srv::builder::Init_Shutdown_Response_status();
}

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__BUILDER_HPP_
