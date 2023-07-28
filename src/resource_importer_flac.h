// #ifndef RESOURCE_IMPORTER_FLAC_H
// #define RESOURCE_IMPORTER_FLAC_H


// #include <godot_cpp/classes/resource_saver.hpp>
// #include <godot_cpp/classes/file_access.hpp>
// #include <godot_cpp/classes/texture.hpp>
// #include <godot_cpp/classes/resource_importer.hpp>
// #include "audio_stream_flac.h"

// namespace godot {

// class ResourceImporterFLAC : public ResourceImporter {
// 	GDCLASS(ResourceImporterFLAC, ResourceImporter);

// public:
// 	virtual String _get_importer_name() const override;
// 	virtual String get_visible_name() const override;
// 	virtual void get_recognized_extensions(List<String> *p_extensions) const override;
// 	virtual String get_save_extension() const override;
// 	virtual String get_resource_type() const override;

// 	virtual int get_preset_count() const override;
// 	virtual String get_preset_name(int p_idx) const override;

// 	virtual void get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset = 0) const override;
// 	virtual bool get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const override;

// #ifdef TOOLS_ENABLED
// 	virtual bool has_advanced_options() const override;
// 	virtual void show_advanced_options(const String &p_path) override;
// #endif
// 	static Ref<AudioStreamFLAC> import_flac(const String &p_path);

// 	virtual Error import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files = nullptr, Variant *r_metadata = nullptr) override;

// 	ResourceImporterFLAC();
// };

// };

// #endif // RESOURCE_IMPORTER_FLAC_H
