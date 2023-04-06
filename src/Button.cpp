#include <Button.hpp>
#include <iostream>

Button::Button(sf::Font &font, Category::Type type, sf::Vector2f position, sf::Vector2f size, sf::Color background_color):
    mType(type)
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
        case Category::Type::ButtonCreate:
            mText.setString("Create");
            break;
            case Category::Type::ButtonEmpty:
                mText.setString("Empty");
                break;
            case Category::Type::ButtonSetRandom:
                mText.setString("Random");
                break;
            case Category::Type::ButtonLoadFromFile:
                mText.setString("File");
                break;
        case Category::Type::ButtonInsert:
            mText.setString("Insert");
            break;
            case Category::Type::ButtonInsertFront:
                mText.setString("Front");
                break;
            case Category::Type::ButtonInsertBack:
                mText.setString("Back");
                break;
            case Category::Type::ButtonInsertMiddle:
                mText.setString("Middle");
                break;
        case Category::Type::ButtonUpdate:
            mText.setString("Update");
            break;
        case Category::Type::ButtonRemove:
            mText.setString("Remove");
            break;
        case Category::Type::ButtonSearch:
            mText.setString("Search");
            break;
    }

    mText.setCharacterSize(ButtonConfig::CHARACTER_SIZE);
    mText.setFillColor(ButtonConfig::TEXT_COLOR);

    sf::FloatRect textRect = mText.getLocalBounds();
    mText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    mText.setPosition(size / 2.f);
}

unsigned int Button::getCategory() const
{
    return mType;
}

bool Button::isMousePressed(sf::Vector2f mouse_pos)
{
    return isMouseOver(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
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
