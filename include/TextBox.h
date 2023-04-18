#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "Global.h"

class TextBox: public sf::Drawable
{
public:
    TextBox(
        sf::Font* font,
        sf::Vector2f position
    );
    
    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
    std::string         mStr;

    bool                mIsFocus;
};

#endif // TEXT_BOX_H