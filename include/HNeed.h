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

typedef std::function<void(float)> functor;

namespace Colors
{
    const sf::Color BLANK = sf::Color(0, 0, 0, 0);
    const sf::Color BLACK = sf::Color(0, 0, 0, 255);
    const sf::Color WHITE = sf::Color(255, 255, 255, 255);
    const sf::Color ORANGE = sf::Color(255, 138, 39, 255);
    const sf::Color GREEN = sf::Color(82, 188, 105, 255);
    const sf::Color BLUE = sf::Color(46, 187, 209, 255);
    const sf::Color RED = sf::Color(217, 81, 60, 255);
}

#endif // HNEED_H