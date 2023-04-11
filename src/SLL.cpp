#include "SLL.h"
#include "Random.h"
#include "Config.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, int FPS, sf::CircleShape *hCircle, sf::CircleShape *sCircle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    curBtn(Button::NONE),
    graph(window, sanf, hCircle, sCircle, arrowFig)
{
    graph.clear();

    createBtn = new Button(sanf, "Create", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    emptyBtn = new Button(sanf, "Empty", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    randomBtn = new Button(sanf, "Random", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    loadFromFileBtn = new Button(sanf, "File", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    insertBtn = new Button(sanf, "Insert", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    updateBtn = new Button(sanf, "Update", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    searchBtn = new Button(sanf, "Search", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    removeBtn = new Button(sanf, "Remove", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::SILVER, Colors::GRAY, Colors::BLACK);


    sf::Vector2u windowSize = window->getSize();
    createBtn->setPosition(sf::Vector2f(0,windowSize.y-5*createBtn->getSize().y));
    emptyBtn->setPosition(sf::Vector2f(createBtn->getSize().x+10.f,windowSize.y-5*emptyBtn->getSize().y));
    randomBtn->setPosition(sf::Vector2f(2*createBtn->getSize().x+10.f,windowSize.y-5*randomBtn->getSize().y));
    loadFromFileBtn->setPosition(sf::Vector2f(3*createBtn->getSize().x+10.f,windowSize.y-5*loadFromFileBtn->getSize().y));

    insertBtn->setPosition(sf::Vector2f(0,windowSize.y-4*insertBtn->getSize().y));

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
    graph.drawGrow(&listNode,Hollow,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,Colors::BLUE);
}

void SLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(FPS/2);

    // draw nodes to graph
    graph.drawGrow(&listNode,Hollow,Colors::WHITE,Colors::BLACK,Colors::BLACK);
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
    emptyBtn->update(window);
    randomBtn->update(window);
    loadFromFileBtn->update(window);

    insertBtn->update(window);

    updateBtn->update(window);

    searchBtn->update(window);

    removeBtn->update(window);
}

void SLL::render()
{
    window->draw(*createBtn);
    if(curBtn==Button::CREATE){
        window->draw(*emptyBtn);
        window->draw(*randomBtn);
        window->draw(*loadFromFileBtn);
    }

    window->draw(*insertBtn);

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
