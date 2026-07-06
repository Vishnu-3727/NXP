#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to medbot_msgs__msg__Detection
/// A single perceived object (sign, hospital, patient, obstacle).

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Detection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// e.g. "stop_sign", "hospital_a", "patient", "obstacle"
    pub label: std::string::String,

    /// 0.0 - 1.0
    pub confidence: f32,

    /// position in header.frame_id (camera or map)
    pub position: geometry_msgs::msg::Point,

    /// meters from robot; -1 if unknown
    pub distance: f32,

}



impl Default for Detection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Detection::default())
  }
}

impl rosidl_runtime_rs::Message for Detection {
  type RmwMsg = super::msg::rmw::Detection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        label: msg.label.as_str().into(),
        confidence: msg.confidence,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        distance: msg.distance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        label: msg.label.as_str().into(),
      confidence: msg.confidence,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      distance: msg.distance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      label: msg.label.to_string(),
      confidence: msg.confidence,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      distance: msg.distance,
    }
  }
}


// Corresponds to medbot_msgs__msg__Patient
/// A patient to be picked up and delivered to a hospital.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Patient {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: std::string::String,

    /// map-frame location
    pub position: geometry_msgs::msg::Point,

    /// hospital label to deliver to, e.g. "hospital_a"
    pub target_hospital: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub picked_up: bool,

}



impl Default for Patient {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Patient::default())
  }
}

impl rosidl_runtime_rs::Message for Patient {
  type RmwMsg = super::msg::rmw::Patient;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        id: msg.id.as_str().into(),
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        target_hospital: msg.target_hospital.as_str().into(),
        picked_up: msg.picked_up,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        id: msg.id.as_str().into(),
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
        target_hospital: msg.target_hospital.as_str().into(),
      picked_up: msg.picked_up,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      id: msg.id.to_string(),
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      target_hospital: msg.target_hospital.to_string(),
      picked_up: msg.picked_up,
    }
  }
}


// Corresponds to medbot_msgs__msg__MissionState
/// Current stage of the medical-response mission.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MissionState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// One of: IDLE, TO_PATIENT, PICKUP, TO_HOSPITAL, DELIVER, RETURN, DONE, ABORT
    pub state: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detail: std::string::String,

}



impl Default for MissionState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MissionState::default())
  }
}

impl rosidl_runtime_rs::Message for MissionState {
  type RmwMsg = super::msg::rmw::MissionState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state.as_str().into(),
        detail: msg.detail.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        state: msg.state.as_str().into(),
        detail: msg.detail.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state.to_string(),
      detail: msg.detail.to_string(),
    }
  }
}


