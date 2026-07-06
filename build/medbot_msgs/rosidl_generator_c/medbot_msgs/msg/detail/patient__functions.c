// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from medbot_msgs:msg/Patient.idl
// generated code does not contain a copyright notice
#include "medbot_msgs/msg/detail/patient__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `id`
// Member `target_hospital`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
medbot_msgs__msg__Patient__init(medbot_msgs__msg__Patient * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    medbot_msgs__msg__Patient__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    medbot_msgs__msg__Patient__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    medbot_msgs__msg__Patient__fini(msg);
    return false;
  }
  // target_hospital
  if (!rosidl_runtime_c__String__init(&msg->target_hospital)) {
    medbot_msgs__msg__Patient__fini(msg);
    return false;
  }
  // picked_up
  return true;
}

void
medbot_msgs__msg__Patient__fini(medbot_msgs__msg__Patient * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // target_hospital
  rosidl_runtime_c__String__fini(&msg->target_hospital);
  // picked_up
}

bool
medbot_msgs__msg__Patient__are_equal(const medbot_msgs__msg__Patient * lhs, const medbot_msgs__msg__Patient * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // target_hospital
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_hospital), &(rhs->target_hospital)))
  {
    return false;
  }
  // picked_up
  if (lhs->picked_up != rhs->picked_up) {
    return false;
  }
  return true;
}

bool
medbot_msgs__msg__Patient__copy(
  const medbot_msgs__msg__Patient * input,
  medbot_msgs__msg__Patient * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // target_hospital
  if (!rosidl_runtime_c__String__copy(
      &(input->target_hospital), &(output->target_hospital)))
  {
    return false;
  }
  // picked_up
  output->picked_up = input->picked_up;
  return true;
}

medbot_msgs__msg__Patient *
medbot_msgs__msg__Patient__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Patient * msg = (medbot_msgs__msg__Patient *)allocator.allocate(sizeof(medbot_msgs__msg__Patient), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(medbot_msgs__msg__Patient));
  bool success = medbot_msgs__msg__Patient__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
medbot_msgs__msg__Patient__destroy(medbot_msgs__msg__Patient * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    medbot_msgs__msg__Patient__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
medbot_msgs__msg__Patient__Sequence__init(medbot_msgs__msg__Patient__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Patient * data = NULL;

  if (size) {
    data = (medbot_msgs__msg__Patient *)allocator.zero_allocate(size, sizeof(medbot_msgs__msg__Patient), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = medbot_msgs__msg__Patient__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        medbot_msgs__msg__Patient__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
medbot_msgs__msg__Patient__Sequence__fini(medbot_msgs__msg__Patient__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      medbot_msgs__msg__Patient__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

medbot_msgs__msg__Patient__Sequence *
medbot_msgs__msg__Patient__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Patient__Sequence * array = (medbot_msgs__msg__Patient__Sequence *)allocator.allocate(sizeof(medbot_msgs__msg__Patient__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = medbot_msgs__msg__Patient__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
medbot_msgs__msg__Patient__Sequence__destroy(medbot_msgs__msg__Patient__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    medbot_msgs__msg__Patient__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
medbot_msgs__msg__Patient__Sequence__are_equal(const medbot_msgs__msg__Patient__Sequence * lhs, const medbot_msgs__msg__Patient__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!medbot_msgs__msg__Patient__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
medbot_msgs__msg__Patient__Sequence__copy(
  const medbot_msgs__msg__Patient__Sequence * input,
  medbot_msgs__msg__Patient__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(medbot_msgs__msg__Patient);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    medbot_msgs__msg__Patient * data =
      (medbot_msgs__msg__Patient *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!medbot_msgs__msg__Patient__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          medbot_msgs__msg__Patient__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!medbot_msgs__msg__Patient__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
