#include "Figure.h"

Figure::Figure()
{
    genCircle();
    genArrow();
}

Figure::~Figure()
{
    delete circle;
    delete arrow->bar;
    delete arrow->triangle;
}

void Figure::genCircle()
{
    circle = new sf::CircleShape;
    circle->setRadius(CircleConfig::RADIUS);
    circle->setOutlineThickness(CircleConfig::THICKNESS);
    {
        sf::FloatRect bounds = circle->getLocalBounds();
        circle->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}

void Figure::genArrow()
{
    arrow = new ArrowFigure(ArrowConfig::BAR_WIDTH, ArrowConfig::TRIANGLE_WIDTH, ArrowConfig::HEIGHT_EACH);
}
