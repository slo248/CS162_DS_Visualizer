#ifndef FIGURE_H
#define FIGURE_H

#include "Config.h"
#include "ArrowFigure.h"

struct Figure
{
    sf::CircleShape* circle;
    ArrowFigure* arrow; // arrow
    Figure();
    ~Figure();
    void genCircle();
    void genArrow();
};

#endif // FIGURE_H