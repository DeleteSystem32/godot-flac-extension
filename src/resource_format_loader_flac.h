#ifndef RESOURCE_FORMAT_LOADER_FLAC_H
#define RESOURCE_FORMAT_LOADER_FLAC_H

#include <godot_cpp/classes/resource_format_loader.hpp>
#include <godot_cpp/classes/file_access.hpp>

namespace godot
{

class ResourceFormatLoaderFLAC : public ResourceFormatLoader {
    GDCLASS(ResourceFormatLoaderFLAC, ResourceFormatLoader);

private:
    /* data */
protected:
    static void _bind_methods();

public:

    virtual PackedStringArray _get_recognized_extensions() const override;
	virtual bool _handles_type(const StringName &type) const override;
	virtual String _get_resource_type(const String &path) const override;
	virtual bool _exists(const String &path) const override;
	virtual Variant _load(const String &path, const String &original_path, bool use_sub_threads, int32_t cache_mode) const override;

    ResourceFormatLoaderFLAC();
	virtual ~ResourceFormatLoaderFLAC();

};

};

#endif