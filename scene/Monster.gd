extends CSGSphere3D

var astar = AStar3D.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	var tween = get_tree().create_tween()
	nodesArray = get_tree().get_nodes_in_group('Waypoint')
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
