#ifndef RECT_TEXT_H
#define RECT_TEXT_H

#include "Global.h"

class RectText : 
    public sf::Transformable,
    public sf::Drawable
{
public:
    RectText(
        sf::Font*       font,
        sf::Texture*    bgTexture,
        std::string     str,
        sf::Vector2f    position
    );

    void setString(std::string str);
    virtual sf::FloatRect getLocalBounds() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    sf::Sprite     mRect;
    sf::Text       mText;
};

#endif // RECT_TEXT_H