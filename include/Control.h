#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"

class Control
{
public: 
    Control();

protected:
    std::vector<Button> options;
    std::vector<std::vector<std::string>> suboption;
    sf::Texture  btnSprite;
    sf::Texture  bgSprite;
};

#endif // CONTROL_H