#pragma once

#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

namespace Fonts{
    enum ID{
        Arial,
        Consolas,
        Times
    };
}

template<class Resource, class Identifier>
class ResourceHolder{
    private:
        std::map<Identifier,std::unique_ptr<Resource>> holder;
    public:
        void                load(Identifier id, const std::string& dir);
        Resource&           get(Identifier id);
        const Resource&     get(Identifier id) const;
};

#include<ResourceHolder.inl>

typedef class ResourceHolder<sf::Font,Fonts::ID> FontHolder;
