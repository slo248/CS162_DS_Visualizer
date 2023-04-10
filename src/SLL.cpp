#include "SLL.h"

SLL::SLL(sf::RenderWindow *window, int FPS, sf::CircleShape *hCircle, sf::CircleShape *sCircle):
    FPS(FPS),
    window(window),
    graph(window, hCircle, sCircle)
{
    graph.clear();
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
