#ifndef NODE_H
#define NODE_H

#include "Global.h"

struct Node
{
    int value;
    sf::Vector2f position, scaleFactor;
    Node(int value=0, sf::Vector2f position=sf::Vector2f(0, 0)) : 
        value(value), position(position) {}
    
    // Circle
    void drawCircle(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor);
    void drawCircleGrow(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawCircleShrink(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawCircleFadeIn(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawCircleFadeOut(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawCircleMove(sf::RenderWindow* window, sf::Vector2f src, sf::Vector2f dest, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawCircleMoveAngle(sf::RenderWindow* window, sf::Vector2f src, float alpha, float beta, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    //

    // Square
    void drawSquare(sf::RenderWindow* window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor);
    void drawSquareGrow(sf::RenderWindow* window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSquareShrink(sf::RenderWindow* window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSquareFadeIn(sf::RenderWindow* window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSquareFadeOut(sf::RenderWindow* window, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSquareMove(sf::RenderWindow* window, sf::Vector2f src, sf::Vector2f dest, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSquareMoveAngle(sf::RenderWindow* window, sf::Vector2f src, float alpha, float beta, sf::RectangleShape* square, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    //

    void drawSubscript(sf::RenderWindow* window, sf::Text* text, std::string str, sf::Color textColor, SubscriptDir dir);
};

#endif // NODE_H