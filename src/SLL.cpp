#include "SLL.h"
#include "Random.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, int FPS, sf::CircleShape *hCircle, sf::CircleShape *sCircle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    graph(window, sanf, hCircle, sCircle, arrowFig)
{
    graph.clear();

    createBtn = new Button(sanf, "Create", sf::Vector2f(100, 50), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    insertBtn = new Button(sanf, "Insert", sf::Vector2f(100, 50), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    updateBtn = new Button(sanf, "Update", sf::Vector2f(100, 50), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    searchBtn = new Button(sanf, "Search", sf::Vector2f(100, 50), Colors::SILVER, Colors::GRAY, Colors::BLACK);
    removeBtn = new Button(sanf, "Remove", sf::Vector2f(100, 50), Colors::SILVER, Colors::GRAY, Colors::BLACK);

    sf::Vector2u windowSize = window->getSize();
    createBtn->setPosition(sf::Vector2f(0,windowSize.y-5*createBtn->getSize().y));
    insertBtn->setPosition(sf::Vector2f(0,windowSize.y-4*createBtn->getSize().y));
    updateBtn->setPosition(sf::Vector2f(0,windowSize.y-3*createBtn->getSize().y));
    searchBtn->setPosition(sf::Vector2f(0,windowSize.y-2*createBtn->getSize().y));
    removeBtn->setPosition(sf::Vector2f(0,windowSize.y-1*createBtn->getSize().y));
}

void SLL::randomList(int n)
{
    listNode.clear();
    listArrow.clear();
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
    graph.addStep(FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,Hollow,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,Colors::BLUE);
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code){
                    case sf::Keyboard::Space:
                        graph.finishAllSteps();
                        randomList(getRand(1, 10));
                        makeList();
                        break;
                }            
        }
    createBtn->update(window);
    insertBtn->update(window);
    updateBtn->update(window);
    searchBtn->update(window);
    removeBtn->update(window);
}

void SLL::render()
{
    window->draw(*createBtn);
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
