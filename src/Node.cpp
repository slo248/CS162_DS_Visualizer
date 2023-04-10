#include "Node.h"

void Node::draw(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, float nothing)
{
    circle->setPosition(position);
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);
    window->draw(*circle);
}