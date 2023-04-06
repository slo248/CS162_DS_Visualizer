#pragma once

#include <Entity.hpp>

namespace ArrowConfig
{
    const float             HEIGHT_EACH=5.f;
    const float             SECOND_WIDTH=10.f;
    const sf::Color         DEFAULT_COLOR=sf::Color::Black;

    const sf::Color         ORANGE=sf::Color(255, 138, 39, 255);
}

class Arrow: public Entity
{
    public:
        Arrow(sf::Vector2f dist);
        unsigned int            getCategory() const;
        void                    setColor(const sf::Color& color);

    private:
        sf::RectangleShape      mLine;
        sf::ConvexShape         mTriangle;
    
    private:
        void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
};