#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "HNeed.h"

namespace TextBoxConfig
{
    const sf::Vector2f      SIZE(400, 100);
    const sf::Vector2f      POSITION(0, 0);
    const sf::Color         BG_COLOR(Colors::BLUE);
    const sf::Color         TEXT_COLOR(Colors::BLACK);
    const float             CHAR_SIZE(20);
}

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