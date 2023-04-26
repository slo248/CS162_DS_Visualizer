#include "Node.h"
#include "Motion.h"
#include "Global.h"
#include "Config.h"

void Node::drawSquare(sf::RenderWindow *window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor)
{
    scaleFactor=square->getScale();

    square->setPosition(position);
    square->setFillColor(inColor);
    square->setOutlineColor(outColor);

    num->setString(std::to_string(value));
    num->setCharacterSize(Config::Square::CHAR_SIZE);
    {
        sf::FloatRect textRect = num->getLocalBounds();
        num->setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    }
    num->setPosition(position);
    num->setFillColor(numColor);
        
    window->draw(*square);
    window->draw(*num);
}

void Node::drawSquareGrow(sf::RenderWindow *window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(percent);
    square->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    drawSquare(window, square, inColor, outColor, num, numColor);
}

void Node::drawSquareShrink(sf::RenderWindow *window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent)
{
    float ratio=Motion::Bezier(1-percent);
    square->setScale(ratio,ratio);
    num->setScale(ratio,ratio);
    drawSquare(window, square, inColor, outColor, num, numColor);
}

void Node::drawSquareFadeIn(sf::RenderWindow *window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*Motion::Bezier(percent);
    outColor.a=255*Motion::Bezier(percent);
    numColor.a=255*Motion::Bezier(percent);
    drawSquare(window, square, inColor, outColor, num, numColor);
}

void Node::drawSquareFadeOut(sf::RenderWindow *window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    inColor.a=255*(1-Motion::Bezier(percent));
    outColor.a=255*(1-Motion::Bezier(percent));
    numColor.a=255*(1-Motion::Bezier(percent));
    drawSquare(window, square, inColor, outColor, num, numColor);
}

void Node::drawSquareMove(sf::RenderWindow *window, sf::Vector2f src, sf::Vector2f dest, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text *num, sf::Color numColor, float percent)
{
    position=src+(dest-src)*Motion::Bezier(percent);
    drawSquare(window, square, inColor, outColor, num, numColor);
}
