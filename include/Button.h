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
        sf::Vector2f    position
    );

    bool isMouseOver(sf::RenderWindow* window);
};

#endif // BUTTON_H