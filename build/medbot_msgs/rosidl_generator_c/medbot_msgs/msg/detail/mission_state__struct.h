// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from medbot_msgs:msg/MissionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/mission_state.h"


#ifndef MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__STRUCT_H_
#define MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'state'
// Member 'detail'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MissionState in the package medbot_msgs.
/**
  * Current stage of the medical-response mission.
 */
typedef struct medbot_msgs__msg__MissionState
{
  std_msgs__msg__Header header;
  /// One of: IDLE, TO_PATIENT, PICKUP, TO_HOSPITAL, DELIVER, RETURN, DONE, ABORT
  rosidl_runtime_c__String state;
  rosidl_runtime_c__String detail;
} medbot_msgs__msg__MissionState;

// Struct for a sequence of medbot_msgs__msg__MissionState.
typedef struct medbot_msgs__msg__MissionState__Sequence
{
  medbot_msgs__msg__MissionState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} medbot_msgs__msg__MissionState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__STRUCT_H_
