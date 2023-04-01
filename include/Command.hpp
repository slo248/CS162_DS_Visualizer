#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

class SceneNode;

struct Command
{
    int category;
    std::function<void(SceneNode&, sf::Time)> action;
};