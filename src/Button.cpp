#include "Button.h"
#include "Config.h"

using namespace Config::Button;

Button::Button(
    sf::Font*       font,
    sf::Texture*    bgTexture,
    std::string     str,
    sf::Vector2f    position,
    bool            isCentered
): RectText(font, bgTexture, str, position, isCentered)
{
}

bool Button::isMouseOver(sf::RenderWindow *window)
{
    sf::Vector2f mousePos=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::Vector2f rectPos=getPosition();
    sf::Vector2f origin=getOrigin();
    sf::FloatRect bounds=getLocalBounds();

    bool res=bounds.contains(mousePos.x-rectPos.x+origin.x, mousePos.y-rectPos.y+origin.y);
    if(res)
        mRect.setColor(BG_MOUSE_OVER);
    else
        mRect.setColor(BG_COLOR);
    return res;
}
