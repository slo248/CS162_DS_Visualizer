#ifndef BUTTON_H
#define BUTTON_H

#include "RectText.h"

class Button: public RectText
{
public:
    Button(
        sf::Font*       font,
        sf::Texture*    bgTexture,
        std::string     str,
        sf::Vector2f    position,
        bool            isCentered=false
    );

    bool isMouseOver(sf::RenderWindow* window, sf::Vector2f offset=sf::Vector2f(0, 0));
};

#endif // BUTTON_H