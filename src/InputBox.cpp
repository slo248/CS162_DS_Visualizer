#include "InputBox.h"
#include "Config.h"

using namespace Config::InputBox;

InputBox::InputBox(sf::Font *font, sf::Vector2f position, std::string str):
    mRect(sf::Vector2f(WIDTH,HEIGHT)),
    mText(str, *font, 20),
    mTextBox(font, position)
{
    mRect.setFillColor(BG_COLOR);
    mText.setFillColor(TEXT_COLOR); 
    setPosition(position);   
}

void InputBox::setPosition(sf::Vector2f position)
{
    mRect.setPosition(position);
    mText.setPosition(
        position.x + 10.f,
        position.y + HEIGHT / 2.0f
    );
    mTextBox.setPosition(sf::Vector2f(
        position.x + WIDTH - (Config::TextBox::WIDTH + 10.f),
        position.y + HEIGHT / 2.0f
    ));
}

void InputBox::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

void InputBox::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    mTextBox.handleEvent(event, window);
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect);
    target.draw(mText);
    target.draw(mTextBox);
}