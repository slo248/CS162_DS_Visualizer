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
    
    int  getValue();
    void update(float dt);
    bool changeFocus(sf::RenderWindow* window);
    void handleKeyInput(sf::Keyboard::Key key);
    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
    std::string         mStr;

    bool                mIsFocus;
    float               mTime;
};

#endif // TEXT_BOX_H