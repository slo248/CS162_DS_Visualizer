#include "Figure.h"

Figure::Figure()
{
    genHollowCircle();
    genSolidCircle();
}

Figure::~Figure()
{
    delete hCircle;
    delete sCircle;
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
