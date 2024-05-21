extends Window
@onready var tile_map = $"../TileMap"

var location:Vector2i 
var groundLayer = 0
var atlasSourceId = 0
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func setLocation(newLocation:Vector2i):
	location = newLocation
	

func _on_close_requested():
	hide()




func _on_store_button_pressed():
	var store_atlas_coord = Vector2i(4,3)
	tile_map.set_cell(groundLayer,location,atlasSourceId,store_atlas_coord)
	hide()


func _on_parking_lot_button_pressed():
	var parking_lot_atlas_coord = Vector2i(5,3)
	tile_map.set_cell(groundLayer,location,atlasSourceId,parking_lot_atlas_coord)
	hide()


func _on_north_south_road_button_pressed():
	var road_atlas_coord = Vector2i(1,2)
	tile_map.set_cell(groundLayer,location,atlasSourceId,road_atlas_coord)
	hide()


func _on_east_west_road_button_pressed():
	var store_atlas_coord = Vector2i(8,4)
	tile_map.set_cell(groundLayer,location,atlasSourceId,store_atlas_coord)
	hide()
