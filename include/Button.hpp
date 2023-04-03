#pragma once

#include <SceneNode.hpp>
#include <SFML/Graphics.hpp>

namespace ButtonConfig{
    const sf::Color     BG_COLOR=sf::Color(sf::Uint8(192),sf::Uint8(192),sf::Uint8(192),sf::Uint8(255));
    const sf::Color     BG_COLOR_HOVER=sf::Color(sf::Uint8(128),sf::Uint8(128),sf::Uint8(128),sf::Uint8(255));
    const sf::Color     TEXT_COLOR=sf::Color::Black;
    const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(100.f,300.f);
    const sf::Vector2f  DEFAULT_SIZE=sf::Vector2f(190.f,60.f);
    const float         CHARACTER_SIZE=23.f;
    const float         THICK=3.f;
}

class Button: public SceneNode
{
public:
    Button(
        sf::Font& font, 
        Category::Type type,
        sf::Vector2f position=ButtonConfig::DEFAULT_POSITION, 
        sf::Vector2f size=ButtonConfig::DEFAULT_SIZE, 
        sf::Color background_color=ButtonConfig::BG_COLOR
    );

    virtual int         getCategory() const;
    bool                isMouseOver(sf::Vector2f mouse_pos);
    bool                isMousePressed(sf::Vector2f mouse_pos);
    void                setBackGroundColor(sf::Color color);

private:
    sf::RectangleShape  mBackground;
    sf::Text            mText;
    Category::Type      mType;

    void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void        updateCurrent(sf::Time dt);
};