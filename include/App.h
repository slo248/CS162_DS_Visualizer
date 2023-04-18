#ifndef APP_H
#define APP_H

#include "Global.h"
#include "SLL_Control.h"
#include "SLL.h"
#include "Figure.h"

class App
{
public:
    App();

    // main loop
    void processInput();
    void draw();
    //

    void run();

private:
    sf::RenderWindow    window;
    sf::Font            cons, sanf;
    sf::Texture         bgImage;
    sf::Sprite          bgSprite;
    Figure              figure;

    SLL*                sll;
    SLL_Control*        sllControl;
};

#endif // APP_H