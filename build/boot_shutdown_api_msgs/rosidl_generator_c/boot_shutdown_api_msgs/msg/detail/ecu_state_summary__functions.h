// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from boot_shutdown_api_msgs:msg/EcuStateSummary.idl
// generated code does not contain a copyright notice

#ifndef BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__FUNCTIONS_H_
#define BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "boot_shutdown_api_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "boot_shutdown_api_msgs/msg/detail/ecu_state_summary__struct.h"

/// Initialize msg/EcuStateSummary message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * boot_shutdown_api_msgs__msg__EcuStateSummary
 * )) before or use
 * boot_shutdown_api_msgs__msg__EcuStateSummary__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__init(boot_shutdown_api_msgs__msg__EcuStateSummary * msg);

/// Finalize msg/EcuStateSummary message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
void
boot_shutdown_api_msgs__msg__EcuStateSummary__fini(boot_shutdown_api_msgs__msg__EcuStateSummary * msg);

/// Create msg/EcuStateSummary message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
boot_shutdown_api_msgs__msg__EcuStateSummary *
boot_shutdown_api_msgs__msg__EcuStateSummary__create();

/// Destroy msg/EcuStateSummary message.
/**
 * It calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
void
boot_shutdown_api_msgs__msg__EcuStateSummary__destroy(boot_shutdown_api_msgs__msg__EcuStateSummary * msg);

/// Check for msg/EcuStateSummary message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__are_equal(const boot_shutdown_api_msgs__msg__EcuStateSummary * lhs, const boot_shutdown_api_msgs__msg__EcuStateSummary * rhs);

/// Copy a msg/EcuStateSummary message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__copy(
  const boot_shutdown_api_msgs__msg__EcuStateSummary * input,
  boot_shutdown_api_msgs__msg__EcuStateSummary * output);

/// Initialize array of msg/EcuStateSummary messages.
/**
 * It allocates the memory for the number of elements and calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__init(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array, size_t size);

/// Finalize array of msg/EcuStateSummary messages.
/**
 * It calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
void
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__fini(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array);

/// Create array of msg/EcuStateSummary messages.
/**
 * It allocates the memory for the array and calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence *
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__create(size_t size);

/// Destroy array of msg/EcuStateSummary messages.
/**
 * It calls
 * boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
void
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__destroy(boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * array);

/// Check for msg/EcuStateSummary message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__are_equal(const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * lhs, const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * rhs);

/// Copy an array of msg/EcuStateSummary messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_boot_shutdown_api_msgs
bool
boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence__copy(
  const boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * input,
  boot_shutdown_api_msgs__msg__EcuStateSummary__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BOOT_SHUTDOWN_API_MSGS__MSG__DETAIL__ECU_STATE_SUMMARY__FUNCTIONS_H_
