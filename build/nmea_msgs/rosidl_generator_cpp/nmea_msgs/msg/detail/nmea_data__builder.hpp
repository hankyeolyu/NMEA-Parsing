// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nmea_msgs:msg/NmeaData.idl
// generated code does not contain a copyright notice

#ifndef NMEA_MSGS__MSG__DETAIL__NMEA_DATA__BUILDER_HPP_
#define NMEA_MSGS__MSG__DETAIL__NMEA_DATA__BUILDER_HPP_

#include "nmea_msgs/msg/detail/nmea_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nmea_msgs
{

namespace msg
{

namespace builder
{

class Init_NmeaData_data
{
public:
  Init_NmeaData_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nmea_msgs::msg::NmeaData data(::nmea_msgs::msg::NmeaData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nmea_msgs::msg::NmeaData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nmea_msgs::msg::NmeaData>()
{
  return nmea_msgs::msg::builder::Init_NmeaData_data();
}

}  // namespace nmea_msgs

#endif  // NMEA_MSGS__MSG__DETAIL__NMEA_DATA__BUILDER_HPP_
