#include "Node.h"
#include "Motion.h"
#include "Global.h"
#include "Config.h"

void Node::drawCircle(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor)
{
    scaleFactor=circle->getScale();

    circle->setPosition(position);
    circle->setFillColor(inColor);
    circle->setOutlineColor(outColor);

    num->setString(std::to_string(value));
    num->setCharacterSize(Config::Circle::CHAR_SIZE);
    {
        sf::FloatRect textRect = num->getLocalBounds();
        num->setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    }
    num->setPosition(position);
    num->setFillColor(numColor);
        
    window->draw(*circle);
    window->draw(*num);
}

void Node::drawCircleGrow(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(percent);
    circle->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    drawCircle(window, circle, inColor, outColor, num, numColor);
}

void Node::drawCircleShrink(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(1-percent);
    circle->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    drawCircle(window, circle, inColor, outColor, num, numColor);
}

void Node::drawCircleFadeIn(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*Motion::Bezier(percent);
    outColor.a=255*Motion::Bezier(percent);
    numColor.a=255*Motion::Bezier(percent);
    drawCircle(window, circle, inColor, outColor, num, numColor);
}

void Node::drawCircleFadeOut(sf::RenderWindow *window, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*(1-Motion::Bezier(percent));
    outColor.a=255*(1-Motion::Bezier(percent));
    numColor.a=255*(1-Motion::Bezier(percent));
    drawCircle(window, circle, inColor, outColor, num, numColor);
}

void Node::drawCircleMove(sf::RenderWindow *window, sf::Vector2f src, sf::Vector2f dest, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    position=src+(dest-src)*Motion::Bezier(percent);
    drawCircle(window, circle, inColor, outColor, num, numColor);
}

void Node::drawCircleMoveAngle(sf::RenderWindow *window, sf::Vector2f src, sf::Vector2f origin, float alpha, float beta, sf::CircleShape *circle, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    angle=alpha+(beta-alpha)*Motion::Bezier(percent);
    src-=origin;
    position=sf::Vector2f(
        origin.x+src.x*cos(angle)-src.y*sin(angle),
        origin.y+src.x*sin(angle)+src.y*cos(angle)
    );
    drawCircle(window, circle, inColor, outColor, num, numColor);
}
