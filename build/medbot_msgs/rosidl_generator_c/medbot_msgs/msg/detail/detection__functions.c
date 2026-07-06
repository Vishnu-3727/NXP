// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from medbot_msgs:msg/Detection.idl
// generated code does not contain a copyright notice
#include "medbot_msgs/msg/detail/detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
medbot_msgs__msg__Detection__init(medbot_msgs__msg__Detection * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    medbot_msgs__msg__Detection__fini(msg);
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    medbot_msgs__msg__Detection__fini(msg);
    return false;
  }
  // confidence
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    medbot_msgs__msg__Detection__fini(msg);
    return false;
  }
  // distance
  return true;
}

void
medbot_msgs__msg__Detection__fini(medbot_msgs__msg__Detection * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // confidence
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // distance
}

bool
medbot_msgs__msg__Detection__are_equal(const medbot_msgs__msg__Detection * lhs, const medbot_msgs__msg__Detection * rhs)
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
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
medbot_msgs__msg__Detection__copy(
  const medbot_msgs__msg__Detection * input,
  medbot_msgs__msg__Detection * output)
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
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  return true;
}

medbot_msgs__msg__Detection *
medbot_msgs__msg__Detection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Detection * msg = (medbot_msgs__msg__Detection *)allocator.allocate(sizeof(medbot_msgs__msg__Detection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(medbot_msgs__msg__Detection));
  bool success = medbot_msgs__msg__Detection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
medbot_msgs__msg__Detection__destroy(medbot_msgs__msg__Detection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    medbot_msgs__msg__Detection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
medbot_msgs__msg__Detection__Sequence__init(medbot_msgs__msg__Detection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Detection * data = NULL;

  if (size) {
    data = (medbot_msgs__msg__Detection *)allocator.zero_allocate(size, sizeof(medbot_msgs__msg__Detection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = medbot_msgs__msg__Detection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        medbot_msgs__msg__Detection__fini(&data[i - 1]);
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
medbot_msgs__msg__Detection__Sequence__fini(medbot_msgs__msg__Detection__Sequence * array)
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
      medbot_msgs__msg__Detection__fini(&array->data[i]);
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

medbot_msgs__msg__Detection__Sequence *
medbot_msgs__msg__Detection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  medbot_msgs__msg__Detection__Sequence * array = (medbot_msgs__msg__Detection__Sequence *)allocator.allocate(sizeof(medbot_msgs__msg__Detection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = medbot_msgs__msg__Detection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
medbot_msgs__msg__Detection__Sequence__destroy(medbot_msgs__msg__Detection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    medbot_msgs__msg__Detection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
medbot_msgs__msg__Detection__Sequence__are_equal(const medbot_msgs__msg__Detection__Sequence * lhs, const medbot_msgs__msg__Detection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!medbot_msgs__msg__Detection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
medbot_msgs__msg__Detection__Sequence__copy(
  const medbot_msgs__msg__Detection__Sequence * input,
  medbot_msgs__msg__Detection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(medbot_msgs__msg__Detection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    medbot_msgs__msg__Detection * data =
      (medbot_msgs__msg__Detection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!medbot_msgs__msg__Detection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          medbot_msgs__msg__Detection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!medbot_msgs__msg__Detection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
