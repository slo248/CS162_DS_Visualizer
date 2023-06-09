#include "RectText.h"
#include "Config.h"

using namespace Config::Button;

RectText::RectText(sf::Font *font, sf::Texture *bgTexture, std::string str, sf::Vector2f position, bool isCentered)
{
    mRect.setTexture(*bgTexture);
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

    if(isCentered) setCenter();
    setPosition(position);
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

void RectText::setCenter()
{
    sf::FloatRect bounds = getLocalBounds();
    setOrigin(
        bounds.left + bounds.width/2.0f,
        bounds.top  + bounds.height/2.0f
    );
}

sf::FloatRect RectText::getLocalBounds() const
{
    return mRect.getLocalBounds();
}

void RectText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mRect, states);
    states.transform *= mRect.getTransform();
    target.draw(mText, states);
}
