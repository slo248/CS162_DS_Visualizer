#include <Button.hpp>

Button::Button(sf::Font &font, const std::string &text, sf::Vector2f position, sf::Vector2f size, sf::Color background_color)
{
    mBackground.setSize(size);
    mBackground.setFillColor(background_color);
    mBackground.setPosition(position);

    mText.setFont(font);
    mText.setString(text);
    mText.setCharacterSize(ButtonConfig::CHARACTER_SIZE);
    mText.setFillColor(ButtonConfig::TEXT_COLOR);

    sf::FloatRect textRect = mText.getLocalBounds();
    mText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    mText.setPosition(position + size / 2.f);
}

int Button::getCategory() const
{
    return Category::Button;
}

void Button::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mBackground, states);
    states.transform *= getTransform();
    target.draw(mText, states);
}

void Button::updateCurrent(sf::Time dt)
{
}
