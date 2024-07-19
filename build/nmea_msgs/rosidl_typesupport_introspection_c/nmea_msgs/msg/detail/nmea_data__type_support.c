// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nmea_msgs:msg/NmeaData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nmea_msgs/msg/detail/nmea_data__rosidl_typesupport_introspection_c.h"
#include "nmea_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nmea_msgs/msg/detail/nmea_data__functions.h"
#include "nmea_msgs/msg/detail/nmea_data__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void NmeaData__rosidl_typesupport_introspection_c__NmeaData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nmea_msgs__msg__NmeaData__init(message_memory);
}

void NmeaData__rosidl_typesupport_introspection_c__NmeaData_fini_function(void * message_memory)
{
  nmea_msgs__msg__NmeaData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nmea_msgs__msg__NmeaData, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_members = {
  "nmea_msgs__msg",  // message namespace
  "NmeaData",  // message name
  1,  // number of fields
  sizeof(nmea_msgs__msg__NmeaData),
  NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_member_array,  // message members
  NmeaData__rosidl_typesupport_introspection_c__NmeaData_init_function,  // function to initialize message memory (memory has to be allocated)
  NmeaData__rosidl_typesupport_introspection_c__NmeaData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_type_support_handle = {
  0,
  &NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nmea_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nmea_msgs, msg, NmeaData)() {
  if (!NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_type_support_handle.typesupport_identifier) {
    NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NmeaData__rosidl_typesupport_introspection_c__NmeaData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
