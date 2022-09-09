// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice
#include "rt_msgs/msg/detail/rt_entry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `history`
#include "rosidl_runtime_c/string_functions.h"

bool
rt_msgs__msg__RTEntry__init(rt_msgs__msg__RTEntry * msg)
{
  if (!msg) {
    return false;
  }
  // reactiontime
  // dataage
  // history
  if (!rosidl_runtime_c__String__Sequence__init(&msg->history, 0)) {
    rt_msgs__msg__RTEntry__fini(msg);
    return false;
  }
  return true;
}

void
rt_msgs__msg__RTEntry__fini(rt_msgs__msg__RTEntry * msg)
{
  if (!msg) {
    return;
  }
  // reactiontime
  // dataage
  // history
  rosidl_runtime_c__String__Sequence__fini(&msg->history);
}

rt_msgs__msg__RTEntry *
rt_msgs__msg__RTEntry__create()
{
  rt_msgs__msg__RTEntry * msg = (rt_msgs__msg__RTEntry *)malloc(sizeof(rt_msgs__msg__RTEntry));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rt_msgs__msg__RTEntry));
  bool success = rt_msgs__msg__RTEntry__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rt_msgs__msg__RTEntry__destroy(rt_msgs__msg__RTEntry * msg)
{
  if (msg) {
    rt_msgs__msg__RTEntry__fini(msg);
  }
  free(msg);
}


bool
rt_msgs__msg__RTEntry__Sequence__init(rt_msgs__msg__RTEntry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rt_msgs__msg__RTEntry * data = NULL;
  if (size) {
    data = (rt_msgs__msg__RTEntry *)calloc(size, sizeof(rt_msgs__msg__RTEntry));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rt_msgs__msg__RTEntry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rt_msgs__msg__RTEntry__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rt_msgs__msg__RTEntry__Sequence__fini(rt_msgs__msg__RTEntry__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rt_msgs__msg__RTEntry__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rt_msgs__msg__RTEntry__Sequence *
rt_msgs__msg__RTEntry__Sequence__create(size_t size)
{
  rt_msgs__msg__RTEntry__Sequence * array = (rt_msgs__msg__RTEntry__Sequence *)malloc(sizeof(rt_msgs__msg__RTEntry__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rt_msgs__msg__RTEntry__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rt_msgs__msg__RTEntry__Sequence__destroy(rt_msgs__msg__RTEntry__Sequence * array)
{
  if (array) {
    rt_msgs__msg__RTEntry__Sequence__fini(array);
  }
  free(array);
}
