#ifndef BUTTON_H
#define BUTTON_H

#include "Global.h"

class Button
{
public:
    Button(
        sf::Font*       font,
        std::string     str,
        sf::Texture*    bgTexture,
        sf::Vector2f    size,
        sf::Vector2f    position
    );

private:
    sf::Sprite      mRect;
    sf::Text        mText;
};

#endif // BUTTON_H