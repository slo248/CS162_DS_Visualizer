#ifndef FIGURE_H
#define FIGURE_H

#include "Config.h"
#include "ArrowFigure.h"

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