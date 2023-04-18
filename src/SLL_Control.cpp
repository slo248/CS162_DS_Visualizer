#include "SLL_Control.h"
#include "Config.h"

SLL_Control::SLL_Control(sf::Font *font): 
    mFont(font), curOption(-1), curSuboption(-1)
{
    genOptions();
    genSuboptions();
}

void SLL_Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &option : options)
        target.draw(option, states);
}

void SLL_Control::genOptions()
{
    options.push_back(Button(mFont, &btnSprite, "Create", sf::Vector2f(0, 400+0*Config::Button::HEIGHT)));
    options.push_back(Button(mFont, &btnSprite, "Insert", sf::Vector2f(0, 400+1*Config::Button::HEIGHT)));
    options.push_back(Button(mFont, &btnSprite, "Search", sf::Vector2f(0, 400+2*Config::Button::HEIGHT)));
    options.push_back(Button(mFont, &btnSprite, "Update", sf::Vector2f(0, 400+3*Config::Button::HEIGHT)));
    options.push_back(Button(mFont, &btnSprite, "Delete", sf::Vector2f(0, 400+4*Config::Button::HEIGHT)));
}

void SLL_Control::genSuboptions()
{
    suboption.push_back(std::vector<std::string>{"Empty","User defined list","Random"});
    suboption.push_back(std::vector<std::string>{"i=0 (Head), specify v=","i=N (After Tail), specify v","specify both i in [1,N-1] and v:"});
    suboption.push_back(std::vector<std::string>{"Specify v="});
    suboption.push_back(std::vector<std::string>{"Specify i in [1,N] and v="});
    suboption.push_back(std::vector<std::string>{"i=0 (Head)","i=N-1 (Tail)","specify i in [1,N-2]"});
}
