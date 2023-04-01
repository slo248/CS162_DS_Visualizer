#pragma once

#include <Node.hpp>
#include <Arrow.hpp>
#include <CommandQueue.hpp>

class User
{
    public:
        void   handleEvent(const sf::Event& event, CommandQueue& commands);
        void   handleRealtimeInput(CommandQueue& commands);
};