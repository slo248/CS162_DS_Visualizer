#include "SLL_Control.h"
#include "Config.h"

SLL_Control::SLL_Control(sf::Font *font, sf::Vector2f windowSize): 
    Control(font)
{
    genOptions(windowSize);
    genSuboptions(windowSize);
    bgSuboptionSprite.setPosition(sf::Vector2f(
        btnTexture.getSize().x+10.f, 
        windowSize.y-5*btnTexture.getSize().y
    ));
}

void SLL_Control::genOptions(sf::Vector2f windowSize)
{
    options.push_back(Button(mFont, &btnTexture, "Create", sf::Vector2f(0, windowSize.y-5*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Insert", sf::Vector2f(0, windowSize.y-4*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Search", sf::Vector2f(0, windowSize.y-3*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Update", sf::Vector2f(0, windowSize.y-2*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Delete", sf::Vector2f(0, windowSize.y-1*btnTexture.getSize().y)));
}

void SLL_Control::genSuboptions(sf::Vector2f windowSize)
{
    suboption.push_back(std::vector<std::string>{"Empty","User defined list","Random"});
    suboption.push_back(std::vector<std::string>{"i=0 (Head), specify v=","i=N (After Tail), specify v","specify both i in [1,N-1] and v:"});
    suboption.push_back(std::vector<std::string>{"Specify v="});
    suboption.push_back(std::vector<std::string>{"Specify i in [1,N] and v="});
    suboption.push_back(std::vector<std::string>{"i=0 (Head)","i=N-1 (Tail)","specify i in [1,N-2]"});
}
