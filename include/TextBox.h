#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "HNeed.h"

namespace TextBoxConfig
{
    const sf::Vector2f      SIZE(100, 50);
    const sf::Vector2f      POSITION(200, 300);
    const sf::Color         BG_COLOR(Colors::BLUE);
    const sf::Color         TEXT_COLOR(Colors::BLACK);
    const float             CHAR_SIZE(22);
    const float             BLINK_TIME(0.5f);
    const int               LIMIT(7);
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
        const float&            charSize = TextBoxConfig::CHAR_SIZE,
        const int&              limit = TextBoxConfig::LIMIT
    );

    bool                    isMouseOver(sf::RenderWindow* window);
    void                    setSelect(bool flag);
    void                    handleInput(char c);
    void                    update(float dt);
    void                    draw(sf::RenderWindow* window);
    int                     getValue();
    void                    setPosition(const sf::Vector2f& position);

private:
    sf::RectangleShape      box;
    sf::Text                text;
    std::string             str;

    bool                    flag;
    float                   timer;
    bool                    isSelected;
    int                     limit;
};

#endif // TEXT_BOX_H