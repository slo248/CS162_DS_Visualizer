#include "Button.h"

Button::Button(sf::Font *font, std::string str,sf::Vector2f size, sf::Color bgColorNormal, sf::Color bgColorHit ,sf::Color textColor):
    bgColorNormal(bgColorNormal),
    bgColorHit(bgColorHit)
{
    rect=new sf::RectangleShape(size);
    rect->setFillColor(bgColorNormal);
    rect->setOutlineThickness(THICK);
    rect->setOutlineColor(Colors::BLACK);
    {
        sf::FloatRect bounds=rect->getLocalBounds();
        rect->setOrigin(bounds.left,bounds.top);
    }

    text=new sf::Text(str, *font, 23);
    text->setFillColor(textColor);
    {
        sf::FloatRect bounds=text->getLocalBounds();
        text->setOrigin(
            bounds.left+bounds.width/2,
            bounds.top+bounds.height/2
        );
    }
    text->setPosition(THICK+size.x/2.f, THICK+size.y/2.f);
}

Button::~Button()
{
    delete rect;
    delete text;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform*=getTransform();
    target.draw(*rect, states);
    target.draw(*text, states);
}

bool Button::isMouseOver(sf::RenderWindow *window)
{
    sf::Vector2f mousePos=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds=rect->getGlobalBounds();
    return bounds.contains(mousePos);
}