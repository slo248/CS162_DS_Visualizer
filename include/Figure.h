#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>

namespace CircleConfig
{
    const float RADIUS = 20.f;
    const float THICKNESS = 6.f;
}

struct Figure
{
    sf::CircleShape* hCircle; // hollow circle
    sf::CircleShape* sCircle; // solid circle
    Figure();
    ~Figure();
    void genHollowCircle();
    void genSolidCircle();
};

#endif // FIGURE_H