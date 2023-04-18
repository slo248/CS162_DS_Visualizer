#include "Control.h"

Control::Control()
{
    if (!btnSprite.loadFromFile("media/image/button.png"))
    {
        std::cout << "Error loading btn.png" << std::endl;
    }
    if (!bgSprite.loadFromFile("media/image/bg.jpg"))
    {
        std::cout << "Error loading bg.png" << std::endl;
    }
}

void Control::handleRealTimeInput(sf::RenderWindow *window)
{
    for(Button& btn: options)
        btn.isMouseOver(window);
}
