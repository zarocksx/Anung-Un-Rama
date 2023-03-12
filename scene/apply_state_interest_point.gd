extends Node3D

@export var is_interest_point: bool = false

# Called when the node enters the scene tree for the first time.
func _ready():
	$Waypoint.is_interest_point = is_interest_point


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
