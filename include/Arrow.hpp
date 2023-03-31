#pragma once

#include <SceneNode.hpp>

class Arrow: public SceneNode
{
    public:
        const float             HEIGHT_EACH=5.f;
        const float             SECOND_WIDTH=10.f;
        const sf::Color         DEFAULT_COLOR=sf::Color::Blue;

    private:
        sf::RectangleShape      mLine;
        sf::ConvexShape         mTriangle;

    public:
        Arrow(sf::Vector2f dist);
        void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};