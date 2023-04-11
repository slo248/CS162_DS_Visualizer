#include "Node.h"
#include "Motion.h"
#include "HNeed.h"

void Node::draw(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float nothing)
{
    circle->setPosition(position);
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);

    num->setString(std::to_string(value));
    {
        sf::FloatRect textRect = num->getLocalBounds();
        num->setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    }
    num->setPosition(position);
    num->setFillColor(numColor);
        
    window->draw(*circle);
    window->draw(*num);
}

void Node::drawGrow(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(percent);
    circle->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    draw(window, circle, inColor, outColor, num, numColor, 0);
}

void Node::drawShrink(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(1-percent);
    circle->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    draw(window, circle, inColor, outColor, num, numColor, 0);
}
