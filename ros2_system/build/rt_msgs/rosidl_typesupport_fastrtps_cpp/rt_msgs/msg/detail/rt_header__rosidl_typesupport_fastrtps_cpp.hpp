// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_HEADER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RT_MSGS__MSG__DETAIL__RT_HEADER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rt_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rt_msgs/msg/detail/rt_header__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rt_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
cdr_serialize(
  const rt_msgs::msg::RTHeader & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rt_msgs::msg::RTHeader & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
get_serialized_size(
  const rt_msgs::msg::RTHeader & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
max_serialized_size_RTHeader(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rt_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rt_msgs, msg, RTHeader)();

#ifdef __cplusplus
}
#endif

#endif  // RT_MSGS__MSG__DETAIL__RT_HEADER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
