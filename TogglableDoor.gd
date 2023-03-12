extends Node3D

@export var is_closed: bool = false
@export var neighbor_distance = 2.5
@export var is_visible = true
var neighboring_waypoints = []
var monster

func _ready():
	await get_tree().create_timer(0.1).timeout;
	monster = get_tree().get_nodes_in_group('Monster')[0]
		
	if monster:
		for node in monster.waypoints:
			if (self.global_transform.origin.distance_to(node.global_transform.origin) < neighbor_distance):
				neighboring_waypoints.push_back(node)
	if is_closed:
		door_close()
	
	if !is_visible:
		for child in get_children():
			child.visible = false

func door_close() -> void:
	self.monster.astar.disconnect_points(neighboring_waypoints[0].get_instance_id(), neighboring_waypoints[1].get_instance_id())
	is_closed = true
	monster.actualise_path()
#	animate door here

func door_open() -> void:
	self.monster.astar.connect_points(neighboring_waypoints[0].get_instance_id(), neighboring_waypoints[1].get_instance_id())
	is_closed = false
#	animate door here

func _input(_event):
	if Input.is_key_pressed(KEY_A):
		if is_closed:
			door_open()
		else:
			door_close()
