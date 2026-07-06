// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from medbot_msgs:msg/Patient.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/patient.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__PATIENT__BUILDER_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__PATIENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "medbot_msgs/msg/detail/patient__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace medbot_msgs
{

namespace msg
{

namespace builder
{

class Init_Patient_picked_up
{
public:
  explicit Init_Patient_picked_up(::medbot_msgs::msg::Patient & msg)
  : msg_(msg)
  {}
  ::medbot_msgs::msg::Patient picked_up(::medbot_msgs::msg::Patient::_picked_up_type arg)
  {
    msg_.picked_up = std::move(arg);
    return std::move(msg_);
  }

private:
  ::medbot_msgs::msg::Patient msg_;
};

class Init_Patient_target_hospital
{
public:
  explicit Init_Patient_target_hospital(::medbot_msgs::msg::Patient & msg)
  : msg_(msg)
  {}
  Init_Patient_picked_up target_hospital(::medbot_msgs::msg::Patient::_target_hospital_type arg)
  {
    msg_.target_hospital = std::move(arg);
    return Init_Patient_picked_up(msg_);
  }

private:
  ::medbot_msgs::msg::Patient msg_;
};

class Init_Patient_position
{
public:
  explicit Init_Patient_position(::medbot_msgs::msg::Patient & msg)
  : msg_(msg)
  {}
  Init_Patient_target_hospital position(::medbot_msgs::msg::Patient::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Patient_target_hospital(msg_);
  }

private:
  ::medbot_msgs::msg::Patient msg_;
};

class Init_Patient_id
{
public:
  explicit Init_Patient_id(::medbot_msgs::msg::Patient & msg)
  : msg_(msg)
  {}
  Init_Patient_position id(::medbot_msgs::msg::Patient::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Patient_position(msg_);
  }

private:
  ::medbot_msgs::msg::Patient msg_;
};

class Init_Patient_header
{
public:
  Init_Patient_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patient_id header(::medbot_msgs::msg::Patient::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Patient_id(msg_);
  }

private:
  ::medbot_msgs::msg::Patient msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::medbot_msgs::msg::Patient>()
{
  return medbot_msgs::msg::builder::Init_Patient_header();
}

}  // namespace medbot_msgs

#endif  // MEDBOT_MSGS__MSG__DETAIL__PATIENT__BUILDER_HPP_
