#ifndef APP_H
#define APP_H

#include "Global.h"
#include "Figure.h"

#include "SLL.h"
#include "SLL_Control.h"

#include "Stack.h"
#include "Stack_Control.h"

class App
{
public:
    App();
    ~App();

    // main loop
    void processInput();
    void update();
    void draw();
    //

    void SLL_Update();
    void Stack_Update();

    void run();

private:
    sf::RenderWindow    window;
    sf::Font            cons, sanf;
    sf::Texture         bgImage;
    sf::Sprite          bgSprite;
    Figure              figure;

    SLL*                sll;
    SLL_Control*        sllControl;

    Stack*              stack;
    Stack_Control*      stackControl;
};

#endif // APP_H