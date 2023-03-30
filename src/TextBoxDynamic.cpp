#include "TextBoxDynamic.hpp"

TextBoxDynamic::TextBoxDynamic(int size, sf::Color color, bool sel)
{
    mTextBox.setCharacterSize(size);
    mTextBox.setColor(color);
    mIsSelected=sel;
}

void TextBoxDynamic::deleteLastChar()
{
    std::string a=mText.str();
    if(!a.empty()){
        a.pop_back();
        mText.str("");
        mText<<a;
    }

    mTextBox.setString(mText.str()+'|');
}
