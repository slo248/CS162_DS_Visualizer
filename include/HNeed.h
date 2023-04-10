#ifndef HNEED_H
#define HNEED_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <functional>
#include <cassert>
#include <cmath>
#include <vector>

enum CircleType
{
    Hollow, Solid
};

typedef std::function<float(float)> functor;

#endif // HNEED_H