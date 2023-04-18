#ifndef INPUT_BOX_H
#define INPUT_BOX_H

#include "TextBox.h"

class InputBox
{
public:
    InputBox(
        sf::Font* font,
        sf::Vector2f position,
        std::string str
    );

private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
    TextBox             mTextBox;
};

#endif // INPUT_BOX_H