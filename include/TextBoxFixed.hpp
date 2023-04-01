#pragma once

#include <string>
#include <SceneNode.hpp>

const sf::Color         CHAR_COLOR=sf::Color::Black;
const std::string       DEFAULT_TEXT="hello";
const float             DEFAULT_SIZE=23;

class TextBoxFixed: public SceneNode
{
    public:
        TextBoxFixed(
            sf::Font& font,
            const std::string& text=DEFAULT_TEXT,
            const sf::Color& color=CHAR_COLOR,
            float size=DEFAULT_SIZE
        );

        int             getCategory() const;

    private:
        sf::Text            mText;

    private:
        void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
};