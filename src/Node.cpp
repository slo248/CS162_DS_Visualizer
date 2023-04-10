#include "Node.h"
#include "Motion.h"

void Node::draw(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, float nothing)
{
    circle->setPosition(position);
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);
    window->draw(*circle);
}

void Node::drawGrow(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, float percent)
{
    float ratio=Motion::Bezier(percent);
    circle->setScale(ratio,ratio);
    draw(window, circle, inColor, outColor, 0);
}

void Node::drawShrink(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, float percent)
{
    float ratio=Motion::Bezier(1-percent);
    circle->setScale(ratio,ratio);
    draw(window, circle, inColor, outColor, 0);
}
