#ifndef MOTION_H
#define MOTION_H

namespace Motion
{
    float linear(float time);
    float parabolic(float time);
    float cubic(float time);
    float sqrt(float time);
    float Bezier(float time);
}

#endif // MOTION_H