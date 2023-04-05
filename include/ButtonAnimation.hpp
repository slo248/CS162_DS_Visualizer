#pragma once

#include <Motion.hpp>
#include <Button.hpp>

namespace ButtonAnimation
{
    struct Grow
    {
        Grow(){}
        void operator() (Button& button, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            button.setScale(factor,factor);
        }
    };

    struct Shrink
    {
        Shrink(){}
        void operator() (Button& button, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=1.f-Motion::Bezier(elapsedTime/duration);
            button.setScale(factor,factor);
        }
    };
}