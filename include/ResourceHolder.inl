#include <assert.h>
#include <utility>


template <class Resource, class Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &dir)
{
    std::unique_ptr<Resource> resource(new Resource());
    if(!resource->loadFromFile(dir))
        throw std::runtime_error("Failed to load "+dir);

    assert(holder.insert(make_pair(id,std::move(resource))).second);
}