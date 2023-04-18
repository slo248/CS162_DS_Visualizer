#include "Control.h"
#include "Config.h"

Control::Control(sf::Font* font):
    curOption(-1),
    curSuboption(-1),
    mFont(font),
    inputBox(nullptr),
    subOption(nullptr)
{
    if (!btnTexture.loadFromFile("media/image/button.png"))
    {
        std::cout << "Error loading btn.png" << std::endl;
    }
    if (!bgSuboptionTexture.loadFromFile("media/image/bgSuboption.png"))
    {
        std::cout << "Error loading bgSuboption.png" << std::endl;
    }
    bgSuboptionSprite.setTexture(bgSuboptionTexture);
    if(!suboptionTexture.loadFromFile("media/image/suboption.png"))
    {
        std::cout << "Error loading suboption.png" << std::endl;
    }
}

Control::~Control()
{
    if(inputBox) delete inputBox;
    if(subOption) delete subOption;
}

void Control::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    if(inputBox) inputBox->handleEvent(event,window);

    switch (event.type)
    {
        case sf::Event::MouseButtonReleased:
            if(event.mouseButton.button==sf::Mouse::Left)
            {
                for(int i=0;i<options.size();i++)
                {
                    if(options[i].isMouseOver(window))
                    {
                        curOption=i;
                        curSuboption=0;
                        loadSubOption(curOption);
                        command.push(i);
                        break;
                    }
                }                
            }
            break;
    }
}

void Control::handleRealTimeInput(sf::RenderWindow *window)
{
    for(Button& btn: options)
        btn.isMouseOver(window);
}

void Control::update(float dt)
{
    if(inputBox) inputBox->update(dt);
}

int Control::getCommand()
{
    if(command.empty()) return -1;
    int cmd=command.front();
    command.pop();
    return cmd;
}

void Control::loadSubOption(int option)
{
    if(subOption) delete subOption;
    subOption=new RectText(
        mFont,
        &suboptionTexture,
        suboption[option][curSuboption],
        sf::Vector2f(
            Config::Button::WIDTH+10,
            Config::Window::HEIGHT-Config::Button::HEIGHT*options.size()
        )
    );
}

void Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &option : options)
        target.draw(option, states);
    if(curSuboption!=-1)
        target.draw(bgSuboptionSprite, states);
    if(inputBox)
        target.draw(*inputBox, states);
    if(subOption)
        target.draw(*subOption, states);
}
