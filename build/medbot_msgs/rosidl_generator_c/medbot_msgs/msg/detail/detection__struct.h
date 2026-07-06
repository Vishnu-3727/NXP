// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from medbot_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/detection.h"


#ifndef MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
#define MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_

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
// Member 'label'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Detection in the package medbot_msgs.
/**
  * A single perceived object (sign, hospital, patient, obstacle).
 */
typedef struct medbot_msgs__msg__Detection
{
  std_msgs__msg__Header header;
  /// e.g. "stop_sign", "hospital_a", "patient", "obstacle"
  rosidl_runtime_c__String label;
  /// 0.0 - 1.0
  float confidence;
  /// position in header.frame_id (camera or map)
  geometry_msgs__msg__Point position;
  /// meters from robot; -1 if unknown
  float distance;
} medbot_msgs__msg__Detection;

// Struct for a sequence of medbot_msgs__msg__Detection.
typedef struct medbot_msgs__msg__Detection__Sequence
{
  medbot_msgs__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} medbot_msgs__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
