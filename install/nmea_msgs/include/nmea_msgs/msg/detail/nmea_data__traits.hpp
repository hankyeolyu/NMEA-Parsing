// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nmea_msgs:msg/NmeaData.idl
// generated code does not contain a copyright notice

#ifndef NMEA_MSGS__MSG__DETAIL__NMEA_DATA__TRAITS_HPP_
#define NMEA_MSGS__MSG__DETAIL__NMEA_DATA__TRAITS_HPP_

#include "nmea_msgs/msg/detail/nmea_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nmea_msgs::msg::NmeaData>()
{
  return "nmea_msgs::msg::NmeaData";
}

template<>
inline const char * name<nmea_msgs::msg::NmeaData>()
{
  return "nmea_msgs/msg/NmeaData";
}

template<>
struct has_fixed_size<nmea_msgs::msg::NmeaData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nmea_msgs::msg::NmeaData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nmea_msgs::msg::NmeaData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NMEA_MSGS__MSG__DETAIL__NMEA_DATA__TRAITS_HPP_
