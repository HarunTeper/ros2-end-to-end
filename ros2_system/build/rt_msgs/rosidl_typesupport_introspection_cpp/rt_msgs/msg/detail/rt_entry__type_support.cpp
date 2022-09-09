// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rt_msgs/msg/detail/rt_entry__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rt_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RTEntry_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rt_msgs::msg::RTEntry(_init);
}

void RTEntry_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rt_msgs::msg::RTEntry *>(message_memory);
  typed_message->~RTEntry();
}

size_t size_function__RTEntry__history(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RTEntry__history(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__RTEntry__history(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__RTEntry__history(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RTEntry_message_member_array[3] = {
  {
    "reactiontime",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rt_msgs::msg::RTEntry, reactiontime),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "dataage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rt_msgs::msg::RTEntry, dataage),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "history",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rt_msgs::msg::RTEntry, history),  // bytes offset in struct
    nullptr,  // default value
    size_function__RTEntry__history,  // size() function pointer
    get_const_function__RTEntry__history,  // get_const(index) function pointer
    get_function__RTEntry__history,  // get(index) function pointer
    resize_function__RTEntry__history  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RTEntry_message_members = {
  "rt_msgs::msg",  // message namespace
  "RTEntry",  // message name
  3,  // number of fields
  sizeof(rt_msgs::msg::RTEntry),
  RTEntry_message_member_array,  // message members
  RTEntry_init_function,  // function to initialize message memory (memory has to be allocated)
  RTEntry_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RTEntry_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RTEntry_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rt_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rt_msgs::msg::RTEntry>()
{
  return &::rt_msgs::msg::rosidl_typesupport_introspection_cpp::RTEntry_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rt_msgs, msg, RTEntry)() {
  return &::rt_msgs::msg::rosidl_typesupport_introspection_cpp::RTEntry_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
