// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice
#include "rt_msgs/msg/detail/rt_header__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rt_msgs/msg/detail/rt_header__struct.hpp"

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
bool cdr_serialize(
  const rt_msgs::msg::RTEntry &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  rt_msgs::msg::RTEntry &);
size_t get_serialized_size(
  const rt_msgs::msg::RTEntry &,
  size_t current_alignment);
size_t
max_serialized_size_RTEntry(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace rt_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: entries
  {
    size_t size = ros_message.entries.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rt_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.entries[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rt_msgs::msg::RTHeader & ros_message)
{
  // Member: entries
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.entries.resize(size);
    for (size_t i = 0; i < size; i++) {
      rt_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.entries[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
get_serialized_size(
  const rt_msgs::msg::RTHeader & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: entries
  {
    size_t array_size = ros_message.entries.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rt_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.entries[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rt_msgs
max_serialized_size_RTHeader(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: entries
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rt_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_RTEntry(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _RTHeader__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rt_msgs::msg::RTHeader *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RTHeader__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rt_msgs::msg::RTHeader *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RTHeader__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rt_msgs::msg::RTHeader *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RTHeader__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RTHeader(full_bounded, 0);
}

static message_type_support_callbacks_t _RTHeader__callbacks = {
  "rt_msgs::msg",
  "RTHeader",
  _RTHeader__cdr_serialize,
  _RTHeader__cdr_deserialize,
  _RTHeader__get_serialized_size,
  _RTHeader__max_serialized_size
};

static rosidl_message_type_support_t _RTHeader__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RTHeader__callbacks,
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
get_message_type_support_handle<rt_msgs::msg::RTHeader>()
{
  return &rt_msgs::msg::typesupport_fastrtps_cpp::_RTHeader__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rt_msgs, msg, RTHeader)() {
  return &rt_msgs::msg::typesupport_fastrtps_cpp::_RTHeader__handle;
}

#ifdef __cplusplus
}
#endif
