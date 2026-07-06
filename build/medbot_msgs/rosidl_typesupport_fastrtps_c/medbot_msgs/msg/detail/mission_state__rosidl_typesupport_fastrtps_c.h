// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from medbot_msgs:msg/MissionState.idl
// generated code does not contain a copyright notice
#ifndef MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "medbot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "medbot_msgs/msg/detail/mission_state__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
bool cdr_serialize_medbot_msgs__msg__MissionState(
  const medbot_msgs__msg__MissionState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
bool cdr_deserialize_medbot_msgs__msg__MissionState(
  eprosima::fastcdr::Cdr &,
  medbot_msgs__msg__MissionState * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
size_t get_serialized_size_medbot_msgs__msg__MissionState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
size_t max_serialized_size_medbot_msgs__msg__MissionState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
bool cdr_serialize_key_medbot_msgs__msg__MissionState(
  const medbot_msgs__msg__MissionState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
size_t get_serialized_size_key_medbot_msgs__msg__MissionState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
size_t max_serialized_size_key_medbot_msgs__msg__MissionState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_medbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, medbot_msgs, msg, MissionState)();

#ifdef __cplusplus
}
#endif

#endif  // MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
