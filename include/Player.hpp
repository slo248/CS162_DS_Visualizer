#pragma once

#include <Node.hpp>
#include <Arrow.hpp>
#include <CommandQueue.hpp>

class Player
{
    public:
        void   handleEvent(const sf::Event& event, CommandQueue& commands);
        void   handleRealtimeInput(CommandQueue& commands);
};

struct NodeMover
{
    NodeMover(float vx, float vy): 
        mVelocityX(vx), mVelocityY(vy){};
    void operator() (Node& node, sf::Time dt) const{
        node.accelerate(mVelocityX, mVelocityY);
    }

    float mVelocityX;
    float mVelocityY;
};

struct NodeStopper
{
    NodeStopper(){};
    void operator() (Node& node, sf::Time dt) const{
        node.setVelocity(0.f, 0.f);
    }
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