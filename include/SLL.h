#ifndef SLL_H
#define SLL_H

#include "Graph.h"
#include "HNeed.h"

class SLL
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(100, 100);
    float           DISTANCE        = 100.f;

public:
    SLL(sf::RenderWindow* window, sf::Font* sanf, int FPS, sf::CircleShape* hCircle, sf::CircleShape* sCircle);

    void randomList(int n);
    void makeList();

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