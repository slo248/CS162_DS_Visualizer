#ifndef BUTTON_H
#define BUTTON_H

#include "HNeed.h"

class Button:
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{
public:
    enum Type{
        NONE,
        CREATE,
        EMPTY,
        RANDOM,
        LOAD_FROM_FILE,
        INSERT,
        UPDATE,
        SEARCH,
        DELETE
    };

    Button(sf::Font* font, std::string str, sf::Vector2f size, sf::Color bgColorNormal, sf::Color bgColorHit, sf::Color textColor);
    ~Button();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool isMouseOver(sf::RenderWindow* window);
    void update(sf::RenderWindow* window);
    sf::Vector2f getSize();
private:
    sf::RectangleShape* rect;
    sf::Text* text;
    sf::Color bgColorNormal;
    sf::Color bgColorHit;
};

#endif // BUTTON_H