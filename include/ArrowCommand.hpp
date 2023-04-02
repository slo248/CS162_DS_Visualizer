#pragma once

#include <Arrow.hpp>

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