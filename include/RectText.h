#ifndef RECT_TEXT_H
#define RECT_TEXT_H

#include "Global.h"

class RectText : public sf::Drawable
{
public:
    RectText(
        sf::Font*       font,
        sf::Texture*    bgTexture,
        std::string     str,
        sf::Vector2f    position
    );
protected:
    sf::Sprite     mRect;
    sf::Text       mText;
};

#endif // RECT_TEXT_H