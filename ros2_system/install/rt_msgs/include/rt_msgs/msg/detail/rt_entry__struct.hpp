// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_HPP_
#define RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rt_msgs__msg__RTEntry __attribute__((deprecated))
#else
# define DEPRECATED__rt_msgs__msg__RTEntry __declspec(deprecated)
#endif

namespace rt_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RTEntry_
{
  using Type = RTEntry_<ContainerAllocator>;

  explicit RTEntry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reactiontime = 0ull;
      this->dataage = 0ull;
    }
  }

  explicit RTEntry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reactiontime = 0ull;
      this->dataage = 0ull;
    }
  }

  // field types and members
  using _reactiontime_type =
    uint64_t;
  _reactiontime_type reactiontime;
  using _dataage_type =
    uint64_t;
  _dataage_type dataage;
  using _history_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _history_type history;

  // setters for named parameter idiom
  Type & set__reactiontime(
    const uint64_t & _arg)
  {
    this->reactiontime = _arg;
    return *this;
  }
  Type & set__dataage(
    const uint64_t & _arg)
  {
    this->dataage = _arg;
    return *this;
  }
  Type & set__history(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->history = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rt_msgs::msg::RTEntry_<ContainerAllocator> *;
  using ConstRawPtr =
    const rt_msgs::msg::RTEntry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rt_msgs::msg::RTEntry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rt_msgs::msg::RTEntry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rt_msgs__msg__RTEntry
    std::shared_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rt_msgs__msg__RTEntry
    std::shared_ptr<rt_msgs::msg::RTEntry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTEntry_ & other) const
  {
    if (this->reactiontime != other.reactiontime) {
      return false;
    }
    if (this->dataage != other.dataage) {
      return false;
    }
    if (this->history != other.history) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTEntry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTEntry_

// alias to use template instance with default allocator
using RTEntry =
  rt_msgs::msg::RTEntry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rt_msgs

#endif  // RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_HPP_
