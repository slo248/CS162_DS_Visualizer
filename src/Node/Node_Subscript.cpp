#include "Node.h"
#include "Config.h"

void Node::drawSubscript(sf::RenderWindow *window, sf::Text *text, std::string str, sf::Color textColor, SubscriptDir dir)
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

    sf::FloatRect textRect=text->getLocalBounds();

    switch (dir)
    {
        case UP:
            text->setPosition(
                position.x, 
                position.y-(Config::Circle::HALF_WIDTH+textRect.height/2.f+5.f)
            );
            break;
        case DOWN:
            text->setPosition(
                position.x, 
                position.y+(Config::Circle::HALF_WIDTH+textRect.height/2.f+5.f)
            );
            break;
        case LEFT:
            text->setPosition(
                position.x-(Config::Circle::HALF_WIDTH+textRect.width/2.f+5.f), 
                position.y
            );
            break;
        case RIGHT:
            text->setPosition(
                position.x+(Config::Circle::HALF_WIDTH+textRect.width/2.f+5.f), 
                position.y
            );
            break;
    }

    text->setScale(scaleFactor);
    window->draw(*text);
}