// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_HPP_
#define BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Request __attribute__((deprecated))
#else
# define DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Request __declspec(deprecated)
#endif

namespace boot_shutdown_api_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Shutdown_Request_
{
  using Type = Shutdown_Request_<ContainerAllocator>;

  explicit Shutdown_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Shutdown_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Request
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Request
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Shutdown_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Shutdown_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Shutdown_Request_

// alias to use template instance with default allocator
using Shutdown_Request =
  boot_shutdown_api_msgs::srv::Shutdown_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace boot_shutdown_api_msgs


// Include directives for member types
// Member 'status'
#include "autoware_adapi_v1_msgs/msg/detail/response_status__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Response __attribute__((deprecated))
#else
# define DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Response __declspec(deprecated)
#endif

namespace boot_shutdown_api_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Shutdown_Response_
{
  using Type = Shutdown_Response_<ContainerAllocator>;

  explicit Shutdown_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_init)
  {
    (void)_init;
  }

  explicit Shutdown_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _status_type =
    autoware_adapi_v1_msgs::msg::ResponseStatus_<ContainerAllocator>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const autoware_adapi_v1_msgs::msg::ResponseStatus_<ContainerAllocator> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Response
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__boot_shutdown_api_msgs__srv__Shutdown_Response
    std::shared_ptr<boot_shutdown_api_msgs::srv::Shutdown_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Shutdown_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Shutdown_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Shutdown_Response_

// alias to use template instance with default allocator
using Shutdown_Response =
  boot_shutdown_api_msgs::srv::Shutdown_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

namespace boot_shutdown_api_msgs
{

namespace srv
{

struct Shutdown
{
  using Request = boot_shutdown_api_msgs::srv::Shutdown_Request;
  using Response = boot_shutdown_api_msgs::srv::Shutdown_Response;
};

}  // namespace srv

}  // namespace boot_shutdown_api_msgs

#endif  // BOOT_SHUTDOWN_API_MSGS__SRV__DETAIL__SHUTDOWN__STRUCT_HPP_
