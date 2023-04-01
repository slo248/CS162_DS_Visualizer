#pragma once

#include <SceneNode.hpp>

class Entity: public SceneNode
{
    public:
        virtual int     getCategory() const;

    private:
        sf::Vector2f    mVelocity;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void    updateCurrent(sf::Time dt);
};