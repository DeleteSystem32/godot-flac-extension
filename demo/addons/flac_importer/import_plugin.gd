@tool
extends EditorImportPlugin

enum Presets {DEFAULT}

func _get_importer_name():
	return "stoemason.flac"

func _get_visible_name():
	return "FLAC importer"

func _get_recognized_extensions():
	return ["flac"]

func _get_save_extension():
	return "flacstr"

func _get_resource_type():
	return "AudioStreamFLAC"

func _get_preset_count():
	return Presets.size()

func _get_priority():
	return 1

func _get_import_order():
	return 0

func _get_preset_name(preset_index):
	match preset_index:
		Presets.DEFAULT:
			return "Default"
		_:
			return "Unknown"

func _get_import_options(path, preset_index):
	match preset_index:
		Presets.DEFAULT:
			return []
		_:
			return []


func _get_option_visibility(path, option_name, options):
	return true


func _import(source_file, save_path, options, r_platform_variants, r_gen_files):
	var data = FileAccess.get_file_as_bytes(source_file)
	var flacstr = AudioStreamFLAC.new()
	flacstr.data = data
	return ResourceSaver.save(flacstr, save_path)
