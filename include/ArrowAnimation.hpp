#pragma once

#include <Arrow.hpp>

namespace ArrowAnimation
{
    struct ChangeColor
    {
        sf::Color mColor;
        ChangeColor(sf::Color color):mColor(color){}
        void operator() (Arrow* arrow, sf::Time elapsedTime, sf::Time duration) const
        {
            arrow->setColor(mColor);
        }
    };
}