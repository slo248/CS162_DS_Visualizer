#pragma once

#include <string>
#include <SceneNode.hpp>

const sf::Color         CHAR_COLOR=sf::Color::Red;
const std::string       DEFAULT_TEXT="hello";
const sf::Vector2f      DEFAULT_SIZE=sf::Vector2f(100.f,100.f);

class TextBox: public SceneNode
{
    public:

    private:
        sf::Text            mText;
};