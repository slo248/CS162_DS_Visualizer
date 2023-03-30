#pragma once

#include <sstream>
#include <SceneNode.hpp>

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
};