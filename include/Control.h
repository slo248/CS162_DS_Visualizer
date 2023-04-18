#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"
#include <queue>

class Control
{
public: 
    Control();

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
};

#endif // CONTROL_H