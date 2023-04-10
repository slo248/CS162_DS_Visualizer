#ifndef GRAPH_H
#define GRAPH_H

#include "HNeed.h"
#include "Node.h"
#include "List.h"
#include "Arrow.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::Font* sanf, sf::CircleShape* hCircle, sf::CircleShape* sCircle, ArrowFigure* arrowFig);

    void clear();
    void addStep(int frames);

    // Node
    void draw(Node* node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(Node* node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(Node* node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    //

    // List of nodes
    void draw(List<Node>* list, int i, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, int from, int to, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);

    // Arrow
    void draw(Arrow* arrow, sf::Color color);

    // List of arrows
    void draw(List<Arrow>* list, int i, sf::Color color);

    void draw();

private:
    sf::RenderWindow* window;
    sf::Text* text;
    sf::CircleShape* hCircle;
    sf::CircleShape* sCircle;
    ArrowFigure* arrowFig;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};

#endif // GRAPH_H