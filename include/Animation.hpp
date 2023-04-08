#pragma once

#include <functional>
#include <cassert>
#include <SFML/Graphics.hpp>

#define Animator std::function<void(SceneNode&, sf::Time, sf::Time)>

class SceneNode;

struct Animation
{
    typedef std::unique_ptr<Animation> Ptr;
    bool            exactly=false;
    bool            isLast=false;
    bool            once=false;
    bool            isDone=false;
    unsigned int    category;
    sf::Time        duration;
    sf::Time        elapsedTime;
    std::vector<Animator> animators;
};

template <class Object, class Function>
Animator derivedAnimator(Function fn)
{
    return [=] (SceneNode& node, sf::Time elapsedTime, sf::Time duration)
    {
        // Check if cast is safe
        assert(dynamic_cast<Object*>(&node) != nullptr);
        // Downcast node and invoke function on it
        fn(static_cast<Object&>(node), elapsedTime, duration);
    };
}