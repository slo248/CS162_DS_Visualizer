#pragma once

#include <SceneNode.hpp>
#include <functional>

struct Command
{
    int category;
    std::function<void(SceneNode&, sf::Time)> action;
};