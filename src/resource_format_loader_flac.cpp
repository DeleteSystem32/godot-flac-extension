#include "resource_format_loader_flac.h"
#include "audio_stream_flac.h"

using namespace godot;

ResourceFormatLoaderFLAC::ResourceFormatLoaderFLAC() {
}

ResourceFormatLoaderFLAC::~ResourceFormatLoaderFLAC() {
}

PackedStringArray ResourceFormatLoaderFLAC::_get_recognized_extensions() const {
    PackedStringArray arr;
    arr.push_back("flac");
    return arr;
}

bool ResourceFormatLoaderFLAC::_handles_type(const StringName &type) const {
    return type == StringName("AudioStreamFLAC");
}

String ResourceFormatLoaderFLAC::_get_resource_type(const String &path) const {
    if(path.get_extension() == "flac") {
        return "AudioStreamFLAC";
    }
    return "";
}

bool ResourceFormatLoaderFLAC::_exists(const String &path) const {
    return FileAccess::file_exists(path);
}

Variant ResourceFormatLoaderFLAC::_load(const String &path, const String &original_path, bool use_sub_threads, int32_t cache_mode) const {
    Ref<AudioStreamFLAC> stream;
    stream.instantiate();
    stream->set_data(FileAccess::get_file_as_bytes(path));
    return stream;
}

void ResourceFormatLoaderFLAC::_bind_methods() {

}