#include "TextBox.h"

TextBox::TextBox(sf::Font *font, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &bgColor, const sf::Color &textColor, const float &charSize):
    isSelected(true), limit(1e9)
{
    box.setSize(size);
    box.setPosition(position);
    box.setFillColor(bgColor);

    text.setFont(*font);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    text.setPosition(
        position.x + 3.f,
        position.y + 0.05f * size.y
    );
}

void TextBox::draw(sf::RenderWindow *window)
{
    window->draw(box);
    window->draw(text);
}
