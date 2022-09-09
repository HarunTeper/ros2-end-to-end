// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rt_msgs:msg/RTEntry.idl
// generated code does not contain a copyright notice

#ifndef RT_MSGS__MSG__DETAIL__RT_ENTRY__FUNCTIONS_H_
#define RT_MSGS__MSG__DETAIL__RT_ENTRY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rt_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rt_msgs/msg/detail/rt_entry__struct.h"

/// Initialize msg/RTEntry message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rt_msgs__msg__RTEntry
 * )) before or use
 * rt_msgs__msg__RTEntry__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
bool
rt_msgs__msg__RTEntry__init(rt_msgs__msg__RTEntry * msg);

/// Finalize msg/RTEntry message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
void
rt_msgs__msg__RTEntry__fini(rt_msgs__msg__RTEntry * msg);

/// Create msg/RTEntry message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rt_msgs__msg__RTEntry__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
rt_msgs__msg__RTEntry *
rt_msgs__msg__RTEntry__create();

/// Destroy msg/RTEntry message.
/**
 * It calls
 * rt_msgs__msg__RTEntry__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
void
rt_msgs__msg__RTEntry__destroy(rt_msgs__msg__RTEntry * msg);


/// Initialize array of msg/RTEntry messages.
/**
 * It allocates the memory for the number of elements and calls
 * rt_msgs__msg__RTEntry__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
bool
rt_msgs__msg__RTEntry__Sequence__init(rt_msgs__msg__RTEntry__Sequence * array, size_t size);

/// Finalize array of msg/RTEntry messages.
/**
 * It calls
 * rt_msgs__msg__RTEntry__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
void
rt_msgs__msg__RTEntry__Sequence__fini(rt_msgs__msg__RTEntry__Sequence * array);

/// Create array of msg/RTEntry messages.
/**
 * It allocates the memory for the array and calls
 * rt_msgs__msg__RTEntry__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
rt_msgs__msg__RTEntry__Sequence *
rt_msgs__msg__RTEntry__Sequence__create(size_t size);

/// Destroy array of msg/RTEntry messages.
/**
 * It calls
 * rt_msgs__msg__RTEntry__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt_msgs
void
rt_msgs__msg__RTEntry__Sequence__destroy(rt_msgs__msg__RTEntry__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // RT_MSGS__MSG__DETAIL__RT_ENTRY__FUNCTIONS_H_
