#pragma once

#include <Entity.hpp>

class Arrow: public Entity
{
    public:
        const float             HEIGHT_EACH=5.f;
        const float             SECOND_WIDTH=10.f;
        const sf::Color         DEFAULT_COLOR=sf::Color::Blue;

    public:
        Arrow(sf::Vector2f dist);
        unsigned int            getCategory() const;

    private:
        sf::RectangleShape      mLine;
        sf::ConvexShape         mTriangle;
    
    private:
        void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
};