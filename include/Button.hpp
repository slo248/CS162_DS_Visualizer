#pragma once

#include <SceneNode.hpp>
#include <SFML/Graphics.hpp>

namespace ButtonConfig{
    const sf::Color     BG_COLOR=sf::Color(sf::Uint8(192),sf::Uint8(192),sf::Uint8(192),sf::Uint8(255));
    const sf::Color     BG_COLOR_HOVER=sf::Color(sf::Uint8(128),sf::Uint8(128),sf::Uint8(128),sf::Uint8(255));
    const sf::Color     TEXT_COLOR=sf::Color::Black;
    const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(100.f,300.f);
    const sf::Vector2f  DEFAULT_SIZE=sf::Vector2f(70.f,50.f);
}

class Button: public SceneNode
{
public:
    Button(
        sf::Font& font, 
        const std::string& text, 
        sf::Vector2f position=ButtonConfig::DEFAULT_POSITION, 
        sf::Vector2f size=ButtonConfig::DEFAULT_SIZE, 
        sf::Color background_color=ButtonConfig::BG_COLOR
    );

    virtual int     getCategory() const;

private:
    void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void        updateCurrent(sf::Time dt);
};