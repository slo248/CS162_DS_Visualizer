#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "HNeed.h"

namespace TextBoxConfig
{
    const sf::Vector2f      SIZE(400, 100);
    const sf::Vector2f      POSITION(200, 200);
    const sf::Color         BG_COLOR(Colors::BLUE);
    const sf::Color         TEXT_COLOR(Colors::BLACK);
    const float             CHAR_SIZE(20);
}

class TextBox
{
public:
    TextBox(
        sf::Font*               font,
        const sf::Vector2f&     size = TextBoxConfig::SIZE,
        const sf::Vector2f&     position = TextBoxConfig::POSITION,
        const sf::Color&        bgColor = TextBoxConfig::BG_COLOR,
        const sf::Color&        textColor = TextBoxConfig::TEXT_COLOR,
        const float&            charSize = TextBoxConfig::CHAR_SIZE
    );

private:
    sf::RectangleShape      box;
    sf::Text                text;
    std::string             str;

    bool                    isSelected;
    int                     limit;
};

#endif // TEXT_BOX_H