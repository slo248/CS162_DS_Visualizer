#ifndef GRAPH_H
#define GRAPH_H

#include "HNeed.h"
#include "Node.h"
#include "List.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::Font* sanf, sf::CircleShape* hCircle, sf::CircleShape* sCircle);

    void clear();
    void addStep(int frames);

    // Node
    void draw(Node* node, CircleType type, sf::Color inColor, sf::Color outColor);
    void drawGrow(Node* node, CircleType type, sf::Color inColor, sf::Color outColor);
    void drawShrink(Node* node, CircleType type, sf::Color inColor, sf::Color outColor);
    //

    // List
    void draw(List<Node>* list, int i, CircleType type, sf::Color inColor, sf::Color outColor);
    void draw(List<Node>* list, int from, int to, CircleType type, sf::Color inColor, sf::Color outColor);
    void draw(List<Node>* list, CircleType type, sf::Color inColor, sf::Color outColor);

    void draw();

private:
    sf::RenderWindow* window;
    sf::Text* text;
    sf::CircleShape* hCircle;
    sf::CircleShape* sCircle;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};

#endif // GRAPH_H