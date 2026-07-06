// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from medbot_msgs:msg/MissionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/mission_state.h"


#ifndef MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__FUNCTIONS_H_
#define MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "medbot_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "medbot_msgs/msg/detail/mission_state__struct.h"

/// Initialize msg/MissionState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * medbot_msgs__msg__MissionState
 * )) before or use
 * medbot_msgs__msg__MissionState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__init(medbot_msgs__msg__MissionState * msg);

/// Finalize msg/MissionState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
void
medbot_msgs__msg__MissionState__fini(medbot_msgs__msg__MissionState * msg);

/// Create msg/MissionState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * medbot_msgs__msg__MissionState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
medbot_msgs__msg__MissionState *
medbot_msgs__msg__MissionState__create(void);

/// Destroy msg/MissionState message.
/**
 * It calls
 * medbot_msgs__msg__MissionState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
void
medbot_msgs__msg__MissionState__destroy(medbot_msgs__msg__MissionState * msg);

/// Check for msg/MissionState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__are_equal(const medbot_msgs__msg__MissionState * lhs, const medbot_msgs__msg__MissionState * rhs);

/// Copy a msg/MissionState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__copy(
  const medbot_msgs__msg__MissionState * input,
  medbot_msgs__msg__MissionState * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
const rosidl_type_hash_t *
medbot_msgs__msg__MissionState__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
const rosidl_runtime_c__type_description__TypeDescription *
medbot_msgs__msg__MissionState__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
const rosidl_runtime_c__type_description__TypeSource *
medbot_msgs__msg__MissionState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
medbot_msgs__msg__MissionState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/MissionState messages.
/**
 * It allocates the memory for the number of elements and calls
 * medbot_msgs__msg__MissionState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__Sequence__init(medbot_msgs__msg__MissionState__Sequence * array, size_t size);

/// Finalize array of msg/MissionState messages.
/**
 * It calls
 * medbot_msgs__msg__MissionState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
void
medbot_msgs__msg__MissionState__Sequence__fini(medbot_msgs__msg__MissionState__Sequence * array);

/// Create array of msg/MissionState messages.
/**
 * It allocates the memory for the array and calls
 * medbot_msgs__msg__MissionState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
medbot_msgs__msg__MissionState__Sequence *
medbot_msgs__msg__MissionState__Sequence__create(size_t size);

/// Destroy array of msg/MissionState messages.
/**
 * It calls
 * medbot_msgs__msg__MissionState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
void
medbot_msgs__msg__MissionState__Sequence__destroy(medbot_msgs__msg__MissionState__Sequence * array);

/// Check for msg/MissionState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__Sequence__are_equal(const medbot_msgs__msg__MissionState__Sequence * lhs, const medbot_msgs__msg__MissionState__Sequence * rhs);

/// Copy an array of msg/MissionState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_medbot_msgs
bool
medbot_msgs__msg__MissionState__Sequence__copy(
  const medbot_msgs__msg__MissionState__Sequence * input,
  medbot_msgs__msg__MissionState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__FUNCTIONS_H_
