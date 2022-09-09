// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rt_msgs:msg/RTHeader.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rt_msgs/msg/detail/rt_header__rosidl_typesupport_introspection_c.h"
#include "rt_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rt_msgs/msg/detail/rt_header__functions.h"
#include "rt_msgs/msg/detail/rt_header__struct.h"


// Include directives for member types
// Member `entries`
#include "rt_msgs/msg/rt_entry.h"
// Member `entries`
#include "rt_msgs/msg/detail/rt_entry__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RTHeader__rosidl_typesupport_introspection_c__RTHeader_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rt_msgs__msg__RTHeader__init(message_memory);
}

void RTHeader__rosidl_typesupport_introspection_c__RTHeader_fini_function(void * message_memory)
{
  rt_msgs__msg__RTHeader__fini(message_memory);
}

size_t RTHeader__rosidl_typesupport_introspection_c__size_function__RTEntry__entries(
  const void * untyped_member)
{
  const rt_msgs__msg__RTEntry__Sequence * member =
    (const rt_msgs__msg__RTEntry__Sequence *)(untyped_member);
  return member->size;
}

const void * RTHeader__rosidl_typesupport_introspection_c__get_const_function__RTEntry__entries(
  const void * untyped_member, size_t index)
{
  const rt_msgs__msg__RTEntry__Sequence * member =
    (const rt_msgs__msg__RTEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

void * RTHeader__rosidl_typesupport_introspection_c__get_function__RTEntry__entries(
  void * untyped_member, size_t index)
{
  rt_msgs__msg__RTEntry__Sequence * member =
    (rt_msgs__msg__RTEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

bool RTHeader__rosidl_typesupport_introspection_c__resize_function__RTEntry__entries(
  void * untyped_member, size_t size)
{
  rt_msgs__msg__RTEntry__Sequence * member =
    (rt_msgs__msg__RTEntry__Sequence *)(untyped_member);
  rt_msgs__msg__RTEntry__Sequence__fini(member);
  return rt_msgs__msg__RTEntry__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_member_array[1] = {
  {
    "entries",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rt_msgs__msg__RTHeader, entries),  // bytes offset in struct
    NULL,  // default value
    RTHeader__rosidl_typesupport_introspection_c__size_function__RTEntry__entries,  // size() function pointer
    RTHeader__rosidl_typesupport_introspection_c__get_const_function__RTEntry__entries,  // get_const(index) function pointer
    RTHeader__rosidl_typesupport_introspection_c__get_function__RTEntry__entries,  // get(index) function pointer
    RTHeader__rosidl_typesupport_introspection_c__resize_function__RTEntry__entries  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_members = {
  "rt_msgs__msg",  // message namespace
  "RTHeader",  // message name
  1,  // number of fields
  sizeof(rt_msgs__msg__RTHeader),
  RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_member_array,  // message members
  RTHeader__rosidl_typesupport_introspection_c__RTHeader_init_function,  // function to initialize message memory (memory has to be allocated)
  RTHeader__rosidl_typesupport_introspection_c__RTHeader_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_type_support_handle = {
  0,
  &RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rt_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rt_msgs, msg, RTHeader)() {
  RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rt_msgs, msg, RTEntry)();
  if (!RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_type_support_handle.typesupport_identifier) {
    RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RTHeader__rosidl_typesupport_introspection_c__RTHeader_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
