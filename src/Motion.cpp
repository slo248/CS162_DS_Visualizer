#include "Motion.h"
#include <cassert>

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

float Motion::Bezier(float time)
{
    assert(0<=time && time<=1);
    return time * time * (3.0f - 2.0f * time);
}