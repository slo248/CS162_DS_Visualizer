#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>

struct Node
{
    int value;
    sf::Vector2f position;
    Node(int value=0, sf::Vector2f position=sf::Vector2f(0, 0)) : 
        value(value), position(position) {}
    
    void draw(sf::RenderWindow* window, sf::CircleShape* circle, sf::Color inColor, sf::Color outColor, float nothing);
};

#endif // NODE_H