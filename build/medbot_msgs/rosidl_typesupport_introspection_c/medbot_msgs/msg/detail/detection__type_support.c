// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from medbot_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "medbot_msgs/msg/detail/detection__rosidl_typesupport_introspection_c.h"
#include "medbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "medbot_msgs/msg/detail/detection__functions.h"
#include "medbot_msgs/msg/detail/detection__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  medbot_msgs__msg__Detection__init(message_memory);
}

void medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_fini_function(void * message_memory)
{
  medbot_msgs__msg__Detection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(medbot_msgs__msg__Detection, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(medbot_msgs__msg__Detection, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(medbot_msgs__msg__Detection, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(medbot_msgs__msg__Detection, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(medbot_msgs__msg__Detection, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_members = {
  "medbot_msgs__msg",  // message namespace
  "Detection",  // message name
  5,  // number of fields
  sizeof(medbot_msgs__msg__Detection),
  false,  // has_any_key_member_
  medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_member_array,  // message members
  medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_init_function,  // function to initialize message memory (memory has to be allocated)
  medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_type_support_handle = {
  0,
  &medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_members,
  get_message_typesupport_handle_function,
  &medbot_msgs__msg__Detection__get_type_hash,
  &medbot_msgs__msg__Detection__get_type_description,
  &medbot_msgs__msg__Detection__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_medbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, medbot_msgs, msg, Detection)() {
  medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_type_support_handle.typesupport_identifier) {
    medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &medbot_msgs__msg__Detection__rosidl_typesupport_introspection_c__Detection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
