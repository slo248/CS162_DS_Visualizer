#include <TextBoxFixed.hpp>

TextBoxFixed::TextBoxFixed(sf::Font &font, const std::string &text, const sf::Color& color, float size)
{
    mText.setFont(font);
    mText.setString(text);
    mText.setFillColor(color);
    mText.setCharacterSize(size);

    sf::FloatRect bounds=mText.getLocalBounds();
    mText.setOrigin(bounds.width/2,bounds.height/2);
}

void TextBoxFixed::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mText,states);
}
