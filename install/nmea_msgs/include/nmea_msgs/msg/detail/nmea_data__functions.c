// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nmea_msgs:msg/NmeaData.idl
// generated code does not contain a copyright notice
#include "nmea_msgs/msg/detail/nmea_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

bool
nmea_msgs__msg__NmeaData__init(nmea_msgs__msg__NmeaData * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    nmea_msgs__msg__NmeaData__fini(msg);
    return false;
  }
  return true;
}

void
nmea_msgs__msg__NmeaData__fini(nmea_msgs__msg__NmeaData * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__String__fini(&msg->data);
}

bool
nmea_msgs__msg__NmeaData__are_equal(const nmea_msgs__msg__NmeaData * lhs, const nmea_msgs__msg__NmeaData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
nmea_msgs__msg__NmeaData__copy(
  const nmea_msgs__msg__NmeaData * input,
  nmea_msgs__msg__NmeaData * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

nmea_msgs__msg__NmeaData *
nmea_msgs__msg__NmeaData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nmea_msgs__msg__NmeaData * msg = (nmea_msgs__msg__NmeaData *)allocator.allocate(sizeof(nmea_msgs__msg__NmeaData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nmea_msgs__msg__NmeaData));
  bool success = nmea_msgs__msg__NmeaData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nmea_msgs__msg__NmeaData__destroy(nmea_msgs__msg__NmeaData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nmea_msgs__msg__NmeaData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nmea_msgs__msg__NmeaData__Sequence__init(nmea_msgs__msg__NmeaData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nmea_msgs__msg__NmeaData * data = NULL;

  if (size) {
    data = (nmea_msgs__msg__NmeaData *)allocator.zero_allocate(size, sizeof(nmea_msgs__msg__NmeaData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nmea_msgs__msg__NmeaData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nmea_msgs__msg__NmeaData__fini(&data[i - 1]);
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
nmea_msgs__msg__NmeaData__Sequence__fini(nmea_msgs__msg__NmeaData__Sequence * array)
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
      nmea_msgs__msg__NmeaData__fini(&array->data[i]);
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

nmea_msgs__msg__NmeaData__Sequence *
nmea_msgs__msg__NmeaData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nmea_msgs__msg__NmeaData__Sequence * array = (nmea_msgs__msg__NmeaData__Sequence *)allocator.allocate(sizeof(nmea_msgs__msg__NmeaData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nmea_msgs__msg__NmeaData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nmea_msgs__msg__NmeaData__Sequence__destroy(nmea_msgs__msg__NmeaData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nmea_msgs__msg__NmeaData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nmea_msgs__msg__NmeaData__Sequence__are_equal(const nmea_msgs__msg__NmeaData__Sequence * lhs, const nmea_msgs__msg__NmeaData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nmea_msgs__msg__NmeaData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nmea_msgs__msg__NmeaData__Sequence__copy(
  const nmea_msgs__msg__NmeaData__Sequence * input,
  nmea_msgs__msg__NmeaData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nmea_msgs__msg__NmeaData);
    nmea_msgs__msg__NmeaData * data =
      (nmea_msgs__msg__NmeaData *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nmea_msgs__msg__NmeaData__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          nmea_msgs__msg__NmeaData__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nmea_msgs__msg__NmeaData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
