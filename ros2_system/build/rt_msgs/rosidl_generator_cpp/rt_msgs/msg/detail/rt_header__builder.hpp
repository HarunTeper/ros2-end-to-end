// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_HEADER__BUILDER_HPP_
#define RT_MSGS__MSG__DETAIL__RT_HEADER__BUILDER_HPP_

#include "rt_msgs/msg/detail/rt_header__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rt_msgs
{

namespace msg
{

namespace builder
{

class Init_RTHeader_entries
{
public:
  Init_RTHeader_entries()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rt_msgs::msg::RTHeader entries(::rt_msgs::msg::RTHeader::_entries_type arg)
  {
    msg_.entries = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rt_msgs::msg::RTHeader msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rt_msgs::msg::RTHeader>()
{
  return rt_msgs::msg::builder::Init_RTHeader_entries();
}

}  // namespace rt_msgs

#endif  // RT_MSGS__MSG__DETAIL__RT_HEADER__BUILDER_HPP_
