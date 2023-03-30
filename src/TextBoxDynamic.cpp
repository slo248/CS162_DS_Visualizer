#include "TextBoxDynamic.hpp"

TextBoxDynamic::TextBoxDynamic(int size, sf::Color color, bool sel)
{
    mTextBox.setCharacterSize(size);
    mTextBox.setColor(color);
    mIsSelected=sel;
}
