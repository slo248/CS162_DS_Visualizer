#pragma once

#include <string>
#include <SceneNode.hpp>

const sf::Color         CHAR_COLOR=sf::Color::Red;
const std::string       DEFAULT_TEXT="hello";
const float             DEFAULT_SIZE=23;

class TextBox: public SceneNode
{
    public:
        TextBox(
            sf::Font& font,
            const std::string& text=DEFAULT_TEXT,
            const sf::Color& color=CHAR_COLOR,
            float size=DEFAULT_SIZE
        );

        void drawCurrent(sf::RenderTarget& target,
                        sf::RenderStates states) const;
    private:
        sf::Text            mText;
};