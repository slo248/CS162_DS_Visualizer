#include <Button.hpp>
#include <iostream>

Button::Button(sf::Font &font, ButtonType type, sf::Vector2f position, sf::Vector2f size, sf::Color background_color)
{
    mBackground.setSize(size);
    mBackground.setFillColor(background_color);
    mBackground.setPosition(position);
    mBackground.setOutlineThickness(ButtonConfig::THICK);
    mBackground.setOutlineColor(ButtonConfig::TEXT_COLOR);
    
    sf::FloatRect bounds = mBackground.getLocalBounds();
    mBackground.setOrigin(bounds.left, bounds.top);

    mText.setFont(font);

    switch (type){
        case ButtonType::Create:
            mText.setString("Create");
            break;
        case ButtonType::Insert:
            mText.setString("Insert");
            break;
        case ButtonType::Update:
            mText.setString("Update");
            break;
        case ButtonType::Remove:
            mText.setString("Remove");
            break;
    }

    mText.setCharacterSize(ButtonConfig::CHARACTER_SIZE);
    mText.setFillColor(ButtonConfig::TEXT_COLOR);

    sf::FloatRect textRect = mText.getLocalBounds();
    mText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    mText.setPosition(size / 2.f);
}

int Button::getCategory() const
{
    return Category::Button;
}

bool Button::isMouseOver(sf::Vector2f mouse_pos)
{
    sf::FloatRect bounds = mBackground.getGlobalBounds();
    return bounds.left<=mouse_pos.x && mouse_pos.x<=bounds.left+bounds.width
     && bounds.top<=mouse_pos.y && mouse_pos.y<=bounds.top+bounds.height;
}

void Button::setBackGroundColor(sf::Color color)
{
    mBackground.setFillColor(color);
}

void Button::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mBackground, states);
    states.transform *= mBackground.getTransform();
    target.draw(mText, states);
}

void Button::updateCurrent(sf::Time dt)
{
}
