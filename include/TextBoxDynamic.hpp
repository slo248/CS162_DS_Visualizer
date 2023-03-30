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
        void                    setFont(sf::Font& font);
        void                    setPosition(sf::Vector2f pos);
        void                    setLimit(bool flag, int lim=0);
        void                    setSelected(bool sel);

    private:
        sf::Text                mTextBox;
        std::ostringstream      mText;
        bool                    mIsSelected;
        bool                    mHasLimit;
        int                     mLimit;
    
    private:
        void                    deleteLastChar();
        void                    inputLogic(int charTyped);
};