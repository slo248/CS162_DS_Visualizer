#pragma once

#include <SceneNode.hpp>

class Entity: public SceneNode
{
    public:
        virtual unsigned int    getCategory() const;
        sf::Vector2f            getVelocity() const;
        void                    setVelocity(sf::Vector2f velocity);
        void                    setVelocity(float vx, float vy);
        void                    accelerate(sf::Vector2f velocity);
        void                    accelerate(float vx, float vy);

    protected:
        sf::Vector2f    mVelocity;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void    updateCurrent(sf::Time dt);
};