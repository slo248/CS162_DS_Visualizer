#include "SLL.h"
#include "Random.h"
#include "Config.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Sprite* bg, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    bg(bg),
    curBtn(Button::NONE),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();

    createBtn = new Button(sanf, "Create", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    emptyBtn = new Button(sanf, "Empty", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    randomBtn = new Button(sanf, "Random", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    loadFromFileBtn = new Button(sanf, "File", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    insertBtn = new Button(sanf, "Insert", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    insertFrontBtn = new Button(sanf, "Front", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    insertBackBtn = new Button(sanf, "Back", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    insertAfterBtn = new Button(sanf, "After", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    updateBtn = new Button(sanf, "Update", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    searchBtn = new Button(sanf, "Search", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    removeBtn = new Button(sanf, "Remove", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);


    sf::Vector2u windowSize = window->getSize();
    createBtn->setPosition(sf::Vector2f(0,windowSize.y-5*createBtn->getSize().y));
    emptyBtn->setPosition(sf::Vector2f(createBtn->getSize().x+10.f,windowSize.y-5*emptyBtn->getSize().y));
    randomBtn->setPosition(sf::Vector2f(2*createBtn->getSize().x+10.f,windowSize.y-5*randomBtn->getSize().y));
    loadFromFileBtn->setPosition(sf::Vector2f(3*createBtn->getSize().x+10.f,windowSize.y-5*loadFromFileBtn->getSize().y));

    insertBtn->setPosition(sf::Vector2f(0,windowSize.y-4*insertBtn->getSize().y));
    insertFrontBtn->setPosition(sf::Vector2f(insertBtn->getSize().x+10.f,windowSize.y-4*insertFrontBtn->getSize().y));
    insertBackBtn->setPosition(sf::Vector2f(2*insertBtn->getSize().x+10.f,windowSize.y-4*insertBackBtn->getSize().y));
    insertAfterBtn->setPosition(sf::Vector2f(3*insertBtn->getSize().x+10.f,windowSize.y-4*insertAfterBtn->getSize().y));

    updateBtn->setPosition(sf::Vector2f(0,windowSize.y-3*updateBtn->getSize().y));

    searchBtn->setPosition(sf::Vector2f(0,windowSize.y-2*searchBtn->getSize().y));

    removeBtn->setPosition(sf::Vector2f(0,windowSize.y-1*removeBtn->getSize().y));
}

void SLL::empty()
{
    listNode.clear();
    listArrow.clear();
}

void SLL::loadFromFile(std::string path)
{
    empty();

    std::ifstream fi(path);
    if(!fi.is_open()) return;
    int val;
    while(fi>>val){
        assert(0<=val && val<=99);
        if(listNode.size()==10) break;
        listNode.pushBack(Node(val));
    }
    fi.close();
}

void SLL::randomList(int n)
{
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(0,99)));
}

void SLL::makeList()
{
    if(listNode.empty()) return;

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next){
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);
        listArrow.pushBack(Arrow(&node->prev->data, &node->data));
    }

    // add new steps
    graph.addStep(FPS/2);

    // draw nodes to graph
    graph.drawGrow(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,Colors::BLACK);
}

void SLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(FPS/2);

    // draw nodes to graph
    graph.drawGrow(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
}

void SLL::insertFront(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    listNode.pushFront(value);
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data));
    listNode.begin()->data.position=START_POSITION+sf::Vector2f(0, DISTANCE);

    // step 1: draw new node
    graph.addStep(FPS/2);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.drawGrow(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    //

    // step 2: draw new arrow
    graph.addStep(FPS/2);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 3: assign head to new node
    graph.addStep(FPS/2);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawShrink(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 4: move new node to correct position
    graph.addStep(FPS/2);

    for(ListElement<Node>* node=listNode.begin()->next; node!=listNode.end(); node=node->next)
        graph.drawMove(&node->data,node->data.position,node->data.position+sf::Vector2f(DISTANCE, 0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawHead(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawTail(&listNode.rbegin()->data,Colors::WHITE,Colors::BLACK,Colors::RED);
    graph.drawMove(&listNode.begin()->data,listNode.begin()->data.position,START_POSITION,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    //
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
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
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertBackBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertAfterBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        curBtn=Button::NONE;
                    }
                else if(updateBtn->isMouseOver(window)){
                    curBtn=Button::UPDATE;
                }
                else if(searchBtn->isMouseOver(window)){
                    curBtn=Button::SEARCH;
                }
                else if(removeBtn->isMouseOver(window)){
                    curBtn=Button::REMOVE;
                }
                break;           
        }

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
        insertAfterBtn->update(window);
    }

    updateBtn->update(window);

    searchBtn->update(window);

    removeBtn->update(window);
}

void SLL::render()
{
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
        window->draw(*insertAfterBtn);
    }

    window->draw(*updateBtn);

    window->draw(*searchBtn);

    window->draw(*removeBtn);

    graph.draw();
}

void SLL::run()
{
    randomList(4);
    makeList();
    while(window->isOpen()){
        processInput();
        window->clear(Colors::WHITE);
        render();
        window->display();
    }
}
