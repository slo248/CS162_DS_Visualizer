#include "RectText.h"
#include "Config.h"

using namespace Config::Button;

RectText::RectText(sf::Font *font, sf::Texture *bgTexture, std::string str, sf::Vector2f position)
{
    mRect.setTexture(*bgTexture);
    mRect.setPosition(position);
    mRect.setColor(BG_COLOR);
    {
        sf::FloatRect rectRect = mRect.getLocalBounds();
        mRect.setOrigin(
            rectRect.left,
            rectRect.top
        );
    }

    mText.setFont(*font);
    mText.setCharacterSize(CHAR_SIZE);
    mText.setFillColor(TEXT_COLOR);
    setString(str);
}

void RectText::setString(std::string str)
{
    mText.setString(str);
    {
        sf::FloatRect textRect = mText.getLocalBounds();
        mText.setOrigin(
            textRect.left + textRect.width/2.0f, 
            textRect.top  + textRect.height/2.0f
        );
    }
    mText.setPosition(
        mRect.getLocalBounds().width/2.0f,
        mRect.getLocalBounds().height/2.0f
    );
}

void RectText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    states.transform *= mRect.getTransform();
    target.draw(mText, states);
}
