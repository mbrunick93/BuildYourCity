extends Node2D

@onready var tile_map = $TileMap
@onready var building_window = $BuildingWindow
@onready var godot_dds_wrapper = $GodotDDSWrapper
@onready var revenue_label = $ColorRect/MarginContainer/HBoxContainer/VBoxContainer/GridContainer/RevenueLabel
@onready var population_label = $ColorRect/MarginContainer/HBoxContainer/VBoxContainer/GridContainer/PopulationLabel
@onready var tick_value = $ColorRect/MarginContainer/HBoxContainer/VBoxContainer2/GridContainer/TickValue
@onready var progress_bar = $ColorRect/MarginContainer/HBoxContainer/VBoxContainer/ProgressBar



# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


func _input(event):
	if Input.is_action_just_pressed("mb_left"):
		if(building_window.visible):
			building_window.hide()
		var mouse_pos = get_global_mouse_position()
		var tileMousePos = tile_map.local_to_map(mouse_pos)
		
		if (tileMousePos.y <= 19):
			print("Mouse position: ",tileMousePos)
			building_window.setLocation(tileMousePos)
			building_window.show()
		
		
func _process(delta):
	godot_dds_wrapper.update()
	revenue_label.set_text(godot_dds_wrapper.getRevenue())
	population_label.set_text(godot_dds_wrapper.getPopulation())
	tick_value.set_text(godot_dds_wrapper.getTick())
	var pro = godot_dds_wrapper.getHappiness()
	progress_bar.value = pro

func _on_main_menu_button_pressed():
	get_tree().change_scene_to_file("res://MainMenu/Scenes/MainMenu.tscn")
