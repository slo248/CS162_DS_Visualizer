#include "Control.h"

Control::Control(sf::Font* font):
    curOption(-1),
    curSuboption(-1),
    mFont(font)
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
}

void Control::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
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

int Control::getCommand()
{
    if(command.empty()) return -1;
    int cmd=command.front();
    command.pop();
    return cmd;
}
