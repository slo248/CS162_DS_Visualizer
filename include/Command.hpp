#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

class SceneNode;

struct Command
{
    int category;
    std::function<void(SceneNode&, sf::Time)> action;
};

template <class Object, class Function>
std::function<void(SceneNode&, sf::Time)>
    derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<Object*>(&node) != nullptr);
        // Downcast node and invoke function on it
        fn(static_cast<Object&>(node), dt);
    };
}