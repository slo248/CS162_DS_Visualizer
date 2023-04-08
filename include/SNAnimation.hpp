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

    struct RemoveChosen
    {
        RemoveChosen(){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setChosen(false);
        }
    };
}