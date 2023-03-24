#include <TextBox.hpp>

TextBox::TextBox(sf::Font &font, const std::string &text, sf::Color color)
{
    mText.setFont(font);
    mText.setString(text);
    mText.setColor(color);
}
