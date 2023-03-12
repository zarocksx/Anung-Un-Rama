extends Node


@export var neighbor_distance = 5;
var waypoints = [];
var important_waypoints = [];
var closest_waypoint;
var astar = AStar3D.new();
var path
var tween
var target_index = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	waypoints = get_tree().get_nodes_in_group('Waypoint');

	closest_waypoint = waypoints[0];
	
	for node in waypoints:
		astar.add_point(node.get_instance_id(), node.global_transform.origin);
		if (node.is_interest_point):
			important_waypoints.push_back(node)

	for node in waypoints:
		for otherNode in waypoints:
			if (node != otherNode && !node.neighbors.has(otherNode)):
				if (node.global_transform.origin.distance_to(otherNode.global_transform.origin) < neighbor_distance):
					node.neighbors.push_back(otherNode);
					otherNode.neighbors.push_back(node);
					astar.connect_points(node.get_instance_id(), otherNode.get_instance_id(), true);
	move()

func move() -> void:
	get_closest()
	tween = get_tree().create_tween()
	randomize()
	while true :
		var new_target_index = randi_range(0, important_waypoints.size() - 1) 
		if new_target_index != target_index:
			target_index = new_target_index
			break
	path = astar.get_point_path(closest_waypoint.get_instance_id(), important_waypoints[target_index].get_instance_id())
	var dirted_path = astar.get_id_path(closest_waypoint.get_instance_id(), important_waypoints[target_index].get_instance_id())
	for pointId in dirted_path:
		astar.set_point_weight_scale(pointId, astar.get_point_weight_scale(pointId) + 1)
	for point in path:
		tween.tween_property(self, "position", point, 0.16)
	tween.tween_callback(move)
	
func get_closest() -> void:
	for node in waypoints:
		if (self.global_transform.origin.distance_to(closest_waypoint.global_transform.origin) > self.global_transform.origin.distance_to(node.global_transform.origin)):
			closest_waypoint = node
	pass
