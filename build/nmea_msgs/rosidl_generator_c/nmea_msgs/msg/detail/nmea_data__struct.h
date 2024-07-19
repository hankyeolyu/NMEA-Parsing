// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nmea_msgs:msg/NmeaData.idl
// generated code does not contain a copyright notice

#ifndef NMEA_MSGS__MSG__DETAIL__NMEA_DATA__STRUCT_H_
#define NMEA_MSGS__MSG__DETAIL__NMEA_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/NmeaData in the package nmea_msgs.
typedef struct nmea_msgs__msg__NmeaData
{
  rosidl_runtime_c__String data;
} nmea_msgs__msg__NmeaData;

// Struct for a sequence of nmea_msgs__msg__NmeaData.
typedef struct nmea_msgs__msg__NmeaData__Sequence
{
  nmea_msgs__msg__NmeaData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nmea_msgs__msg__NmeaData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NMEA_MSGS__MSG__DETAIL__NMEA_DATA__STRUCT_H_
