// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'summary'
// Member 'details'
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__boot_shutdown_api_msgs__msg__EcuStateSummary __attribute__((deprecated))
#else
# define DEPRECATED__boot_shutdown_api_msgs__msg__EcuStateSummary __declspec(deprecated)
#endif

namespace boot_shutdown_api_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EcuStateSummary_
{
  using Type = EcuStateSummary_<ContainerAllocator>;

  explicit EcuStateSummary_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : summary(_init)
  {
    (void)_init;
  }

  explicit EcuStateSummary_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : summary(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _summary_type =
    boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>;
  _summary_type summary;
  using _details_type =
    std::vector<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>>;
  _details_type details;

  // setters for named parameter idiom
  Type & set__summary(
    const boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> & _arg)
  {
    this->summary = _arg;
    return *this;
  }
  Type & set__details(
    const std::vector<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>> & _arg)
  {
    this->details = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> *;
  using ConstRawPtr =
    const boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__boot_shutdown_api_msgs__msg__EcuStateSummary
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__boot_shutdown_api_msgs__msg__EcuStateSummary
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuStateSummary_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EcuStateSummary_ & other) const
  {
    if (this->summary != other.summary) {
      return false;
    }
    if (this->details != other.details) {
      return false;
    }
    return true;
  }
  bool operator!=(const EcuStateSummary_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EcuStateSummary_

// alias to use template instance with default allocator
using EcuStateSummary =
  boot_shutdown_api_msgs::msg::EcuStateSummary_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__STRUCT_HPP_
