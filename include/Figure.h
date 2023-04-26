#ifndef FIGURE_H
#define FIGURE_H

#include "Config.h"
#include "ArrowFigure.h"

struct Figure
{
    sf::CircleShape* circle;
    sf::RectangleShape* square;
    ArrowFigure* arrow; // arrow
    Figure();
    ~Figure();
    void genCircle();
    void genSquare();
    void genArrow();
};

#endif // FIGURE_H