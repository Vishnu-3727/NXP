// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from medbot_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/detection.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__medbot_msgs__msg__Detection __attribute__((deprecated))
#else
# define DEPRECATED__medbot_msgs__msg__Detection __declspec(deprecated)
#endif

namespace medbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Detection_
{
  using Type = Detection_<ContainerAllocator>;

  explicit Detection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->confidence = 0.0f;
      this->distance = 0.0f;
    }
  }

  explicit Detection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    label(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->confidence = 0.0f;
      this->distance = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _distance_type =
    float;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    medbot_msgs::msg::Detection_<ContainerAllocator> *;
  using ConstRawPtr =
    const medbot_msgs::msg::Detection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<medbot_msgs::msg::Detection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<medbot_msgs::msg::Detection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      medbot_msgs::msg::Detection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<medbot_msgs::msg::Detection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      medbot_msgs::msg::Detection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<medbot_msgs::msg::Detection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<medbot_msgs::msg::Detection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<medbot_msgs::msg::Detection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__medbot_msgs__msg__Detection
    std::shared_ptr<medbot_msgs::msg::Detection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__medbot_msgs__msg__Detection
    std::shared_ptr<medbot_msgs::msg::Detection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Detection_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const Detection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Detection_

// alias to use template instance with default allocator
using Detection =
  medbot_msgs::msg::Detection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace medbot_msgs

#endif  // MEDBOT_MSGS__MSG__DETAIL__DETECTION__STRUCT_HPP_
