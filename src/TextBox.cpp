#include "TextBox.h"

using namespace TextBoxConfig;

const int DELETE_KEY = 8;
const int ESCAPE_KEY = 27;

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
    sf::FloatRect bounds=box.getLocalBounds();
    sf::Vector2f boxPos=box.getPosition();
    return bounds.contains(mousePos.x-boxPos.x, mousePos.y-boxPos.y);
}

void TextBox::setSelect(bool flag)
{
    isSelected = flag;
}

void TextBox::handleInput(char c)
{
    if(!isSelected || c>=128) return;

    if(c == DELETE_KEY){
        if(str.size() > 0)
            str.erase(str.size()-1);
    }
    else if(c==ESCAPE_KEY)
        isSelected=false;
    else if('0'<=c && c<='9' && str.size() < limit)
        str += c;
}

void TextBox::update(float dt)
{
    timer += dt;
    if(timer > BLINK_TIME){
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

int TextBox::getValue()
{
    return std::stoi(str);
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    box.setPosition(position);
    text.setPosition(
        position.x+3.f,
        position.y + box.getSize().y / 2.f
    );
}
