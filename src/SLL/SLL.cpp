#include "SLL.h"
#include "Random.h"
#include "Config.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, sf::Sprite* bg, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    bg(bg),
    curBtn(Button::NONE),
    isPause(false),
    codeBox(cons),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();
    graph.setVisualType(STEP_BY_STEP);

    createBtn = new Button(sanf, "Create", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    emptyBtn = new Button(sanf, "Empty", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    randomBtn = new Button(sanf, "Random", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    loadFromFileBtn = new Button(sanf, "File", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    insertBtn = new Button(sanf, "Insert", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertFrontBtn = new Button(sanf, "Front", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertBackBtn = new Button(sanf, "Back", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertMiddleBtn = new Button(sanf, "Middle", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    updateBtn = new Button(sanf, "Update", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    searchBtn = new Button(sanf, "Search", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    deleteBtn = new Button(sanf, "Delete", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteFirstBtn = new Button(sanf, "First", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteLastBtn = new Button(sanf, "Last", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteMiddleBtn = new Button(sanf, "Middle", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    sf::Vector2u windowSize = window->getSize();
    createBtn->setPosition(sf::Vector2f(0,windowSize.y-5*createBtn->getSize().y));
    emptyBtn->setPosition(sf::Vector2f(createBtn->getSize().x+10.f,windowSize.y-5*emptyBtn->getSize().y));
    randomBtn->setPosition(sf::Vector2f(2*createBtn->getSize().x+10.f,windowSize.y-5*randomBtn->getSize().y));
    loadFromFileBtn->setPosition(sf::Vector2f(3*createBtn->getSize().x+10.f,windowSize.y-5*loadFromFileBtn->getSize().y));

    insertBtn->setPosition(sf::Vector2f(0,windowSize.y-4*insertBtn->getSize().y));
    insertFrontBtn->setPosition(sf::Vector2f(insertBtn->getSize().x+10.f,windowSize.y-4*insertFrontBtn->getSize().y));
    insertBackBtn->setPosition(sf::Vector2f(2*insertBtn->getSize().x+10.f,windowSize.y-4*insertBackBtn->getSize().y));
    insertMiddleBtn->setPosition(sf::Vector2f(3*insertBtn->getSize().x+10.f,windowSize.y-4*insertMiddleBtn->getSize().y));

    updateBtn->setPosition(sf::Vector2f(0,windowSize.y-3*updateBtn->getSize().y));

    searchBtn->setPosition(sf::Vector2f(0,windowSize.y-2*searchBtn->getSize().y));

    deleteBtn->setPosition(sf::Vector2f(0,windowSize.y-1*deleteBtn->getSize().y));
    deleteFirstBtn->setPosition(sf::Vector2f(deleteBtn->getSize().x+10.f,windowSize.y-1*deleteFirstBtn->getSize().y));
    deleteLastBtn->setPosition(sf::Vector2f(2*deleteBtn->getSize().x+10.f,windowSize.y-1*deleteLastBtn->getSize().y));
    deleteMiddleBtn->setPosition(sf::Vector2f(3*deleteBtn->getSize().x+10.f,windowSize.y-1*deleteMiddleBtn->getSize().y));
}

SLL::~SLL()
{
    delete createBtn;
    delete emptyBtn;
    delete randomBtn;
    delete loadFromFileBtn;

    delete insertBtn;
    delete insertFrontBtn;
    delete insertBackBtn;
    delete insertMiddleBtn;

    delete updateBtn;

    delete searchBtn;

    delete deleteBtn;
    delete deleteFirstBtn;
    delete deleteLastBtn;
    delete deleteMiddleBtn;

    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::LostFocus:
                isPause=true;
                window->setFramerateLimit(1);
                break;
            case sf::Event::GainedFocus:
                isPause=false;
                window->setFramerateLimit(FPS);
                break;
            case sf::Event::MouseButtonReleased:
                if(createBtn->isMouseOver(window)){
                    curBtn=Button::CREATE;
                }
                    else if(curBtn==Button::CREATE && emptyBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        empty();
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::CREATE && randomBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        randomList(getRand(0,10));
                        makeList();
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::CREATE && loadFromFileBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        loadFromFile("inp.txt");
                        makeList();
                        curBtn=Button::NONE;
                    }
                else if(insertBtn->isMouseOver(window)){
                    curBtn=Button::INSERT;
                }
                    else if(curBtn==Button::INSERT && insertFrontBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertFront(getRand(0,99));
                        codeBox.loadFromFile("media/code/insertFront.txt");
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertBackBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertBack(getRand(0,99));
                        codeBox.loadFromFile("media/code/insertBack.txt");
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertMiddleBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertMiddle(getRand(0,99),getRand(1,listNode.size()-1));
                        codeBox.loadFromFile("media/code/insertMiddle.txt");
                        curBtn=Button::NONE;
                    }
                else if(updateBtn->isMouseOver(window)){
                    curBtn=Button::UPDATE;
                    graph.finishAllSteps();
                    update(getRand(0,listNode.size()-1),getRand(0,99));
                    codeBox.loadFromFile("media/code/update.txt");
                    curBtn=Button::NONE;
                }
                else if(searchBtn->isMouseOver(window)){
                    curBtn=Button::SEARCH;
                    graph.finishAllSteps();
                    search(getRand(0,99));
                    codeBox.loadFromFile("media/code/search.txt");
                    curBtn=Button::NONE;
                }
                else if(deleteBtn->isMouseOver(window)){
                    curBtn=Button::DELETE;
                }
                    else if (curBtn==Button::DELETE && deleteFirstBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        deleteFirst();
                        codeBox.loadFromFile("media/code/deleteFirst.txt");
                        curBtn=Button::NONE;
                    }
                    else if (curBtn==Button::DELETE && deleteLastBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        deleteLast();
                        codeBox.loadFromFile("media/code/deleteLast.txt");
                        curBtn=Button::NONE;
                    }
                    else if (curBtn==Button::DELETE && deleteMiddleBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        deleteMiddle(1);
                        codeBox.loadFromFile("media/code/deleteMiddle.txt");
                        curBtn=Button::NONE;
                    }
                break;           
        }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isPause)
        graph.nextStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isPause)
        graph.prevStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        graph.setVisualType(STEP_BY_STEP);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        graph.setVisualType(AUTO);
}

void SLL::update()
{
    createBtn->update(window);
    if(curBtn==Button::CREATE){
        emptyBtn->update(window);
        randomBtn->update(window);
        loadFromFileBtn->update(window);
    }

    insertBtn->update(window);
    if(curBtn==Button::INSERT){
        insertFrontBtn->update(window);
        insertBackBtn->update(window);
        insertMiddleBtn->update(window);
    }

    updateBtn->update(window);

    searchBtn->update(window);

    deleteBtn->update(window);
    if(curBtn==Button::DELETE){
        deleteFirstBtn->update(window);
        deleteLastBtn->update(window);
        deleteMiddleBtn->update(window);
    }
}

void SLL::render()
{
    window->clear(Colors::WHITE);

    window->draw(*bg);

    window->draw(*createBtn);
    if(curBtn==Button::CREATE){
        window->draw(*emptyBtn);
        window->draw(*randomBtn);
        window->draw(*loadFromFileBtn);
    }

    window->draw(*insertBtn);
    if(curBtn==Button::INSERT){
        window->draw(*insertFrontBtn);
        window->draw(*insertBackBtn);
        window->draw(*insertMiddleBtn);
    }

    window->draw(*updateBtn);

    window->draw(*searchBtn);

    window->draw(*deleteBtn);
    if(curBtn==Button::DELETE){
        window->draw(*deleteFirstBtn);
        window->draw(*deleteLastBtn);
        window->draw(*deleteMiddleBtn);
    }

    graph.draw();
    codeBox.draw(window);

    window->display();
}

void SLL::run()
{
    randomList(4);
    makeList();
    while(window->isOpen()){
        processInput();
        update();
        render();
    }
}
