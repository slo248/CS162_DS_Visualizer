#include "App.h"
#include "Config.h"
#include "Random.h"

using namespace Config::Window;

App::App():
    window(
        sf::VideoMode(WIDTH, HEIGHT),
        TITLE,
        STYLE,
        SETTINGS
    )
{
    window.setFramerateLimit(FPS);

    if (!cons.loadFromFile("media/font/consola.ttf"))
    {
        std::cout << "Error loading consola.ttf" << std::endl;
    }
    if (!sanf.loadFromFile("media/font/SFProDisplay.ttf"))
    {
        std::cout << "Error loading SFProDisplay.ttf" << std::endl;
    }
    if (!bgImage.loadFromFile("media/image/bg.jpg"))
    {
        std::cout << "Error loading bg.jpg" << std::endl;
    }
    bgSprite.setTexture(bgImage);
    bgSprite.setScale(
        (float)WIDTH/bgImage.getSize().x,
        (float)HEIGHT/bgImage.getSize().y
    );

    sll=new SLL(&window,&sanf,&cons,FPS,figure.circle,figure.arrow);
    sllControl=new SLL_Control(&sanf,window.getView().getSize());
}

App::~App()
{
    if(sll) delete sll;
    if(sllControl) delete sllControl;
}

void App::processInput()
{
    sllControl->handleRealTimeInput(&window);

    sf::Event event;
    while (window.pollEvent(event)){
        // sll->handleEvent(event);
        sllControl->handleEvent(event,&window);
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void App::update()
{
    sllControl->update(1.0f/FPS);

    Command cmd;
    bool flag=sllControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            sll->pause();
            break;
        case -3: // play
            sll->play();
            break;
        case -4: // prev
            sll->prevStep();
            break;
        case -5: // next
            sll->nextStep();
            break;
    }

    if(sll->isDoneAllSteps() && flag)
        switch (cmd.option)
        {                  
            case 0: // Create
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        sll->empty();
                        break;
                    case 1: // Manual
                        sll->manual(cmd.list);
                        sll->makeList();
                        break;
                    case 2: // Random
                        sll->randomList(getRand(1,10));
                        sll->makeList();
                        break;
                    case 3: // Random fixed size
                        sll->randomList(cmd.input1);
                        sll->makeList();
                        break;
                }
                break;
            case 1: // Insert
                switch (cmd.suboption)
                {
                    case 0: // Front
                        sll->insertFront(cmd.input1);
                        break;
                    case 1: // Back
                        sll->insertBack(cmd.input1);
                        break;
                    case 2: // Middle
                        sll->insertMiddle(cmd.input1,cmd.input2);
                        break;
                }
                break;
            case 2: // Search
                sll->search(cmd.input1);
                break;
            case 3: // Update
                sll->update(cmd.input1,cmd.input2);
                break;
            case 4: // Delete
                switch (cmd.suboption)
                {
                    case 0: // First
                        sll->deleteFirst();
                        break;
                    case 1: // Last
                        sll->deleteLast();
                        break;
                    case 2: // Middle
                        sll->deleteMiddle(cmd.input1);
                        break;
                }
                break;
        }
}

void App::draw()
{
    window.clear();
    window.draw(bgSprite);
    window.draw(*sllControl);
    sll->draw();
    window.display();
}

void App::run()
{
    sll->randomList(4);
    sll->makeList();
    while (window.isOpen())
    {
        processInput();
        update();
        draw();
    }
}
