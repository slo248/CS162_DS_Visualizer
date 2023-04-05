#pragma once

#include <Motion.hpp>
#include <Node.hpp>
#include <SFML/Graphics.hpp>

namespace NodeAnimation
{
    struct Grow
    {
        Grow(){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setScale(factor,factor);
        }
    };

    struct Shrink
    {
        Shrink(){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=1.f-Motion::Bezier(elapsedTime/duration);
            node.setScale(factor,factor);
        }
    };
}