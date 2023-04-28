#include "Motion.h"
#include <cassert>
#include <cmath>

float Motion::linear(float time)
{
    assert(0<=time && time<=1);
    return time;
}

float Motion::parabolic(float time)
{
    assert(0<=time && time<=1);
    return time * time;
}

float Motion::cubic(float time)
{
    assert(0<=time && time<=1);
    return time * time * time;
}

float Motion::sqrt(float time)
{
    assert(0<=time && time<=1);
    return std::sqrt(time);
}

float Motion::Bezier(float time)
{
    assert(0<=time && time<=1);
    return time * time * (3.0f - 2.0f * time);
}