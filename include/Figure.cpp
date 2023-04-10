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
    hCircle->setRadius(30);
    hCircle->setOutlineThickness(5);
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
    sCircle->setRadius(30);
    {
        sf::FloatRect bounds = sCircle->getLocalBounds();
        sCircle->setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
}
