#ifndef SLL_H
#define SLL_H

#include "Graph.h"

class SLL
{
public:
    SLL(sf::RenderWindow* window, int FPS, sf::CircleShape* hCircle, sf::CircleShape* sCircle);

    void randomList(int n);

    void processInput();
    void render();
    void run();

private:
    int FPS;
    sf::RenderWindow* window;
    
    Graph graph;

    List<Node> listNode;
};

#endif // SLL_H