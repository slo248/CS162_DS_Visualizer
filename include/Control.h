#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"

class Control
{
public: 
    Control();

    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void handleRealTimeInput(sf::RenderWindow* window);

protected:
    int curOption;
    int curSuboption;

    std::vector<Button> options;
    std::vector<std::vector<std::string>> suboption;
    sf::Texture  btnSprite;
    sf::Texture  bgSprite;
};

#endif // CONTROL_H