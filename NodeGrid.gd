extends Node


@export var nodesArray = [];
@export var neighbor_distance = 4;
var astar = AStar3D.new();


# Called when the node enters the scene tree for the first time.
func _ready():
	var tween = get_tree().create_tween()
	nodesArray = get_tree().get_nodes_in_group('Waypoint');
	
	for node in nodesArray:
		astar.add_point(node.get_instance_id(), node.global_transform.origin);
			
	for node in nodesArray:
		for otherNode in nodesArray:
			if (node != otherNode && !node.neighbors.has(otherNode)):
				if (node.global_transform.origin.distance_to(otherNode.global_transform.origin) < neighbor_distance):
					node.neighbors.push_back(otherNode);
					otherNode.neighbors.push_back(node);
					astar.connect_points(node.get_instance_id(), otherNode.get_instance_id(), true);
					
	print(nodesArray[0].neighbors)
	
	var character = self.get_node("DemoSphere")
	var path = astar.get_point_path(nodesArray[0].get_instance_id(), nodesArray[3].get_instance_id())
#	print(path, path[0].get_type())
	print(character)
	
	
	for point in path:
		tween.tween_property(character, "position", point, 1)
		
	



# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

