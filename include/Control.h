#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"
#include "TextBox.h"
#include <queue>

class Control
{
public: 
    Control(sf::Font* font);

    void    handleEvent(sf::Event& event, sf::RenderWindow* window);
    void    handleRealTimeInput(sf::RenderWindow* window);
    int     getCommand();

protected:
    int curOption;
    int curSuboption;
    std::queue<int> command;

    std::vector<Button> options;
    std::vector<std::vector<std::string>> suboption;
    sf::Texture  btnTexture;
    sf::Texture  bgSuboptionTexture;
    sf::Sprite   bgSuboptionSprite;
    sf::Font*    mFont;

    TextBox      textBox;
};

#endif // CONTROL_H