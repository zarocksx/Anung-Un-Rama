extends Node


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _input(event):
	if Input.is_action_just_pressed("A") :
		print("AAAHHHHHH!!!!")
	if Input.is_action_just_pressed("B") :
		print("BBBBBBBBBBBBB!!!!!")
		
		
