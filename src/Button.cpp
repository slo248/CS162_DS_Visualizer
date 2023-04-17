#include "Button.h"
#include "Config.h"

using namespace Config::Button;

Button::Button(
    sf::Font*       font,
    std::string     str,
    sf::Texture*    bgTexture,
    sf::Vector2f    position
)
{
    mRect.setTexture(*bgTexture);
    mRect.setPosition(position);
    mRect.setColor(BG_COLOR);

    mText.setFont(*font);
    mText.setString(str);
    mText.setCharacterSize(CHAR_SIZE);
    mText.setFillColor(TEXT_COLOR);
    {
        sf::FloatRect textRect = mText.getLocalBounds();
        mText.setOrigin(
            textRect.left + textRect.width/2.0f, 
            textRect.top  + textRect.height/2.0f
        );
    }
    mText.setPosition(
        position.x + mRect.getLocalBounds().width/2.0f,
        position.y + mRect.getLocalBounds().height/2.0f
    );
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect);
    target.draw(mText);
}
