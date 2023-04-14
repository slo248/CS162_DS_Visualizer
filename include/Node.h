#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>

struct Node
{
    int value;
    sf::Vector2f position, scaleFactor;
    Node(int value=0, sf::Vector2f position=sf::Vector2f(0, 0)) : 
        value(value), position(position) {}
    
    void draw(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor);
    void drawGrow(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawShrink(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawFadeIn(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawFadeOut(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawMove(sf::RenderWindow* window, sf::Vector2f src, sf::Vector2f dest, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, sf::Text* num, sf::Color numColor, float percent);
    void drawSubscript(sf::RenderWindow* window, sf::Text* text, std::string str, sf::Color textColor);
};

#endif // NODE_H