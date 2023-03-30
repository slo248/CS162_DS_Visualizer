#include "TextBoxDynamic.hpp"

TextBoxDynamic::TextBoxDynamic(int size, sf::Color color, bool sel)
{
    mTextBox.setCharacterSize(size);
    mTextBox.setColor(color);
    mIsSelected=sel;
    if(sel)
        mTextBox.setString("|");
    else
        mTextBox.setString("");
}

void TextBoxDynamic::deleteLastChar()
{
    std::string a=mText.str();
    if(!a.empty()){
        a.pop_back();
        mText.str("");
        mText<<a;
    }
}

void TextBoxDynamic::inputLogic(int charTyped)
{
    switch (charTyped){
        case DELETE_KEY:
            deleteLastChar();
            break;
        case ENTER_KEY:
            break;
        case ESCAPE_KEY:
            break;
        default:
            mText<<static_cast<char>(charTyped);
    }

    mTextBox.setString(mText.str()+'|');
}

void TextBoxDynamic::setFont(sf::Font &font)
{
    mTextBox.setFont(font);
}

void TextBoxDynamic::setPosition(sf::Vector2f pos)
{
    mTextBox.setPosition(pos);
}

void TextBoxDynamic::setLimit(bool flag, int lim)
{
    mHasLimit=flag;
    mLimit=lim;
}

void TextBoxDynamic::setSelected(bool sel)
{
    mIsSelected=sel;
    if(!sel) mTextBox.setString(mText.str());
}
