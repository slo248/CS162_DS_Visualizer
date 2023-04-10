#include "Figure.h"

Figure::Figure()
{
    genHollowCircle();
    genSolidCircle();
    genArrow();
}

Figure::~Figure()
{
    delete hCircle;
    delete sCircle;
    delete bar;
    delete triangle;
}

void Figure::genHollowCircle()
{
    hCircle = new sf::CircleShape;
    hCircle->setRadius(CircleConfig::RADIUS);
    hCircle->setOutlineThickness(CircleConfig::THICKNESS);
    {
        sf::FloatRect bounds = hCircle->getLocalBounds();
        hCircle->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}

void Figure::genSolidCircle()
{
    sCircle = new sf::CircleShape;
    sCircle->setRadius(CircleConfig::RADIUS);
    {
        sf::FloatRect bounds = sCircle->getLocalBounds();
        sCircle->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}

void Figure::genArrow()
{
    bar = new sf::RectangleShape;
    bar->setSize(sf::Vector2f(ArrowConfig::BAR_WIDTH, ArrowConfig::HEIGHT_EACH));
    {
        sf::FloatRect bounds = bar->getLocalBounds();
        bar->setOrigin(
            0,
            bounds.top + bounds.height / 2.f
        );
    }

    triangle = new sf::ConvexShape;
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0, 0));
    triangle->setPoint(1, sf::Vector2f(ArrowConfig::TRIANGLE_WIDTH, (3/2)*ArrowConfig::HEIGHT_EACH));
    triangle->setPoint(2, sf::Vector2f(0, 3*ArrowConfig::HEIGHT_EACH));
    {
        sf::FloatRect bounds = triangle->getLocalBounds();
        triangle->setOrigin(
            0,
            bounds.top + bounds.height / 2.f
        );
    }
    triangle->move(sf::Vector2f(ArrowConfig::BAR_WIDTH, 0));
}
