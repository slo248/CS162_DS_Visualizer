#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button:
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{
public:
private:
    sf::RectangleShape* rect;
    sf::Text* text;
};

#endif // BUTTON_H