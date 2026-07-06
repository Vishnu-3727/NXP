# A patient to be picked up and delivered to a hospital.
std_msgs/Header header
string id
geometry_msgs/Point position   # map-frame location
string target_hospital         # hospital label to deliver to, e.g. "hospital_a"
bool picked_up
