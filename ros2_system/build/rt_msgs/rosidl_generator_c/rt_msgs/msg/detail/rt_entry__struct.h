// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_H_
#define RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'history'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/RTEntry in the package rt_msgs.
typedef struct rt_msgs__msg__RTEntry
{
  uint64_t reactiontime;
  uint64_t dataage;
  rosidl_runtime_c__String__Sequence history;
} rt_msgs__msg__RTEntry;

// Struct for a sequence of rt_msgs__msg__RTEntry.
typedef struct rt_msgs__msg__RTEntry__Sequence
{
  rt_msgs__msg__RTEntry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rt_msgs__msg__RTEntry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RT_MSGS__MSG__DETAIL__RT_ENTRY__STRUCT_H_
