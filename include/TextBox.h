#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "HNeed.h"

class TextBox
{
public:
    TextBox();
    ~TextBox();

private:
    sf::RectangleShape      box;
    sf::Text                text;
    std::string             str;
};

#endif // TEXT_BOX_H