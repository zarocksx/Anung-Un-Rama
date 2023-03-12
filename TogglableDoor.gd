extends Node3D

@export var is_closed: bool = false
@export var neighbor_distance = 2.5
var neighboring_waypoints = []
var monster

# Called when the node enters the scene tree for the first time.
func _ready():
	await get_tree().create_timer(0.1).timeout;
	monster = get_tree().get_nodes_in_group('Monster')[0]
		
	if monster:
		for node in monster.waypoints:
			if (self.global_transform.origin.distance_to(node.global_transform.origin) < neighbor_distance):
				neighboring_waypoints.push_back(node)


func door_close():
	self.monster.astar.disconnect_points(neighboring_waypoints[0].get_instance_id(), neighboring_waypoints[1].get_instance_id())
#	animate door here

func door_open():
	self.monster.astar.connect_points(neighboring_waypoints[0].get_instance_id(), neighboring_waypoints[1].get_instance_id())
#	animate door here

func _input(_event):
	if Input.is_key_pressed(KEY_A):
		door_close()
