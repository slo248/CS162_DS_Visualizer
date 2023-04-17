#include "TextBox.h"

TextBox::TextBox(sf::Font *font, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &bgColor, const sf::Color &textColor, const float &charSize):
    isSelected(true), limit(20)
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

void TextBox::update(sf::Time dt)
{
    timer += dt;
    if(timer.asSeconds() > 1.0f){
        timer = sf::Time::Zero;
        if(isSelected){
            if(str.size() < limit)
                str += '_';
            else
                str = str.substr(0, limit);
        }
        else
            str = str.substr(0, limit);
        text.setString(str);
    }
}

void TextBox::draw(sf::RenderWindow *window)
{
    window->draw(box);
    window->draw(text);
}
