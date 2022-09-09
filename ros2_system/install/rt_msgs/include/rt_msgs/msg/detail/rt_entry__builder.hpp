// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_ENTRY__BUILDER_HPP_
#define RT_MSGS__MSG__DETAIL__RT_ENTRY__BUILDER_HPP_

#include "rt_msgs/msg/detail/rt_entry__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rt_msgs
{

namespace msg
{

namespace builder
{

class Init_RTEntry_history
{
public:
  explicit Init_RTEntry_history(::rt_msgs::msg::RTEntry & msg)
  : msg_(msg)
  {}
  ::rt_msgs::msg::RTEntry history(::rt_msgs::msg::RTEntry::_history_type arg)
  {
    msg_.history = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rt_msgs::msg::RTEntry msg_;
};

class Init_RTEntry_dataage
{
public:
  explicit Init_RTEntry_dataage(::rt_msgs::msg::RTEntry & msg)
  : msg_(msg)
  {}
  Init_RTEntry_history dataage(::rt_msgs::msg::RTEntry::_dataage_type arg)
  {
    msg_.dataage = std::move(arg);
    return Init_RTEntry_history(msg_);
  }

private:
  ::rt_msgs::msg::RTEntry msg_;
};

class Init_RTEntry_reactiontime
{
public:
  Init_RTEntry_reactiontime()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RTEntry_dataage reactiontime(::rt_msgs::msg::RTEntry::_reactiontime_type arg)
  {
    msg_.reactiontime = std::move(arg);
    return Init_RTEntry_dataage(msg_);
  }

private:
  ::rt_msgs::msg::RTEntry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rt_msgs::msg::RTEntry>()
{
  return rt_msgs::msg::builder::Init_RTEntry_reactiontime();
}

}  // namespace rt_msgs

#endif  // RT_MSGS__MSG__DETAIL__RT_ENTRY__BUILDER_HPP_
