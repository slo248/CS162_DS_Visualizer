#ifndef INPUT_BOX_H
#define INPUT_BOX_H

#include "TextBox.h"

class InputBox: public sf::Drawable
{
public:
    InputBox(
        sf::Font* font,
        sf::Vector2f position,
        std::string str
    );

    void update(float dt);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::RectangleShape  mRect;
    sf::Text            mText;
    TextBox             mTextBox;
};

#endif // INPUT_BOX_H