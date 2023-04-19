#include "Node.h"
#include "Motion.h"
#include "Global.h"
#include "Config.h"

void Node::draw(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor)
{
    scaleFactor=circle->getScale();

    circle->setPosition(position);
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);

    num->setString(std::to_string(value));
    num->setCharacterSize(25);
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
    draw(window, circle, inColor, outColor, num, numColor);
}

void Node::drawShrink(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(1-percent);
    circle->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    draw(window, circle, inColor, outColor, num, numColor);
}

void Node::drawFadeIn(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*Motion::Bezier(percent);
    outColor.a=255*Motion::Bezier(percent);
    numColor.a=255*Motion::Bezier(percent);
    draw(window, circle, inColor, outColor, num, numColor);
}

void Node::drawFadeOut(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*(1-Motion::Bezier(percent));
    outColor.a=255*(1-Motion::Bezier(percent));
    numColor.a=255*(1-Motion::Bezier(percent));
    draw(window, circle, inColor, outColor, num, numColor);
}

void Node::drawMove(sf::RenderWindow *window, sf::Vector2f src, sf::Vector2f dest, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    position=src+(dest-src)*Motion::Bezier(percent);
    draw(window, circle, inColor, outColor, num, numColor);
}

void Node::drawSubscript(sf::RenderWindow *window, sf::Text *text, std::string str, sf::Color textColor)
{
    text->setString(str);
    {
        sf::FloatRect textRect = text->getLocalBounds();
        text->setOrigin(
            textRect.left + textRect.width/2.0f, 
            textRect.top  + textRect.height/2.0f
        );
    }
    text->setFillColor(textColor);
    text->setPosition(position.x, position.y+2*Config::Circle::RADIUS);
    text->setScale(scaleFactor);
    window->draw(*text);
}
