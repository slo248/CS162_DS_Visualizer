#pragma once

#include <string>
#include <SceneNode.hpp>

const sf::Color         CHAR_COLOR=sf::Color::Red;
const std::string       DEFAULT_TEXT="hello";

class TextBox: public SceneNode
{
    public:
        TextBox(
            sf::Font& font,
            const std::string& text=DEFAULT_TEXT,
            sf::Color color=CHAR_COLOR
        );

        void drawCurrent(sf::RenderTarget& target,
                        sf::RenderStates& states) const;
    private:
        sf::Text            mText;
};