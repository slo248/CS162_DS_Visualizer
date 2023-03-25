#pragma once

#include <SceneNode.hpp>

class Arrow: public SceneNode
{
    private:
        sf::ConvexShape mConvex;
    public:
        Arrow();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};