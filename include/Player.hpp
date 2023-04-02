#pragma once

#include <NodeCommand.hpp>
#include <Arrow.hpp>
#include <CommandQueue.hpp>

class Player
{
    public:
        void   handleEvent(const sf::Event& event, CommandQueue& commands);
        void   handleRealtimeInput(CommandQueue& commands);
};

struct ArrowMover
{
    ArrowMover(float vx, float vy): 
        mVelocityX(vx), mVelocityY(vy){};
    void operator() (Arrow& arrow, sf::Time dt) const{
        arrow.accelerate(mVelocityX, mVelocityY);
    }

    float mVelocityX;
    float mVelocityY;
};