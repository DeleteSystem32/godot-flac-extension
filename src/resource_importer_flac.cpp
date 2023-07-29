// #include "resource_importer_flac.h"

// #include <godot_cpp/core/class_db.hpp>

// using namespace godot;

// #ifdef TOOLS_ENABLED
// #include "editor/import/audio_stream_import_settings.h"
// #endif

// String ResourceImporterFLAC::get_importer_name() const {
// 	return "flac";
// }

// String ResourceImporterFLAC::get_visible_name() const {
// 	return "FLAC";
// }

// void ResourceImporterFLAC::get_recognized_extensions(List<String> *p_extensions) const {
// 	p_extensions->push_back("flac");
// }

// String ResourceImporterFLAC::get_save_extension() const {
// 	return "flacstr";
// }

// String ResourceImporterFLAC::get_resource_type() const {
// 	return "AudioStreamFLAC";
// }

// bool ResourceImporterFLAC::get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const {
// 	return true;
// }

// int ResourceImporterFLAC::get_preset_count() const {
// 	return 0;
// }

// String ResourceImporterFLAC::get_preset_name(int p_idx) const {
// 	return String();
// }

// void ResourceImporterFLAC::get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset) const {
// 	r_options->push_back(ImportOption(PropertyInfo(Variant::BOOL, "loop"), false));
// 	r_options->push_back(ImportOption(PropertyInfo(Variant::FLOAT, "loop_offset"), 0));
// 	r_options->push_back(ImportOption(PropertyInfo(Variant::FLOAT, "bpm", PROPERTY_HINT_RANGE, "0,400,0.01,or_greater"), 0));
// 	r_options->push_back(ImportOption(PropertyInfo(Variant::INT, "beat_count", PROPERTY_HINT_RANGE, "0,512,or_greater"), 0));
// 	r_options->push_back(ImportOption(PropertyInfo(Variant::INT, "bar_beats", PROPERTY_HINT_RANGE, "2,32,or_greater"), 4));
// }

// #ifdef TOOLS_ENABLED
// bool ResourceImporterFLAC::has_advanced_options() const {
// 	return true;
// }
// void ResourceImporterFLAC::show_advanced_options(const String &p_path) {
// 	Ref<AudioStreamFLAC> flac_stream = import_flac(p_path);
// 	if (flac_stream.is_valid()) {
// 		AudioStreamImportSettings::get_singleton()->edit(p_path, "flac", flac_stream);
// 	}
// }
// #endif

// Ref<AudioStreamFLAC> ResourceImporterFLAC::import_flac(const String &p_path) {
// 	Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
// 	ERR_FAIL_COND_V(f.is_null(), Ref<AudioStreamFLAC>());

// 	uint64_t len = f->get_length();

// 	Vector<uint8_t> data;
// 	data.resize(len);
// 	uint8_t *w = data.ptrw();

// 	f->get_buffer(w, len);

// 	Ref<AudioStreamFLAC> flac_stream;
// 	flac_stream.instantiate();

// 	flac_stream->set_data(data);
// 	ERR_FAIL_COND_V(!flac_stream->get_data().size(), Ref<AudioStreamFLAC>());

// 	return flac_stream;
// }

// Error ResourceImporterFLAC::import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) {
// 	bool loop = p_options["loop"];
// 	float loop_offset = p_options["loop_offset"];
// 	double bpm = p_options["bpm"];
// 	float beat_count = p_options["beat_count"];
// 	float bar_beats = p_options["bar_beats"];

// 	Ref<AudioStreamFLAC> flac_stream = import_flac(p_source_file);
// 	if (flac_stream.is_null()) {
// 		return ERR_CANT_OPEN;
// 	}
// 	flac_stream->set_loop(loop);
// 	flac_stream->set_loop_offset(loop_offset);
// 	flac_stream->set_bpm(bpm);
// 	flac_stream->set_beat_count(beat_count);
// 	flac_stream->set_bar_beats(bar_beats);

// 	return ResourceSaver::save(flac_stream, p_save_path + ".flacstr");
// }

// ResourceImporterFLAC::ResourceImporterFLAC() {
// }
