// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_HEADER__TRAITS_HPP_
#define RT_MSGS__MSG__DETAIL__RT_HEADER__TRAITS_HPP_

#include "rt_msgs/msg/detail/rt_header__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rt_msgs::msg::RTHeader>()
{
  return "rt_msgs::msg::RTHeader";
}

template<>
inline const char * name<rt_msgs::msg::RTHeader>()
{
  return "rt_msgs/msg/RTHeader";
}

template<>
struct has_fixed_size<rt_msgs::msg::RTHeader>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rt_msgs::msg::RTHeader>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rt_msgs::msg::RTHeader>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RT_MSGS__MSG__DETAIL__RT_HEADER__TRAITS_HPP_
