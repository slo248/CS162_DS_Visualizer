#include "TextBox.hpp"

TextBox::TextBox(sf::Font &font, sf::Vector2f pos, sf::Color color, float size, bool sel)
{
    mTextBox.setFont(font);
    mTextBox.setPosition(pos);
    mTextBox.setCharacterSize(size);
    mTextBox.setFillColor(color);
    mIsSelected=sel;
    if(sel)
        mTextBox.setString("|");
    else
        mTextBox.setString("");
}

void TextBox::deleteLastChar()
{
    std::string a=mText.str();
    if(!a.empty()){
        a.pop_back();
        mText.str("");
        mText<<a;
    }
}

void TextBox::inputLogic(int charTyped)
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

void TextBox::setLimit(bool flag, int lim)
{
    mHasLimit=flag;
    mLimit=lim;
}

void TextBox::setSelected(bool sel)
{
    mIsSelected=sel;
    if(!sel) mTextBox.setString(mText.str());
}

void TextBox::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mTextBox,states);
}

void TextBox::updateCurrent(sf::Time dt)
{
}

void TextBox::handleEvent(sf::Event event)
{
    if(!mIsSelected) return;
    int charTyped=event.text.unicode;
    if(charTyped>=128) return;
    if(mHasLimit && mText.str().size()>=mLimit){
        if(charTyped==DELETE_KEY)
            deleteLastChar();
    }
    else inputLogic(charTyped);
}

int TextBox::getCategory() const
{
    return Category::TextBox;
}
