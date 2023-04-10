#include "SLL.h"
#include "Random.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, int FPS, sf::CircleShape *hCircle, sf::CircleShape *sCircle):
    FPS(FPS),
    window(window),
    graph(window, sanf, hCircle, sCircle)
{
    graph.clear();
}

void SLL::randomList(int n)
{
    listNode.clear();
    while(n--)
        listNode.pushBack(Node(getRand(0,99)));
}

void SLL::makeList()
{
    if(listNode.empty()) return;

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next)
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);

    // add new steps
    graph.addStep(FPS);

    // Add nodes to graph
    graph.draw(&listNode,Hollow,Colors::WHITE,Colors::BLACK);
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
        }
}

void SLL::render()
{
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
