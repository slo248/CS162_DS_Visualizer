#pragma once

#include <functional>
#include <cassert>
#include <SFML/Graphics.hpp>

class SceneNode;

struct Animation
{
    typedef std::unique_ptr<Animation> Ptr;
    bool            exactly=false;
    unsigned int    category;
    sf::Time        duration;
    sf::Time        elapsedTime;
    std::function<void(SceneNode&, sf::Time, sf::Time)> animator;
};

template <class Object, class Function>
std::function<void(SceneNode&, sf::Time, sf::Time)>
    derivedAnimator(Function fn)
{
    return [=] (SceneNode& node, sf::Time elapsedTime, sf::Time duration)
    {
        // Check if cast is safe
        assert(dynamic_cast<Object*>(&node) != nullptr);
        // Downcast node and invoke function on it
        fn(static_cast<Object&>(node), elapsedTime, duration);
    };
}