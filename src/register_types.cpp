#include "register_types.h"

#include "audio_stream_flac.h"
#include "resource_format_loader_flac.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

using namespace godot;

static Ref<ResourceFormatLoaderFLAC> resource_loader_flac;

void initialize_flac_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) {
        return;
    }

    // TODO: implement resourceFormatSaver/ ResourceFormatLoader, otherwise importer will not work
    ClassDB::register_class<AudioStreamFLAC>();
    ClassDB::register_class<AudioStreamPlaybackFLAC>();
    ClassDB::register_class<ResourceFormatLoaderFLAC>();
    resource_loader_flac.instantiate();
    ResourceLoader::get_singleton()->add_resource_format_loader(resource_loader_flac);
}

void uninitialize_flac_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) {
        return;
    }

    ResourceLoader::get_singleton()->remove_resource_format_loader(resource_loader_flac);
    resource_loader_flac.unref();
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT flac_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_flac_module);
    init_obj.register_terminator(uninitialize_flac_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_EDITOR);

    return init_obj.init();
}
}