#ifndef APP_H
#define APP_H

#include "Global.h"
#include "Figure.h"
#include "Menu.h"

#include "SLL.h"
#include "SLL_Control.h"

#include "DLL.h"
#include "DLL_Control.h"

#include "Stack.h"
#include "Stack_Control.h"

#include "Queue.h"
#include "Queue_Control.h"

namespace State
{
    enum Type
    {
        MENU,
        DS,
        ALL,
    };
}

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
    void DLL_Update();
    void Stack_Update();
    void Queue_Update();

    void run();

private:
    sf::RenderWindow    window;
    sf::Font            cons, sanf;
    sf::Texture         bgImage;
    sf::Sprite          bgSprite;
    Figure              figure;

    State::Type         state;

    Menu*               menu;

    SLL*                sll;
    SLL_Control*        sllControl;

    DLL*                dll;
    DLL_Control*        dllControl;

    Stack*              stack;
    Stack_Control*      stackControl;

    Queue*              queue;
    Queue_Control*      queueControl;
};

#endif // APP_H