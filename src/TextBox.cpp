#include "TextBox.h"
#include "Config.h"

using namespace Config::TextBox;

TextBox::TextBox(sf::Font *font, sf::Vector2f position): 
    mStr("1"), mIsFocus(false), mTime(0)
{
    mRect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    mRect.setFillColor(BG_COLOR);
    mRect.setPosition(position);

    mText.setFont(*font);
    mText.setCharacterSize(CHAR_SIZE);
    mText.setString(mStr);
    {
        sf::FloatRect rect = mText.getLocalBounds();
        mText.setOrigin(
            rect.left, 
            rect.top + rect.height / 2.0f
        );
    }
    mText.setFillColor(TEXT_COLOR);
    mText.setPosition(
        position.x + 10.f,
        position.y + HEIGHT / 2.0f
    );
}

void TextBox::update(float dt)
{
    if(mIsFocus){
        mTime+=dt;
        if(mTime>CURSOR_BLINK_TIME){
            mTime=0;
            std::string cur=mText.getString();
            if(cur.empty()) mText.setString(cur+"_");
            else{
                if(cur.back()=='_') cur.pop_back();
                else cur.push_back('_');
                mText.setString(cur);
            }
        }
    }
    else mText.setString(mStr);
}

bool TextBox::changeFocus(sf::RenderWindow *window)
{
    sf::Vector2f mousePos = window->mapPixelToCoords(
        sf::Mouse::getPosition(*window)
    );
    mIsFocus=mRect.getGlobalBounds().contains(mousePos);
    return mIsFocus;
}

void TextBox::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
                changeFocus(window);
            break;
    }
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    target.draw(mText, states);
}
