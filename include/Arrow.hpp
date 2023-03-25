#pragma once

#include <SceneNode.hpp>

class Arrow: public SceneNode
{
    private:
        const float             HEIGHT_EACH=10;
        const float             FIRST_WIDTH=35;
        const float             SECOND_WIDTH=20;
        const sf::Color         DEFAULT_COLOR=sf::Color::Black;

    private:
        sf::ConvexShape mConvex;

    public:
        Arrow();
        void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};