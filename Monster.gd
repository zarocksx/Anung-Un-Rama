extends Node


@export var neighbor_distance = 5;
var waypoints = [];
var important_waypoints = [];
var closest_waypoint;
var astar = AStar3D.new();


# Called when the node enters the scene tree for the first time.
func _ready():
	waypoints = get_tree().get_nodes_in_group('Waypoint');

	closest_waypoint = waypoints[0];
	
	for node in waypoints:
		astar.add_point(node.get_instance_id(), node.global_transform.origin);
		if (node.is_interst_point):
			important_waypoints.push_back(node)
			if (self.global_transform.origin.distance_to(closest_waypoint.global_transform.origin) > self.global_transform.origin.distance_to(node.global_transform.origin)):
				closest_waypoint = node
			
	for node in waypoints:
		for otherNode in waypoints:
			if (node != otherNode && !node.neighbors.has(otherNode)):
				if (node.global_transform.origin.distance_to(otherNode.global_transform.origin) < neighbor_distance):
					node.neighbors.push_back(otherNode);
					otherNode.neighbors.push_back(node);
					astar.connect_points(node.get_instance_id(), otherNode.get_instance_id(), true);
					
	
	randomize()
	print('start move')
	var character = self.get_parent()
	var rnd_index = randf_range(1, important_waypoints.size() - 1)
	var path = astar.get_point_path(closest_waypoint.get_instance_id(), important_waypoints[rnd_index].get_instance_id())
	print(path)
	var tween = get_tree().create_tween()
	print(tween)
	for point in path:
		tween.tween_property(character, "position", point, 1)
		
	



# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

