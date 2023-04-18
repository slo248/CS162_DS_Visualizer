#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "Global.h"

class TextBox: public sf::Drawable
{
public:
    TextBox(
        sf::Font* font,
        sf::Vector2f position
    );

private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
    std::string         mStr;
};

#endif // TEXT_BOX_H