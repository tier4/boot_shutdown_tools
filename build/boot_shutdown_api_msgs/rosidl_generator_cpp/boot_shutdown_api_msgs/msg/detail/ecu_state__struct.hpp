// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_HPP_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'power_off_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__boot_shutdown_api_msgs__msg__EcuState __attribute__((deprecated))
#else
# define DEPRECATED__boot_shutdown_api_msgs__msg__EcuState __declspec(deprecated)
#endif

namespace boot_shutdown_api_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EcuState_
{
  using Type = EcuState_<ContainerAllocator>;

  explicit EcuState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : power_off_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->name = "";
      this->message = "";
    }
  }

  explicit EcuState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    message(_alloc),
    power_off_time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->name = "";
      this->message = "";
    }
  }

  // field types and members
  using _state_type =
    uint16_t;
  _state_type state;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _power_off_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _power_off_time_type power_off_time;

  // setters for named parameter idiom
  Type & set__state(
    const uint16_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__power_off_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->power_off_time = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t UNKNOWN =
    0u;
  static constexpr uint16_t STARTUP =
    1u;
  static constexpr uint16_t RUNNING =
    2u;
  static constexpr uint16_t SHUTDOWN_PREPARING =
    3u;
  static constexpr uint16_t SHUTDOWN_READY =
    4u;
  static constexpr uint16_t STARTUP_TIMEOUT =
    1001u;
  static constexpr uint16_t SHUTDOWN_TIMEOUT =
    1002u;

  // pointer types
  using RawPtr =
    boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> *;
  using ConstRawPtr =
    const boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__boot_shutdown_api_msgs__msg__EcuState
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__boot_shutdown_api_msgs__msg__EcuState
    std::shared_ptr<boot_shutdown_api_msgs::msg::EcuState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EcuState_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->power_off_time != other.power_off_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const EcuState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EcuState_

// alias to use template instance with default allocator
using EcuState =
  boot_shutdown_api_msgs::msg::EcuState_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::UNKNOWN;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::STARTUP;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::RUNNING;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::SHUTDOWN_PREPARING;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::SHUTDOWN_READY;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::STARTUP_TIMEOUT;
template<typename ContainerAllocator>
constexpr uint16_t EcuState_<ContainerAllocator>::SHUTDOWN_TIMEOUT;

}  // namespace msg

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE__STRUCT_HPP_
