// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice
#include "rt_msgs/msg/detail/rt_entry__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rt_msgs/msg/detail/rt_entry__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rt_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
cdr_serialize(
  const rt_msgs::msg::RTEntry & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: reactiontime
  cdr << ros_message.reactiontime;
  // Member: dataage
  cdr << ros_message.dataage;
  // Member: history
  {
    cdr << ros_message.history;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rt_msgs::msg::RTEntry & ros_message)
{
  // Member: reactiontime
  cdr >> ros_message.reactiontime;

  // Member: dataage
  cdr >> ros_message.dataage;

  // Member: history
  {
    cdr >> ros_message.history;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
get_serialized_size(
  const rt_msgs::msg::RTEntry & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: reactiontime
  {
    size_t item_size = sizeof(ros_message.reactiontime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dataage
  {
    size_t item_size = sizeof(ros_message.dataage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: history
  {
    size_t array_size = ros_message.history.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.history[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
max_serialized_size_RTEntry(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: reactiontime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: dataage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: history
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

static bool _RTEntry__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rt_msgs::msg::RTEntry *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RTEntry__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rt_msgs::msg::RTEntry *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RTEntry__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rt_msgs::msg::RTEntry *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RTEntry__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RTEntry(full_bounded, 0);
}

static message_type_support_callbacks_t _RTEntry__callbacks = {
  "rt_msgs::msg",
  "RTEntry",
  _RTEntry__cdr_serialize,
  _RTEntry__cdr_deserialize,
  _RTEntry__get_serialized_size,
  _RTEntry__max_serialized_size
};

static rosidl_message_type_support_t _RTEntry__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RTEntry__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rt_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rt_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<rt_msgs::msg::RTEntry>()
{
  return &rt_msgs::msg::typesupport_fastrtps_cpp::_RTEntry__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rt_msgs, msg, RTEntry)() {
  return &rt_msgs::msg::typesupport_fastrtps_cpp::_RTEntry__handle;
}

#ifdef __cplusplus
}
#endif
