#include "Button.h"
#include "Config.h"

using namespace Config::Button;

Button::Button(
    sf::Font*       font,
    sf::Texture*    bgTexture,
    std::string     str,
    sf::Vector2f    position
): RectText(font, bgTexture, str, position)
{
}

bool Button::isMouseOver(sf::RenderWindow *window)
{
    sf::Vector2f mousePos=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::Vector2f rectPos=mRect.getPosition();
    sf::FloatRect bounds=mRect.getLocalBounds();
    bool res=bounds.contains(mousePos.x-rectPos.x, mousePos.y-rectPos.y);
    if(res)
        mRect.setColor(BG_MOUSE_OVER);
    else
        mRect.setColor(BG_COLOR);
    return res;
}
