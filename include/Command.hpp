#pragma once

#include <SceneNode.hpp>
#include <functional>

struct Command
{
    std::function<void(SceneNode&, sf::Time)> action;
};