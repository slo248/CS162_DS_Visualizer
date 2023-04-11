#ifndef BUTTON_H
#define BUTTON_H

#include "HNeed.h"

class Button:
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{
public:
    const float THICK=3.f;

    Button(sf::Font* font, std::string str, sf::Vector2f size, sf::Color bgColor, sf::Color textColor);
    ~Button();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::RectangleShape* rect;
    sf::Text* text;
};

#endif // BUTTON_H