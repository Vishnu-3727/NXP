// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from medbot_msgs:msg/Patient.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/patient.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__PATIENT__TRAITS_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__PATIENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "medbot_msgs/msg/detail/patient__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace medbot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Patient & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: target_hospital
  {
    out << "target_hospital: ";
    rosidl_generator_traits::value_to_yaml(msg.target_hospital, out);
    out << ", ";
  }

  // member: picked_up
  {
    out << "picked_up: ";
    rosidl_generator_traits::value_to_yaml(msg.picked_up, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Patient & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: target_hospital
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_hospital: ";
    rosidl_generator_traits::value_to_yaml(msg.target_hospital, out);
    out << "\n";
  }

  // member: picked_up
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "picked_up: ";
    rosidl_generator_traits::value_to_yaml(msg.picked_up, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Patient & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace medbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use medbot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const medbot_msgs::msg::Patient & msg,
  std::ostream & out, size_t indentation = 0)
{
  medbot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use medbot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const medbot_msgs::msg::Patient & msg)
{
  return medbot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<medbot_msgs::msg::Patient>()
{
  return "medbot_msgs::msg::Patient";
}

template<>
inline const char * name<medbot_msgs::msg::Patient>()
{
  return "medbot_msgs/msg/Patient";
}

template<>
struct has_fixed_size<medbot_msgs::msg::Patient>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<medbot_msgs::msg::Patient>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<medbot_msgs::msg::Patient>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MEDBOT_MSGS__MSG__DETAIL__PATIENT__TRAITS_HPP_
