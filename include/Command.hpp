#pragma once

#include <functional>

class SceneNode;

struct Command
{
    int category;
    std::function<void(SceneNode&, sf::Time)> action;
};