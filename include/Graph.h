#ifndef GRAPH_H
#define GRAPH_H

#include "HNeed.h"
#include "Node.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::CircleShape* hCircle, sf::CircleShape* sCircle);

    void clear();
    void addStep(int frames);

    // Node
    void draw(Node* node, CircleType type, sf::Color inColor, sf::Color outColor);
    //

    void draw();

private:
    sf::RenderWindow* window;
    sf::CircleShape* hCircle;
    sf::CircleShape* sCircle;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};

#endif // GRAPH_H