#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>

namespace CircleConfig
{
    const float RADIUS = 20.f;
    const float THICKNESS = 6.f;
}

namespace ArrowConfig
{
    const float BAR_WIDTH = 30.f;
    const float TRIANGLE_WIDTH = 6.f;
    const float HEIGHT_EACH=5.f;
}

struct Figure
{
    sf::CircleShape* hCircle; // hollow circle
    sf::CircleShape* sCircle; // solid circle
    sf::RectangleShape* bar; // body of an arrow
    sf::ConvexShape* triangle; // arrow head
    Figure();
    ~Figure();
    void genHollowCircle();
    void genSolidCircle();
    void genArrow();
};

#endif // FIGURE_H