#pragma once

#include <SceneNode.hpp>

class Arrow: public SceneNode
{
    public:
        const float             HEIGHT_EACH=10.f;
        const float             RATIO_FIRST=3.f/4.f;
        const float             RATIO_SECOND=1-RATIO_FIRST;
        const sf::Color         DEFAULT_COLOR=sf::Color::Blue;

    private:
        sf::ConvexShape mConvex;

    public:
        Arrow(sf::Vector2f dist);
        void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};