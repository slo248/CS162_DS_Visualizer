#include <Button.hpp>

Button::Button(sf::Font &font, const std::string &text, sf::Vector2f position, sf::Vector2f size, sf::Color background_color)
{
    
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
