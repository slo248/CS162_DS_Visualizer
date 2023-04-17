#ifndef CONFIG_H
#define CONFIG_H

#include "Global.h"

namespace Config
{
    namespace Circle
    {
        const float RADIUS              = 20.f;
        const float THICKNESS           = 3.f;
        const float HALF_WIDTH          = RADIUS+THICKNESS;
    }

    namespace Arrow
    {
        const float BAR_WIDTH           = 50.f;
        const float TRIANGLE_WIDTH      = 10.f;
        const float HEIGHT_EACH         = 3.f;
        const float WIDTH               = BAR_WIDTH+TRIANGLE_WIDTH;
    }

    namespace Button
    {
        const float HEIGHT              = 60.f;
        const float WIDTH               = 100.f;
        const float CHAR_SIZE           = 25.f;
        const sf::Color BG_COLOR        = GREEN;
        const sf::Color BG_MOUSE_OVER   = BLACK;
        const sf::Color TEXT_COLOR      = BLACK;
    }
}

#endif // CONFIG_H