// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from medbot_msgs:msg/Patient.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/patient.h"


#ifndef MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_H_
#define MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_H_

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
// Member 'id'
// Member 'target_hospital'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Patient in the package medbot_msgs.
/**
  * A patient to be picked up and delivered to a hospital.
 */
typedef struct medbot_msgs__msg__Patient
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String id;
  /// map-frame location
  geometry_msgs__msg__Point position;
  /// hospital label to deliver to, e.g. "hospital_a"
  rosidl_runtime_c__String target_hospital;
  bool picked_up;
} medbot_msgs__msg__Patient;

// Struct for a sequence of medbot_msgs__msg__Patient.
typedef struct medbot_msgs__msg__Patient__Sequence
{
  medbot_msgs__msg__Patient * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} medbot_msgs__msg__Patient__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_H_
