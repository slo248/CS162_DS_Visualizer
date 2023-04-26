#include "Node.h"
#include "Config.h"

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
    text->setPosition(position.x, position.y+Config::Circle::RADIUS*3.f/2.f);
    text->setScale(scaleFactor);
    window->draw(*text);
}