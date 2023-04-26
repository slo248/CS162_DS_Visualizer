#include "Figure.h"

using namespace Config;

Figure::Figure()
{
    genCircle();
    genSquare();
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
    circle->setRadius(Circle::RADIUS);
    circle->setOutlineThickness(Circle::THICKNESS);
    {
        sf::FloatRect bounds = circle->getLocalBounds();
        circle->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}

void Figure::genSquare()
{
    square = new sf::RectangleShape;
    square->setSize(sf::Vector2f(Square::WIDTH, Square::HEIGHT));
    square->setOutlineThickness(Square::THICKNESS);
    {
        sf::FloatRect bounds = square->getLocalBounds();
        square->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}

void Figure::genArrow()
{
    arrow = new ArrowFigure(Arrow::BAR_WIDTH, Arrow::TRIANGLE_WIDTH, Arrow::HEIGHT_EACH);
}
