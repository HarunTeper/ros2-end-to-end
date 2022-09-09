// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_H_
#define RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'entries'
#include "rt_msgs/msg/detail/rt_entry__struct.h"

// Struct defined in msg/RTHeader in the package rt_msgs.
typedef struct rt_msgs__msg__RTHeader
{
  rt_msgs__msg__RTEntry__Sequence entries;
} rt_msgs__msg__RTHeader;

// Struct for a sequence of rt_msgs__msg__RTHeader.
typedef struct rt_msgs__msg__RTHeader__Sequence
{
  rt_msgs__msg__RTHeader * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rt_msgs__msg__RTHeader__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RT_MSGS__MSG__DETAIL__RT_HEADER__STRUCT_H_
