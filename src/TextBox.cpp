#include "TextBox.h"
#include "Config.h"

using namespace Config::TextBox;

TextBox::TextBox(sf::Font *font, sf::Vector2f position): mStr("1")
{
    mRect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    mRect.setFillColor(BG_COLOR);
    mRect.setPosition(position);

    mText.setFont(*font);
    mText.setCharacterSize(CHAR_SIZE);
    mText.setString(mStr);
    {
        sf::FloatRect rect = mText.getLocalBounds();
        mText.setOrigin(
            rect.left, 
            rect.top + rect.height / 2.0f
        );
    }
    mText.setFillColor(TEXT_COLOR);
    mText.setPosition(
        position.x + 10.f,
        position.y + HEIGHT / 2.0f
    );
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    target.draw(mText, states);
}
