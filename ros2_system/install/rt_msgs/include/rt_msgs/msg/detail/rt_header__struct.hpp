// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_HPP_
#define RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'entries'
#include "rt_msgs/msg/detail/rt_entry__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rt_msgs__msg__RTHeader __attribute__((deprecated))
#else
# define DEPRECATED__rt_msgs__msg__RTHeader __declspec(deprecated)
#endif

namespace rt_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RTHeader_
{
  using Type = RTHeader_<ContainerAllocator>;

  explicit RTHeader_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RTHeader_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _entries_type =
    std::vector<rt_msgs::msg::RTEntry_<ContainerAllocator>, typename ContainerAllocator::template rebind<rt_msgs::msg::RTEntry_<ContainerAllocator>>::other>;
  _entries_type entries;

  // setters for named parameter idiom
  Type & set__entries(
    const std::vector<rt_msgs::msg::RTEntry_<ContainerAllocator>, typename ContainerAllocator::template rebind<rt_msgs::msg::RTEntry_<ContainerAllocator>>::other> & _arg)
  {
    this->entries = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rt_msgs::msg::RTHeader_<ContainerAllocator> *;
  using ConstRawPtr =
    const rt_msgs::msg::RTHeader_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rt_msgs::msg::RTHeader_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rt_msgs::msg::RTHeader_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rt_msgs__msg__RTHeader
    std::shared_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rt_msgs__msg__RTHeader
    std::shared_ptr<rt_msgs::msg::RTHeader_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTHeader_ & other) const
  {
    if (this->entries != other.entries) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTHeader_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTHeader_

// alias to use template instance with default allocator
using RTHeader =
  rt_msgs::msg::RTHeader_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rt_msgs

#endif  // RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_HPP_
