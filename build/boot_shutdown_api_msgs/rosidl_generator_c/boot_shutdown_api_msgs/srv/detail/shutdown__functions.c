// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from boot_shutdown_api_msgs:srv/Shutdown.idl
// generated code does not contain a copyright notice
#include "boot_shutdown_api_msgs/srv/detail/shutdown__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
boot_shutdown_api_msgs__srv__Shutdown_Request__init(boot_shutdown_api_msgs__srv__Shutdown_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Request__fini(boot_shutdown_api_msgs__srv__Shutdown_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Request__are_equal(const boot_shutdown_api_msgs__srv__Shutdown_Request * lhs, const boot_shutdown_api_msgs__srv__Shutdown_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Request__copy(
  const boot_shutdown_api_msgs__srv__Shutdown_Request * input,
  boot_shutdown_api_msgs__srv__Shutdown_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

boot_shutdown_api_msgs__srv__Shutdown_Request *
boot_shutdown_api_msgs__srv__Shutdown_Request__create()
{
  boot_shutdown_api_msgs__srv__Shutdown_Request * msg = (boot_shutdown_api_msgs__srv__Shutdown_Request *)malloc(sizeof(boot_shutdown_api_msgs__srv__Shutdown_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(boot_shutdown_api_msgs__srv__Shutdown_Request));
  bool success = boot_shutdown_api_msgs__srv__Shutdown_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Request__destroy(boot_shutdown_api_msgs__srv__Shutdown_Request * msg)
{
  if (msg) {
    boot_shutdown_api_msgs__srv__Shutdown_Request__fini(msg);
  }
  free(msg);
}


bool
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__init(boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  boot_shutdown_api_msgs__srv__Shutdown_Request * data = NULL;
  if (size) {
    data = (boot_shutdown_api_msgs__srv__Shutdown_Request *)calloc(size, sizeof(boot_shutdown_api_msgs__srv__Shutdown_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = boot_shutdown_api_msgs__srv__Shutdown_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        boot_shutdown_api_msgs__srv__Shutdown_Request__fini(&data[i - 1]);
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
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__fini(boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      boot_shutdown_api_msgs__srv__Shutdown_Request__fini(&array->data[i]);
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

boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence *
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__create(size_t size)
{
  boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * array = (boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence *)malloc(sizeof(boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__destroy(boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * array)
{
  if (array) {
    boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__fini(array);
  }
  free(array);
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__are_equal(const boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * lhs, const boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!boot_shutdown_api_msgs__srv__Shutdown_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence__copy(
  const boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * input,
  boot_shutdown_api_msgs__srv__Shutdown_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(boot_shutdown_api_msgs__srv__Shutdown_Request);
    boot_shutdown_api_msgs__srv__Shutdown_Request * data =
      (boot_shutdown_api_msgs__srv__Shutdown_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!boot_shutdown_api_msgs__srv__Shutdown_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          boot_shutdown_api_msgs__srv__Shutdown_Request__fini(&data[i]);
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
    if (!boot_shutdown_api_msgs__srv__Shutdown_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
#include "autoware_adapi_v1_msgs/msg/detail/response_status__functions.h"

bool
boot_shutdown_api_msgs__srv__Shutdown_Response__init(boot_shutdown_api_msgs__srv__Shutdown_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!autoware_adapi_v1_msgs__msg__ResponseStatus__init(&msg->status)) {
    boot_shutdown_api_msgs__srv__Shutdown_Response__fini(msg);
    return false;
  }
  return true;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Response__fini(boot_shutdown_api_msgs__srv__Shutdown_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  autoware_adapi_v1_msgs__msg__ResponseStatus__fini(&msg->status);
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Response__are_equal(const boot_shutdown_api_msgs__srv__Shutdown_Response * lhs, const boot_shutdown_api_msgs__srv__Shutdown_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!autoware_adapi_v1_msgs__msg__ResponseStatus__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Response__copy(
  const boot_shutdown_api_msgs__srv__Shutdown_Response * input,
  boot_shutdown_api_msgs__srv__Shutdown_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!autoware_adapi_v1_msgs__msg__ResponseStatus__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

boot_shutdown_api_msgs__srv__Shutdown_Response *
boot_shutdown_api_msgs__srv__Shutdown_Response__create()
{
  boot_shutdown_api_msgs__srv__Shutdown_Response * msg = (boot_shutdown_api_msgs__srv__Shutdown_Response *)malloc(sizeof(boot_shutdown_api_msgs__srv__Shutdown_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(boot_shutdown_api_msgs__srv__Shutdown_Response));
  bool success = boot_shutdown_api_msgs__srv__Shutdown_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Response__destroy(boot_shutdown_api_msgs__srv__Shutdown_Response * msg)
{
  if (msg) {
    boot_shutdown_api_msgs__srv__Shutdown_Response__fini(msg);
  }
  free(msg);
}


bool
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__init(boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  boot_shutdown_api_msgs__srv__Shutdown_Response * data = NULL;
  if (size) {
    data = (boot_shutdown_api_msgs__srv__Shutdown_Response *)calloc(size, sizeof(boot_shutdown_api_msgs__srv__Shutdown_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = boot_shutdown_api_msgs__srv__Shutdown_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        boot_shutdown_api_msgs__srv__Shutdown_Response__fini(&data[i - 1]);
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
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__fini(boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      boot_shutdown_api_msgs__srv__Shutdown_Response__fini(&array->data[i]);
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

boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence *
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__create(size_t size)
{
  boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * array = (boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence *)malloc(sizeof(boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__destroy(boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * array)
{
  if (array) {
    boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__fini(array);
  }
  free(array);
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__are_equal(const boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * lhs, const boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!boot_shutdown_api_msgs__srv__Shutdown_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence__copy(
  const boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * input,
  boot_shutdown_api_msgs__srv__Shutdown_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(boot_shutdown_api_msgs__srv__Shutdown_Response);
    boot_shutdown_api_msgs__srv__Shutdown_Response * data =
      (boot_shutdown_api_msgs__srv__Shutdown_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!boot_shutdown_api_msgs__srv__Shutdown_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          boot_shutdown_api_msgs__srv__Shutdown_Response__fini(&data[i]);
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
    if (!boot_shutdown_api_msgs__srv__Shutdown_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
