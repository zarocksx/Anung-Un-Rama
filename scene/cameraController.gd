extends Node3D

var cameras = []
var cam_index = 0

func _ready():
	cameras = get_tree().get_nodes_in_group('camera');
	cameras[cam_index].current = true
	
func _input(event):
	if event.is_action_pressed("btn_a_press"):
		pass

	if event.is_action_pressed("btn_b_press"):
		pass

	if event.is_action_pressed("btn_c_press"):
		pass
	
	if event.is_action_pressed("btn_d_press"):
		pass
	
	if event.is_action_pressed("camera_toggle"):
		next_cam()


func next_cam():
	cam_index += 1
	if cam_index > cameras.size() -1:
		cam_index = 0
	cameras[cam_index].current = true
	pass
