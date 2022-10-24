// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from boot_shutdown_api_msgs:msg/EcuState.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/msg/detail/ecu_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `power_off_time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
boot_shutdown_api_msgs__msg__EcuState__init(boot_shutdown_api_msgs__msg__EcuState * msg)
{
  if (!msg) {
    return false;
  }
  // state
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    boot_shutdown_api_msgs__msg__EcuState__fini(msg);
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    boot_shutdown_api_msgs__msg__EcuState__fini(msg);
    return false;
  }
  // power_off_time
  if (!builtin_interfaces__msg__Time__init(&msg->power_off_time)) {
    boot_shutdown_api_msgs__msg__EcuState__fini(msg);
    return false;
  }
  return true;
}

void
boot_shutdown_api_msgs__msg__EcuState__fini(boot_shutdown_api_msgs__msg__EcuState * msg)
{
  if (!msg) {
    return;
  }
  // state
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // power_off_time
  builtin_interfaces__msg__Time__fini(&msg->power_off_time);
}

bool
boot_shutdown_api_msgs__msg__EcuState__are_equal(const boot_shutdown_api_msgs__msg__EcuState * lhs, const boot_shutdown_api_msgs__msg__EcuState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // power_off_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->power_off_time), &(rhs->power_off_time)))
  {
    return false;
  }
  return true;
}

bool
boot_shutdown_api_msgs__msg__EcuState__copy(
  const boot_shutdown_api_msgs__msg__EcuState * input,
  boot_shutdown_api_msgs__msg__EcuState * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // power_off_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->power_off_time), &(output->power_off_time)))
  {
    return false;
  }
  return true;
}

boot_shutdown_api_msgs__msg__EcuState *
boot_shutdown_api_msgs__msg__EcuState__create()
{
  boot_shutdown_api_msgs__msg__EcuState * msg = (boot_shutdown_api_msgs__msg__EcuState *)malloc(sizeof(boot_shutdown_api_msgs__msg__EcuState));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(boot_shutdown_api_msgs__msg__EcuState));
  bool success = boot_shutdown_api_msgs__msg__EcuState__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
boot_shutdown_api_msgs__msg__EcuState__destroy(boot_shutdown_api_msgs__msg__EcuState * msg)
{
  if (msg) {
    boot_shutdown_api_msgs__msg__EcuState__fini(msg);
  }
  free(msg);
}


bool
boot_shutdown_api_msgs__msg__EcuState__Sequence__init(boot_shutdown_api_msgs__msg__EcuState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  boot_shutdown_api_msgs__msg__EcuState * data = NULL;
  if (size) {
    data = (boot_shutdown_api_msgs__msg__EcuState *)calloc(size, sizeof(boot_shutdown_api_msgs__msg__EcuState));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = boot_shutdown_api_msgs__msg__EcuState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        boot_shutdown_api_msgs__msg__EcuState__fini(&data[i - 1]);
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
boot_shutdown_api_msgs__msg__EcuState__Sequence__fini(boot_shutdown_api_msgs__msg__EcuState__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      boot_shutdown_api_msgs__msg__EcuState__fini(&array->data[i]);
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

boot_shutdown_api_msgs__msg__EcuState__Sequence *
boot_shutdown_api_msgs__msg__EcuState__Sequence__create(size_t size)
{
  boot_shutdown_api_msgs__msg__EcuState__Sequence * array = (boot_shutdown_api_msgs__msg__EcuState__Sequence *)malloc(sizeof(boot_shutdown_api_msgs__msg__EcuState__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = boot_shutdown_api_msgs__msg__EcuState__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
boot_shutdown_api_msgs__msg__EcuState__Sequence__destroy(boot_shutdown_api_msgs__msg__EcuState__Sequence * array)
{
  if (array) {
    boot_shutdown_api_msgs__msg__EcuState__Sequence__fini(array);
  }
  free(array);
}

bool
boot_shutdown_api_msgs__msg__EcuState__Sequence__are_equal(const boot_shutdown_api_msgs__msg__EcuState__Sequence * lhs, const boot_shutdown_api_msgs__msg__EcuState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!boot_shutdown_api_msgs__msg__EcuState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
boot_shutdown_api_msgs__msg__EcuState__Sequence__copy(
  const boot_shutdown_api_msgs__msg__EcuState__Sequence * input,
  boot_shutdown_api_msgs__msg__EcuState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(boot_shutdown_api_msgs__msg__EcuState);
    boot_shutdown_api_msgs__msg__EcuState * data =
      (boot_shutdown_api_msgs__msg__EcuState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!boot_shutdown_api_msgs__msg__EcuState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          boot_shutdown_api_msgs__msg__EcuState__fini(&data[i]);
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
    if (!boot_shutdown_api_msgs__msg__EcuState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
