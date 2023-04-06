#pragma once

#include <sstream>
#include <SceneNode.hpp>

const int DELETE_KEY   =8;
const int ENTER_KEY    =13;
const int ESCAPE_KEY   =27;

class TextBox: public SceneNode
{
    public:
        TextBox(
            sf::Font &font,
            sf::Vector2f pos,
            sf::Color color=sf::Color::Black,
            float size=23.f,
            bool sel=true
        );
        void                    setLimit(bool flag, int lim=0);
        void                    setSelected(bool sel);
        void                    handleEvent(sf::Event event);
        unsigned int            getCategory() const;

    private:
        sf::Text                mTextBox;
        std::ostringstream      mText;
        bool                    mIsSelected;
        bool                    mHasLimit;
        int                     mLimit;
    
    private:
        void            deleteLastChar();
        void            inputLogic(int charTyped);
        void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);

};