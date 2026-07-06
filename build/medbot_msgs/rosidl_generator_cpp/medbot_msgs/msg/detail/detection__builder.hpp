// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from medbot_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/detection.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "medbot_msgs/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace medbot_msgs
{

namespace msg
{

namespace builder
{

class Init_Detection_distance
{
public:
  explicit Init_Detection_distance(::medbot_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  ::medbot_msgs::msg::Detection distance(::medbot_msgs::msg::Detection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::medbot_msgs::msg::Detection msg_;
};

class Init_Detection_position
{
public:
  explicit Init_Detection_position(::medbot_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_distance position(::medbot_msgs::msg::Detection::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Detection_distance(msg_);
  }

private:
  ::medbot_msgs::msg::Detection msg_;
};

class Init_Detection_confidence
{
public:
  explicit Init_Detection_confidence(::medbot_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_position confidence(::medbot_msgs::msg::Detection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_Detection_position(msg_);
  }

private:
  ::medbot_msgs::msg::Detection msg_;
};

class Init_Detection_label
{
public:
  explicit Init_Detection_label(::medbot_msgs::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_confidence label(::medbot_msgs::msg::Detection::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Detection_confidence(msg_);
  }

private:
  ::medbot_msgs::msg::Detection msg_;
};

class Init_Detection_header
{
public:
  Init_Detection_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_label header(::medbot_msgs::msg::Detection::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Detection_label(msg_);
  }

private:
  ::medbot_msgs::msg::Detection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::medbot_msgs::msg::Detection>()
{
  return medbot_msgs::msg::builder::Init_Detection_header();
}

}  // namespace medbot_msgs

#endif  // MEDBOT_MSGS__MSG__DETAIL__DETECTION__BUILDER_HPP_
