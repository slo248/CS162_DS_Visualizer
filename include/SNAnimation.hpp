#pragma once

#include <Motion.hpp>
#include <SceneNode.hpp>

namespace SNAnimation
{
    struct Scale
    {
        bool isShrink;
        Scale(bool isShrink):isShrink(isShrink){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            if(isShrink) factor=1.f-factor;
            node.setScale(factor,factor);
        }
    };

    struct RemoveChosen
    {
        RemoveChosen(){}
        void operator() (SceneNode& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setChosen(Category::None);
        }
    };
}