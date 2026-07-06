// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from medbot_msgs:msg/MissionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/mission_state.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__BUILDER_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "medbot_msgs/msg/detail/mission_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace medbot_msgs
{

namespace msg
{

namespace builder
{

class Init_MissionState_detail
{
public:
  explicit Init_MissionState_detail(::medbot_msgs::msg::MissionState & msg)
  : msg_(msg)
  {}
  ::medbot_msgs::msg::MissionState detail(::medbot_msgs::msg::MissionState::_detail_type arg)
  {
    msg_.detail = std::move(arg);
    return std::move(msg_);
  }

private:
  ::medbot_msgs::msg::MissionState msg_;
};

class Init_MissionState_state
{
public:
  explicit Init_MissionState_state(::medbot_msgs::msg::MissionState & msg)
  : msg_(msg)
  {}
  Init_MissionState_detail state(::medbot_msgs::msg::MissionState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_MissionState_detail(msg_);
  }

private:
  ::medbot_msgs::msg::MissionState msg_;
};

class Init_MissionState_header
{
public:
  Init_MissionState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionState_state header(::medbot_msgs::msg::MissionState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MissionState_state(msg_);
  }

private:
  ::medbot_msgs::msg::MissionState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::medbot_msgs::msg::MissionState>()
{
  return medbot_msgs::msg::builder::Init_MissionState_header();
}

}  // namespace medbot_msgs

#endif  // MEDBOT_MSGS__MSG__DETAIL__MISSION_STATE__BUILDER_HPP_
