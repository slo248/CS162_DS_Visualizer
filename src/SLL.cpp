#include "SLL.h"
#include "Random.h"

SLL::SLL(sf::RenderWindow *window, int FPS, sf::CircleShape *hCircle, sf::CircleShape *sCircle):
    FPS(FPS),
    window(window),
    graph(window, hCircle, sCircle)
{
    graph.clear();
}

void SLL::randomList(int n)
{
    listNode.clear();
    while(n--)
        listNode.pushBack(Node(getRand(0,99)));
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
    while(window->isOpen()){
        processInput();
        window->clear(sf::Color::White);
        render();
        window->display();
    }
}
