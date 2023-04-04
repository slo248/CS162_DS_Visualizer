#pragma once

#include <Node.hpp>
#include <iostream>

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

struct NodeScaleFlag
{
    NodeScaleFlag(int flag):mFlag(flag){}
    void operator() (Node& node, sf::Time dt) const{
        node.setIsScaling(mFlag);
    }

    int mFlag;
};

struct NodePrintPos{
    NodePrintPos(){}
    void operator() (Node& node, sf::Time dt) const{
        std::cout << node.getPosition().x << " " << node.getPosition().y << std::endl;
    }
};