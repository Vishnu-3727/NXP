// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from medbot_msgs:msg/MissionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/mission_state.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__TRAITS_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "medbot_msgs/msg/detail/mission_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace medbot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MissionState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: detail
  {
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MissionState & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: detail
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MissionState & msg, bool use_flow_style = false)
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
  const medbot_msgs::msg::MissionState & msg,
  std::ostream & out, size_t indentation = 0)
{
  medbot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use medbot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const medbot_msgs::msg::MissionState & msg)
{
  return medbot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<medbot_msgs::msg::MissionState>()
{
  return "medbot_msgs::msg::MissionState";
}

template<>
inline const char * name<medbot_msgs::msg::MissionState>()
{
  return "medbot_msgs/msg/MissionState";
}

template<>
struct has_fixed_size<medbot_msgs::msg::MissionState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<medbot_msgs::msg::MissionState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<medbot_msgs::msg::MissionState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__TRAITS_HPP_
