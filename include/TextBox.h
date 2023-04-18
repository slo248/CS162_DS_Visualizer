#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "Global.h"

class TextBox: public sf::Drawable
{
public:
private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
};

#endif // TEXT_BOX_H