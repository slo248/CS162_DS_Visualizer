#ifndef CONFIG_H
#define CONFIG_H

#include "SFML/Graphics.hpp"

namespace CircleConfig
{
    const float RADIUS = 20.f;
    const float THICKNESS = 3.f;
    const float HALF_WIDTH=RADIUS+THICKNESS;
}

namespace ArrowConfig
{
    const float BAR_WIDTH = 50.f;
    const float TRIANGLE_WIDTH = 10.f;
    const float HEIGHT_EACH=3.f;
    const float WIDTH=BAR_WIDTH+TRIANGLE_WIDTH;
}

namespace ButtonConfig
{
    const float HEIGHT = 60.f;
    const float WIDTH = 100.f;
    const sf::Color BG_COLOR = Colors::GREEN;
    const sf::Color BG_MOUSE_OVER = Colors::BLACK;
    const sf::Color TEXT_COLOR = Colors::WHITE;
}

#endif // CONFIG_H