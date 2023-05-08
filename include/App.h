#ifndef APP_H
#define APP_H

#include "Global.h"
#include "Menu.h"

#include "SLL.h"
#include "SLL_Control.h"

#include "DLL.h"
#include "DLL_Control.h"

#include "CLL.h"
#include "CLL_Control.h"

#include "Stack.h"
#include "Stack_Control.h"

#include "Queue.h"
#include "Queue_Control.h"

#include "SArr.h"
#include "SArr_Control.h"

#include "DArr.h"
#include "DArr_Control.h"

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
    void CLL_Update();
    void Stack_Update();
    void Queue_Update();
    void SArr_Update();
    void DArr_Update();

    void run();

private:
    sf::RenderWindow    window;
    sf::Font            cons, sanf;
    sf::Texture         bgImage;
    sf::Sprite          bgSprite;

    State::Type         state;

    Menu*               menu;

    SArr*               sarr;
    SArr_Control*       sarrControl;

    DArr*               darr;
    DArr_Control*       darrControl;

    SLL*                sll;
    SLL_Control*        sllControl;

    DLL*                dll;
    DLL_Control*        dllControl;

    CLL*                cll;
    CLL_Control*        cllControl;

    Stack*              stack;
    Stack_Control*      stackControl;

    Queue*              queue;
    Queue_Control*      queueControl;
};

#endif // APP_H