extends Node3D

var cameras = []
var cam_index = 0

func _ready():
	cameras = get_tree().get_nodes_in_group('camera');
	cameras[cam_index].current = true

func _input(event):
	if Input.is_key_pressed(KEY_Z):
		next_cam()

func next_cam():
	cam_index += 1
	if cam_index > cameras.size() -1:
		cam_index = 0
	cameras[cam_index].current = true
	pass
