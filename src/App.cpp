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
    state(State::MENU),
    sarr(nullptr),
    sarrControl(nullptr),
    sll(nullptr),
    sllControl(nullptr),
    stack(nullptr),
    stackControl(nullptr),
    queue(nullptr),
    queueControl(nullptr),
    dll(nullptr),
    dllControl(nullptr),
    darr(nullptr),
    darrControl(nullptr)
{
    window.setFramerateLimit(FPS);

    if (!cons.loadFromFile("media/font/consola.ttf"))
    {
        std::cout << "Error loading consola.ttf" << std::endl;
    }
    if (!sanf.loadFromFile("media/font/SFProDisplay-Bold.ttf"))
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

    menu=new Menu(&sanf,window.getView().getSize());
}

App::~App()
{
    if(sarr){
        delete sarr;
        delete sarrControl;
    }

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

    if(dll){
        delete dll;
        delete dllControl;
    }

    delete menu;
}

void App::processInput()
{
    if(sarrControl) sarrControl->handleRealTimeInput(&window);
    if(sllControl) sllControl->handleRealTimeInput(&window);
    if(stackControl) stackControl->handleRealTimeInput(&window);
    if(queueControl) queueControl->handleRealTimeInput(&window);
    if(dllControl) dllControl->handleRealTimeInput(&window);
    if(darrControl) darrControl->handleRealTimeInput(&window);

    sf::Event event;
    while (window.pollEvent(event)){
        menu->handleEvent(event,&window);
        if(sarrControl) sarrControl->handleEvent(event,&window);
        if(sllControl) sllControl->handleEvent(event,&window);
        if(stackControl) stackControl->handleEvent(event,&window);
        if(queueControl) queueControl->handleEvent(event,&window);
        if(dllControl) dllControl->handleEvent(event,&window);
        if(darrControl) darrControl->handleEvent(event,&window);
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code==sf::Keyboard::Escape && state==State::DS){
                    state=State::MENU;
                    if(sll){
                        delete sll;
                        delete sllControl;
                        sll=nullptr;
                        sllControl=nullptr;
                    }
                    if(stack){
                        delete stack;
                        delete stackControl;
                        stack=nullptr;
                        stackControl=nullptr;
                    }
                    if(queue){
                        delete queue;
                        delete queueControl;
                        queue=nullptr;
                        queueControl=nullptr;
                    }
                    if(dll){
                        delete dll;
                        delete dllControl;
                        dll=nullptr;
                        dllControl=nullptr;
                    }
                    if(sarr){
                        delete sarr;
                        delete sarrControl;
                        sarr=nullptr;
                        sarrControl=nullptr;
                    }
                    if(darr){
                        delete darr;
                        delete darrControl;
                        darr=nullptr;
                        darrControl=nullptr;
                    }
                }
                break;
        }
    }
}

void App::update()
{
    if(state==State::MENU){
        int cmd=menu->getCommand();
        switch (cmd)
        {
            case DS::SLL:
                state=State::DS;
                sll=new SLL(&window,&sanf,&cons,FPS);
                sllControl=new SLL_Control(&sanf,window.getView().getSize());
                break;
            case DS::DLL:
                state=State::DS;
                dll=new DLL(&window,&sanf,&cons,FPS);
                dllControl=new DLL_Control(&sanf,window.getView().getSize());
                break;
            case DS::STACK:
                state=State::DS;
                stack=new Stack(&window,&sanf,&cons,FPS);
                stackControl=new Stack_Control(&sanf,window.getView().getSize());
                break;
            case DS::QUEUE:
                state=State::DS;
                queue=new Queue(&window,&sanf,&cons,FPS);
                queueControl=new Queue_Control(&sanf,window.getView().getSize());
                break;
            case DS::SARR:
                state=State::DS;
                sarr=new SArr(&window,&sanf,&cons,FPS);
                sarrControl=new SArr_Control(&sanf,window.getView().getSize());
                break;
            case DS::DARR:
                state=State::DS;
                darr=new DArr(&window,&sanf,&cons,FPS);
                darrControl=new DArr_Control(&sanf,window.getView().getSize());
                break;
        }
        return;
    }

    if(sll) SLL_Update();
    if(dll) DLL_Update();
    if(stack) Stack_Update();
    if(queue) Queue_Update();
    if(sarr) SArr_Update();
    if(darr) DArr_Update();
}

void App::draw()
{
    window.clear();
    window.draw(bgSprite);
    switch (state)
    {
        case State::MENU:
            window.draw(*menu);
            break;
        case State::DS:
            if(sll){
                sll->draw();
                window.draw(*sllControl);
            }
            if(dll){
                dll->draw();
                window.draw(*dllControl);
            }
            if(stack){
                stack->draw();
                window.draw(*stackControl);
            }
            if(queue){
                queue->draw();
                window.draw(*queueControl);
            }
            if(sarr){
                sarr->draw();
                window.draw(*sarrControl);
            }
            if(darr){
                darr->draw();
                window.draw(*darrControl);
            }
            break;
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
                        sll->randomList();
                        sll->makeList();
                        break;
                    case 3: // Random fixed size
                        sll->randomList(cmd.input1);
                        sll->makeList();
                        break;
                    case 4: // Load from file
                        sll->loadFromFile();
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

void App::DLL_Update()
{
    dllControl->update(1.0f/FPS);

    Command cmd;
    bool flag=dllControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            dll->pause();
            break;
        case -3: // play
            dll->play();
            break;
        case -4: // prev
            dll->prevStep();
            break;
        case -5: // next
            dll->nextStep();
            break;
        case -6: // go to begin
            dll->goToBegin();
            break;
        case -7: // go to end
            dll->goToEnd();
            break;
    }

    if(dll->isDoneAllSteps() && flag)
        switch (cmd.option)
        {                  
            case 0: // Create
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        dll->empty();
                        break;
                    case 1: // Manual
                        dll->manual(cmd.list);
                        dll->makeList();
                        break;
                    case 2: // Random
                        dll->randomList(getRand(1,10));
                        dll->makeList();
                        break;
                    case 3: // Random fixed size
                        dll->randomList(cmd.input1);
                        dll->makeList();
                        break;
                    case 4:
                        dll->loadFromFile();
                        dll->makeList();
                        break;
                }
                break;
            case 1: // Insert
                switch (cmd.suboption)
                {
                    case 0: // Front
                        dll->insertFront(cmd.input1);
                        break;
                    case 1: // Back
                        dll->insertBack(cmd.input1);
                        break;
                    case 2: // Middle
                        dll->insertMiddle(cmd.input1,cmd.input2);
                        break;
                }
                break;
            case 2: // Search
                dll->search(cmd.input1);
                break;
            case 3: // Update
                dll->update(cmd.input1,cmd.input2);
                break;
            case 4: // Delete
                switch (cmd.suboption)
                {
                    case 0: // First
                        dll->deleteFirst();
                        break;
                    case 1: // Last
                        dll->deleteLast();
                        break;
                    case 2: // Middle
                        dll->deleteMiddle(cmd.input1);
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
                    case 4: // Load from file
                        stack->loadFromFile();
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
                    case 4: // Load from file
                        queue->loadFromFile();
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
            case 2: // enqueue
                queue->enqueue(cmd.input1);
                break;
            case 3: // dequeue
                queue->dequeue();
                break;
        }
}

void App::SArr_Update()
{
    sarrControl->update(1.0f/FPS);

    Command cmd;
    bool flag=sarrControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            sarr->pause();
            break;
        case -3: // play
            sarr->play();
            break;
        case -4: // prev
            sarr->prevStep();
            break;
        case -5: // next
            sarr->nextStep();
            break;
        case -6: // go to begin
            sarr->goToBegin();
            break;
        case -7: // go to end
            sarr->goToEnd();
            break;
    }

    if(sarr->isDoneAllSteps() && flag)
        switch (cmd.option)
        {                  
            case 0: // Create
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        sarr->empty();
                        sarr->makeList();
                        break;
                    case 1: // Manual
                        sarr->manual(cmd.list);
                        sarr->makeList();
                        break;
                    case 2: // Random
                        sarr->randomList();
                        sarr->makeList();
                        break;
                    case 3: // Random fixed size
                        sarr->randomList(cmd.input1);
                        sarr->makeList();
                        break;
                    case 4: // Load from file
                        sarr->loadFromFile();
                        sarr->makeList();
                        break;
                }
                break;
            case 1: // Insert
                switch (cmd.suboption)
                {
                    case 0: // Front
                        sarr->insertFront(cmd.input1);
                        break;
                    case 1: // Back
                        sarr->insertBack(cmd.input1);
                        break;
                    case 2: // Middle
                        sarr->insertMiddle(cmd.input1,cmd.input2);
                        break;
                }
                break;
            case 2: // Search or Accses
                switch (cmd.suboption)
                {
                    case 0: // Search
                        sarr->search(cmd.input1);
                        break;
                    case 1: // Accses
                        sarr->access(cmd.input1);
                        break;
                }
                break;
            case 3: // Update
                sarr->update(cmd.input1,cmd.input2);
                break;
            case 4: // Delete
                switch (cmd.suboption)
                {
                    case 0: // First
                        sarr->deleteFirst();
                        break;
                    case 1: // Last
                        sarr->deleteLast();
                        break;
                    case 2: // Middle
                        sarr->deleteMiddle(cmd.input1);
                        break;
                }
                break;
       }
}

void App::DArr_Update()
{
    darrControl->update(1.0f/FPS);

    Command cmd;
    bool flag=darrControl->getCommand(cmd);

    switch (cmd.option)
    {
        case -2: // pause
            darr->pause();
            break;
        case -3: // play
            darr->play();
            break;
        case -4: // prev
            darr->prevStep();
            break;
        case -5: // next
            darr->nextStep();
            break;
        case -6: // go to begin
            darr->goToBegin();
            break;
        case -7: // go to end
            darr->goToEnd();
            break;
    }

    if(darr->isDoneAllSteps() && flag)
        switch (cmd.option)
        {                  
            case 0: // Create
                switch (cmd.suboption)
                {
                    case 0: // Empty
                        darr->empty();
                        darr->makeList();
                        break;
                    case 1: // Manual
                        darr->manual(cmd.list);
                        darr->makeList();
                        break;
                    case 2: // Random
                        darr->randomList();
                        darr->makeList();
                        break;
                    case 3: // Random fixed size
                        darr->randomList(cmd.input1);
                        darr->makeList();
                        break;
                    case 4: // Load from file
                        darr->loadFromFile();
                        darr->makeList();
                        break;
                }
                break;
            case 1: // Insert
                switch (cmd.suboption)
                {
                    case 0: // Front
                        darr->insertFront(cmd.input1);
                        break;
                    case 1: // Back
                        darr->insertBack(cmd.input1);
                        break;
                    case 2: // Middle
                        darr->insertMiddle(cmd.input1,cmd.input2);
                        break;
                }
                break;
            // case 2: // Search or Accses
            //     switch (cmd.suboption)
            //     {
            //         case 0: // Search
            //             darr->search(cmd.input1);
            //             break;
            //         case 1: // Accses
            //             darr->access(cmd.input1);
            //             break;
            //     }
            //     break;
            // case 3: // Update
            //     darr->update(cmd.input1,cmd.input2);
            //     break;
            // case 4: // Delete
            //     switch (cmd.suboption)
            //     {
            //         case 0: // First
            //             darr->deleteFirst();
            //             break;
            //         case 1: // Last
            //             darr->deleteLast();
            //             break;
            //         case 2: // Middle
            //             darr->deleteMiddle(cmd.input1);
            //             break;
            //     }
            //     break;
       }
}

void App::run()
{
    while (window.isOpen())
    {
        processInput();
        update();
        draw();
    }
}
