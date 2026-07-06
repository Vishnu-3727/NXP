#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "medbot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__Detection() -> *const std::ffi::c_void;
}

#[link(name = "medbot_msgs__rosidl_generator_c")]
extern "C" {
    fn medbot_msgs__msg__Detection__init(msg: *mut Detection) -> bool;
    fn medbot_msgs__msg__Detection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Detection>, size: usize) -> bool;
    fn medbot_msgs__msg__Detection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Detection>);
    fn medbot_msgs__msg__Detection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Detection>, out_seq: *mut rosidl_runtime_rs::Sequence<Detection>) -> bool;
}

// Corresponds to medbot_msgs__msg__Detection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A single perceived object (sign, hospital, patient, obstacle).

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Detection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// e.g. "stop_sign", "hospital_a", "patient", "obstacle"
    pub label: rosidl_runtime_rs::String,

    /// 0.0 - 1.0
    pub confidence: f32,

    /// position in header.frame_id (camera or map)
    pub position: geometry_msgs::msg::rmw::Point,

    /// meters from robot; -1 if unknown
    pub distance: f32,

}



impl Default for Detection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !medbot_msgs__msg__Detection__init(&mut msg as *mut _) {
        panic!("Call to medbot_msgs__msg__Detection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Detection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Detection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Detection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Detection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Detection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Detection where Self: Sized {
  const TYPE_NAME: &'static str = "medbot_msgs/msg/Detection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__Detection() }
  }
}


#[link(name = "medbot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__Patient() -> *const std::ffi::c_void;
}

#[link(name = "medbot_msgs__rosidl_generator_c")]
extern "C" {
    fn medbot_msgs__msg__Patient__init(msg: *mut Patient) -> bool;
    fn medbot_msgs__msg__Patient__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Patient>, size: usize) -> bool;
    fn medbot_msgs__msg__Patient__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Patient>);
    fn medbot_msgs__msg__Patient__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Patient>, out_seq: *mut rosidl_runtime_rs::Sequence<Patient>) -> bool;
}

// Corresponds to medbot_msgs__msg__Patient
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A patient to be picked up and delivered to a hospital.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Patient {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: rosidl_runtime_rs::String,

    /// map-frame location
    pub position: geometry_msgs::msg::rmw::Point,

    /// hospital label to deliver to, e.g. "hospital_a"
    pub target_hospital: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub picked_up: bool,

}



impl Default for Patient {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !medbot_msgs__msg__Patient__init(&mut msg as *mut _) {
        panic!("Call to medbot_msgs__msg__Patient__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Patient {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Patient__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Patient__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__Patient__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Patient {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Patient where Self: Sized {
  const TYPE_NAME: &'static str = "medbot_msgs/msg/Patient";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__Patient() }
  }
}


#[link(name = "medbot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__MissionState() -> *const std::ffi::c_void;
}

#[link(name = "medbot_msgs__rosidl_generator_c")]
extern "C" {
    fn medbot_msgs__msg__MissionState__init(msg: *mut MissionState) -> bool;
    fn medbot_msgs__msg__MissionState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MissionState>, size: usize) -> bool;
    fn medbot_msgs__msg__MissionState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MissionState>);
    fn medbot_msgs__msg__MissionState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MissionState>, out_seq: *mut rosidl_runtime_rs::Sequence<MissionState>) -> bool;
}

// Corresponds to medbot_msgs__msg__MissionState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Current stage of the medical-response mission.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MissionState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// One of: IDLE, TO_PATIENT, PICKUP, TO_HOSPITAL, DELIVER, RETURN, DONE, ABORT
    pub state: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detail: rosidl_runtime_rs::String,

}



impl Default for MissionState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !medbot_msgs__msg__MissionState__init(&mut msg as *mut _) {
        panic!("Call to medbot_msgs__msg__MissionState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MissionState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__MissionState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__MissionState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { medbot_msgs__msg__MissionState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MissionState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MissionState where Self: Sized {
  const TYPE_NAME: &'static str = "medbot_msgs/msg/MissionState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__medbot_msgs__msg__MissionState() }
  }
}


