// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `summary`
// Member `details`
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__functions.h"

bool
boot_shutdown_api_msgs__msg__EcuStateSummary__init(boot_shutdown_api_msgs__msg__EcuStateSummary * msg)
{
  if (!msg) {
    return false;
  }
  // summary
  if (!boot_shutdown_api_msgs__msg__EcuState__init(&msg->summary)) {
    boot_shutdown_api_msgs__msg__EcuStateSummary__fini(msg);
    return false;
  }
  // details
  if (!boot_shutdown_api_msgs__msg__EcuState__Sequence__init(&msg->details, 0)) {
    boot_shutdown_api_msgs__msg__EcuStateSummary__fini(msg);
    return false;
  }
  return true;
}

void
boot_shutdown_api_msgs__msg__EcuStateSummary__fini(boot_shutdown_api_msgs__msg__EcuStateSummary * msg)
{
  if (!msg) {
    return;
  }
  // summary
  boot_shutdown_api_msgs__msg__EcuState__fini(&msg->summary);
  // details
  boot_shutdown_api_msgs__msg__EcuState__Sequence__fini(&msg->details);
}

bool
boot_shutdown_api_msgs__msg__EcuStateSummary__are_equal(const boot_shutdown_api_msgs__msg__EcuStateSummary * lhs, const boot_shutdown_api_msgs__msg__EcuStateSummary * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // summary
  if (!boot_shutdown_api_msgs__msg__EcuState__are_equal(
      &(lhs->summary), &(rhs->summary)))
  {
    return false;
  }
  // details
  if (!boot_shutdown_api_msgs__msg__EcuState__Sequence__are_equal(
      &(lhs->details), &(rhs->details)))
  {
    return false;
  }
  return true;
}

bool
boot_shutdown_api_msgs__msg__EcuStateSummary__copy(
  const boot_shutdown_api_msgs__msg__EcuStateSummary * input,
  boot_shutdown_api_msgs__msg__EcuStateSummary * output)
{
  if (!input || !output) {
    return false;
  }
  // summary
  if (!boot_shutdown_api_msgs__msg__EcuState__copy(
      &(input->summary), &(output->summary)))
  {
    return false;
  }
  // details
  if (!boot_shutdown_api_msgs__msg__EcuState__Sequence__copy(
      &(input->details), &(output->details)))
  {
    return false;
  }
  return true;
}

boot_shutdown_api_msgs__msg__EcuStateSummary *
boot_shutdown_api_msgs__msg__EcuStateSummary__create()
{
  boot_shutdown_api_msgs__msg__EcuStateSummary * msg = (boot_shutdown_api_msgs__msg__EcuStateSummary *)malloc(sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary));
  bool success = boot_shutdown_api_msgs__msg__EcuStateSummary__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
boot_shutdown_api_msgs__msg__EcuStateSummary__destroy(boot_shutdown_api_msgs__msg__EcuStateSummary * msg)
{
  if (msg) {
    boot_shutdown_api_msgs__msg__EcuStateSummary__fini(msg);
  }
  free(msg);
}


bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__init(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  boot_shutdown_api_msgs__msg__EcuStateSummary * data = NULL;
  if (size) {
    data = (boot_shutdown_api_msgs__msg__EcuStateSummary *)calloc(size, sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = boot_shutdown_api_msgs__msg__EcuStateSummary__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        boot_shutdown_api_msgs__msg__EcuStateSummary__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__fini(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      boot_shutdown_api_msgs__msg__EcuStateSummary__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence *
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__create(size_t size)
{
  boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array = (boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence *)malloc(sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__destroy(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array)
{
  if (array) {
    boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__fini(array);
  }
  free(array);
}

bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__are_equal(const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * lhs, const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!boot_shutdown_api_msgs__msg__EcuStateSummary__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__copy(
  const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * input,
  boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(boot_shutdown_api_msgs__msg__EcuStateSummary);
    boot_shutdown_api_msgs__msg__EcuStateSummary * data =
      (boot_shutdown_api_msgs__msg__EcuStateSummary *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!boot_shutdown_api_msgs__msg__EcuStateSummary__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          boot_shutdown_api_msgs__msg__EcuStateSummary__fini(&data[i]);
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
    if (!boot_shutdown_api_msgs__msg__EcuStateSummary__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
