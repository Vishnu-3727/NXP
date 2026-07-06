// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from medbot_msgs:msg/Patient.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "medbot_msgs/msg/patient.hpp"


#ifndef MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_HPP_
#define MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_HPP_

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
# define DEPRECATED__medbot_msgs__msg__Patient __attribute__((deprecated))
#else
# define DEPRECATED__medbot_msgs__msg__Patient __declspec(deprecated)
#endif

namespace medbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Patient_
{
  using Type = Patient_<ContainerAllocator>;

  explicit Patient_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->target_hospital = "";
      this->picked_up = false;
    }
  }

  explicit Patient_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    id(_alloc),
    position(_alloc, _init),
    target_hospital(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->target_hospital = "";
      this->picked_up = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _target_hospital_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_hospital_type target_hospital;
  using _picked_up_type =
    bool;
  _picked_up_type picked_up;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__target_hospital(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_hospital = _arg;
    return *this;
  }
  Type & set__picked_up(
    const bool & _arg)
  {
    this->picked_up = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    medbot_msgs::msg::Patient_<ContainerAllocator> *;
  using ConstRawPtr =
    const medbot_msgs::msg::Patient_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<medbot_msgs::msg::Patient_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<medbot_msgs::msg::Patient_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      medbot_msgs::msg::Patient_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<medbot_msgs::msg::Patient_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      medbot_msgs::msg::Patient_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<medbot_msgs::msg::Patient_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<medbot_msgs::msg::Patient_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<medbot_msgs::msg::Patient_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__medbot_msgs__msg__Patient
    std::shared_ptr<medbot_msgs::msg::Patient_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__medbot_msgs__msg__Patient
    std::shared_ptr<medbot_msgs::msg::Patient_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Patient_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->target_hospital != other.target_hospital) {
      return false;
    }
    if (this->picked_up != other.picked_up) {
      return false;
    }
    return true;
  }
  bool operator!=(const Patient_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Patient_

// alias to use template instance with default allocator
using Patient =
  medbot_msgs::msg::Patient_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace medbot_msgs

#endif  // MEDBOT_MSGS__MSG__DETAIL__PATIENT__STRUCT_HPP_
