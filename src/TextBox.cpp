#include "TextBox.h"

TextBox::TextBox(sf::Font *font, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &bgColor, const sf::Color &textColor, const float &charSize, const int &limit):
    isSelected(true), flag(true), str("1"), limit(limit)
{
    box.setSize(size);
    box.setPosition(position);
    box.setFillColor(bgColor);

    text.setFont(*font);
    text.setString(str);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);

    {
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(
            bounds.left,
            bounds.top + bounds.height / 2.f
        );
    }

    text.setPosition(
        position.x+3.f,
        position.y + size.y / 2.f
    );
}

bool TextBox::isMouseOver(sf::RenderWindow *window)
{
    sf::Vector2f mousePos=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds=box.getGlobalBounds();
    sf::Vector2f boxPos=box.getPosition();
    return bounds.contains(mousePos.x-boxPos.x, mousePos.y-boxPos.y);
}

void TextBox::setSelect(bool flag)
{
    isSelected = flag;
}

void TextBox::addChar(char c)
{
    if(str.size() < limit){
        str += c;
        text.setString(str);
    }
}

void TextBox::update(float dt)
{
    timer += dt;
    if(timer > 1.0f){
        timer = 0;
        text.setString(str);
        if(isSelected && flag && str.size() < limit)
            text.setString(str + "_");
        flag=!flag;
    }
}

void TextBox::draw(sf::RenderWindow *window)
{
    window->draw(box);
    window->draw(text);
}
