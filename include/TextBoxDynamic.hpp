#pragma once

#include <sstream>
#include <SceneNode.hpp>

const int DELETE_KEY   =8;
const int ENTER_KEY    =13;
const int ESCAPE_KEY   =27;

class TextBoxDynamic: public SceneNode
{
    public:
        TextBoxDynamic(int size, sf::Color color, bool sel);
    private:
        sf::Text                mTextBox;
        std::ostringstream      mText;
        bool                    mIsSelected;
        bool                    mHasLimit;
        int                     mLimit;
    
    private:
        void deleteLastChar();
};