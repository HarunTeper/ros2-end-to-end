// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice
#include "rt_msgs/msg/detail/rt_entry__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rt_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rt_msgs/msg/detail/rt_entry__struct.h"
#include "rt_msgs/msg/detail/rt_entry__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // history
#include "rosidl_runtime_c/string_functions.h"  // history

// forward declare type support functions


using _RTEntry__ros_msg_type = rt_msgs__msg__RTEntry;

static bool _RTEntry__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RTEntry__ros_msg_type * ros_message = static_cast<const _RTEntry__ros_msg_type *>(untyped_ros_message);
  // Field name: reactiontime
  {
    cdr << ros_message->reactiontime;
  }

  // Field name: dataage
  {
    cdr << ros_message->dataage;
  }

  // Field name: history
  {
    size_t size = ros_message->history.size;
    auto array_ptr = ros_message->history.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  return true;
}

static bool _RTEntry__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RTEntry__ros_msg_type * ros_message = static_cast<_RTEntry__ros_msg_type *>(untyped_ros_message);
  // Field name: reactiontime
  {
    cdr >> ros_message->reactiontime;
  }

  // Field name: dataage
  {
    cdr >> ros_message->dataage;
  }

  // Field name: history
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->history.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->history);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->history, size)) {
      return "failed to create array for field 'history'";
    }
    auto array_ptr = ros_message->history.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'history'\n");
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rt_msgs
size_t get_serialized_size_rt_msgs__msg__RTEntry(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RTEntry__ros_msg_type * ros_message = static_cast<const _RTEntry__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name reactiontime
  {
    size_t item_size = sizeof(ros_message->reactiontime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dataage
  {
    size_t item_size = sizeof(ros_message->dataage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name history
  {
    size_t array_size = ros_message->history.size;
    auto array_ptr = ros_message->history.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RTEntry__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rt_msgs__msg__RTEntry(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rt_msgs
size_t max_serialized_size_rt_msgs__msg__RTEntry(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: reactiontime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: dataage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: history
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _RTEntry__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rt_msgs__msg__RTEntry(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RTEntry = {
  "rt_msgs::msg",
  "RTEntry",
  _RTEntry__cdr_serialize,
  _RTEntry__cdr_deserialize,
  _RTEntry__get_serialized_size,
  _RTEntry__max_serialized_size
};

static rosidl_message_type_support_t _RTEntry__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RTEntry,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rt_msgs, msg, RTEntry)() {
  return &_RTEntry__type_support;
}

#if defined(__cplusplus)
}
#endif
