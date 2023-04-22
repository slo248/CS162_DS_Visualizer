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
    ),
    sll(nullptr),
    sllControl(nullptr),
    stack(nullptr),
    stackControl(nullptr)
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

    // sll=new SLL(&window,&sanf,&cons,FPS,figure.circle,figure.arrow);
    // sllControl=new SLL_Control(&sanf,window.getView().getSize());

    // stack=new Stack(&window,&sanf,&cons,FPS,figure.circle,figure.arrow);
    // stackControl=new Stack_Control(&sanf,window.getView().getSize());

    queue=new Queue(&window,&sanf,&cons,FPS,figure.circle,figure.arrow);
    queueControl=new Queue_Control(&sanf,window.getView().getSize());
}

App::~App()
{
    if(sll){ 
        delete sll;
        delete sllControl;
    }

    if(stack){
        delete stack;
        delete stackControl;
    }

    if(queue){
        delete queue;
        delete queueControl;
    }
}

void App::processInput()
{
    if(sllControl) sllControl->handleRealTimeInput(&window);
    if(stackControl) stackControl->handleRealTimeInput(&window);
    if(queueControl) queueControl->handleRealTimeInput(&window);

    sf::Event event;
    while (window.pollEvent(event)){
        if(sllControl) sllControl->handleEvent(event,&window);
        if(stackControl) stackControl->handleEvent(event,&window);
        if(queueControl) queueControl->handleEvent(event,&window);
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
    if(sll) SLL_Update();
    if(stack) Stack_Update();
    if(queue) Queue_Update();
}

void App::draw()
{
    window.clear();
    window.draw(bgSprite);
    if(sll){ 
        sll->draw();
        window.draw(*sllControl);
    }
    if(stack){ 
        stack->draw();
        window.draw(*stackControl);
    }
    if(queue){ 
        queue->draw();
        window.draw(*queueControl);
    }
    window.display();
}

void App::SLL_Update()
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
        case -6: // go to begin
            sll->goToBegin();
            break;
        case -7: // go to end
            sll->goToEnd();
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

void App::Stack_Update()
{
    stackControl->update(1.0f/FPS);

    Command cmd;
    bool flag=stackControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            stack->pause();
            break;
        case -3: // play
            stack->play();
            break;
        case -4: // prev
            stack->prevStep();
            break;
        case -5: // next
            stack->nextStep();
            break;
        case -6: // go to begin
            stack->goToBegin();
            break;
        case -7: // go to end
            stack->goToEnd();
            break;
    }

    if(stack->isDoneAllSteps() && flag)
        switch (cmd.option)
        {
            case 0:
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        stack->empty();
                        break;
                    case 1: // Manual
                        stack->manual(cmd.list);
                        stack->makeList();
                        break;
                    case 2: // Random
                        stack->randomList(getRand(1,7));
                        stack->makeList();
                        break;
                    case 3: // Random fixed size
                        stack->randomList(cmd.input1);
                        stack->makeList();
                        break;
                }
                break;
            case 1: // Peek
                stack->peek();
                break;
            case 2: // Push
                stack->push(cmd.input1);
                break;
            case 3: // Pop
                stack->pop();
                break;
        }
}

void App::Queue_Update()
{
    queueControl->update(1.0f/FPS);

    Command cmd;
    bool flag=queueControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            queue->pause();
            break;
        case -3: // play
            queue->play();
            break;
        case -4: // prev
            queue->prevStep();
            break;
        case -5: // next
            queue->nextStep();
            break;
        case -6: // go to begin
            queue->goToBegin();
            break;
        case -7: // go to end
            queue->goToEnd();
            break;
    }

    if(queue->isDoneAllSteps() && flag)
        switch (cmd.option)
        {
            case 0:
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        queue->empty();
                        break;
                    case 1: // Manual
                        queue->manual(cmd.list);
                        queue->makeList();
                        break;
                    case 2: // Random
                        queue->randomList(getRand(1,7));
                        queue->makeList();
                        break;
                    case 3: // Random fixed size
                        queue->randomList(cmd.input1);
                        queue->makeList();
                        break;
                }
                break;
            case 1: // Peek
                switch (cmd.suboption)
                {
                    case 0: // Front
                        queue->peekFront();
                        break;
                    case 1: // Back
                        queue->peekBack();
                        break;
                }
                break;
        }
}

void App::run()
{
    if(sll){
        sll->randomList(4);
        sll->makeList();
    }

    if(stack){
        stack->randomList(4);
        stack->makeList();
    }

    if(queue){
        queue->randomList(4);
        queue->makeList();
    }

    while (window.isOpen())
    {
        processInput();
        update();
        draw();
    }
}
