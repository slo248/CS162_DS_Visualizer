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

int TextBox::getValue()
{
    return std::stoi(mStr);
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

void TextBox::setPosition(sf::Vector2f position)
{
    mRect.setPosition(position);
    mText.setPosition(
        position.x + 10.f,
        position.y + HEIGHT / 2.0f
    );
}

bool TextBox::changeFocus(sf::RenderWindow *window)
{
    sf::Vector2f mousePos = window->mapPixelToCoords(
        sf::Mouse::getPosition(*window)
    );
    mIsFocus=mRect.getGlobalBounds().contains(mousePos);
    return mIsFocus;
}

void TextBox::handleKeyInput(sf::Keyboard::Key key)
{
    if(!mIsFocus) return;

    if(key==sf::Keyboard::Backspace){
        if(!mStr.empty()) mStr.pop_back();
    }
    else if(mStr.length()<LIMIT)
    {
        if(sf::Keyboard::Num0<=key && key<=sf::Keyboard::Num9)
            mStr.push_back(key-sf::Keyboard::Num0+'0');
        else if(sf::Keyboard::Numpad0<=key && key<=sf::Keyboard::Numpad9)
            mStr.push_back(key-sf::Keyboard::Numpad0+'0');
    }

    mText.setString(mStr);
}

void TextBox::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
                changeFocus(window);
            break;
        case sf::Event::KeyPressed:
            handleKeyInput(event.key.code);
            break;
    }
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    target.draw(mText, states);
}
