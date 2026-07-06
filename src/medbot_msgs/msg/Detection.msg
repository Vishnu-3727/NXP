# A single perceived object (sign, hospital, patient, obstacle).
std_msgs/Header header
string label                  # e.g. "stop_sign", "hospital_a", "patient", "obstacle"
float32 confidence           # 0.0 - 1.0
geometry_msgs/Point position # position in header.frame_id (camera or map)
float32 distance             # meters from robot; -1 if unknown
