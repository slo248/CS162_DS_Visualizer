#ifndef BUTTON_H
#define BUTTON_H

#include "Global.h"

class Button: public sf::Drawable
{
public:
    Button(
        sf::Font*       font,
        std::string     str,
        sf::Texture*    bgTexture,
        sf::Vector2f    position
    );

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite      mRect;
    sf::Text        mText;
};

#endif // BUTTON_H