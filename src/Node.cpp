#include "Node.h"

void Node::draw(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, float nothing)
{
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);
    window->draw(*circle);
}