#include <TextBox.hpp>

TextBox::TextBox(sf::Font &font, const std::string &text, const sf::Color& color)
{
    mText.setFont(font);
    mText.setString(text);
    mText.setFillColor(color);

    sf::FloatRect bounds=mText.getLocalBounds();
    mText.setOrigin(bounds.width/2,bounds.height/2);
}

void TextBox::drawCurrent(sf::RenderTarget &target, sf::RenderStates &states) const
{
    target.draw(mText,states);
}
