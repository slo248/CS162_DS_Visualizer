#pragma once

#include <map>
#include <memory>
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
        void            load(Identifier id, const std::string& dir);
};

#include<ResourceHolder.inl>
