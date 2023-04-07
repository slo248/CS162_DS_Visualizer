#pragma once

#include <Motion.hpp>
#include <SceneNode.hpp>

namespace SNAnimation
{
    struct Grow
    {
        Grow(){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setScale(factor,factor);
        }
    };

    struct Shrink
    {
        Shrink(){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=1.f-Motion::Bezier(elapsedTime/duration);
            node.setScale(factor,factor);
        }
    };

    struct Move
    {
        sf::Vector2f src;
        sf::Vector2f dest;
        Move(sf::Vector2f src,sf::Vector2f dest):
            src(src),dest(dest){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setPosition(src+(dest-src)*factor);
        }
    };
}