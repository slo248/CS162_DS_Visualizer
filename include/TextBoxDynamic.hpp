#pragma once

#include <string>
#include <SceneNode.hpp>

class TextBoxDynamic: public SceneNode
{
    private:
        sf::Text                mTextBox;
        std::ostringstream      mText;
        bool                    mIsSelected;
        bool                    mHasLimit;
        int                     mLimit;
};