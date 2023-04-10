#ifndef FIGURE_H
#define FIGURE_H

#include "ArrowFigure.h"

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
    ArrowFigure* arrow; // arrow
    Figure();
    ~Figure();
    void genHollowCircle();
    void genSolidCircle();
    void genArrow();
};

#endif // FIGURE_H