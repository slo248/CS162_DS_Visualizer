#pragma once

#include <Node.hpp>

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

struct NodeScaler
{
    NodeScaler(){};
    float f(float dt) const{
        return dt*dt;
    }
    void operator() (Node& node, sf::Time dt) const{
        float factor=f(node.getScaleTime())/f(node.SCALE_TIME);
        node.scale(factor,factor);
        node.setScaleTime(node.getScaleTime()+dt.asSeconds());
    }
};