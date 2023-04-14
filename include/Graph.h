#ifndef GRAPH_H
#define GRAPH_H

#include "HNeed.h"
#include "Node.h"
#include "List.h"
#include "Arrow.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::Font* sanf, sf::CircleShape* circle, ArrowFigure* arrowFig);

    void clear();
    void finishAllSteps();
    void addStep(int frames);
    bool isDoneAllSteps();

    void nextStep();

    void setVisualDir(VisualDir d);
    void setVisualType(VisualType t);

    // Node
    void draw(Node* node, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(Node* node, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(Node* node, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeIn(Node* node, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeOut(Node* node, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(Node* node, sf::Vector2f src, sf::Vector2f dest,sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(Node* node, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawSubscript(Node* node, std::string str, sf::Color textColor);
    //

    // List of nodes
    void draw(List<Node>* list, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, int i, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, int from, int to, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);

    // Arrow
    void draw(Arrow* arrow, sf::Color color);
    void drawGrow(Arrow* arrow, sf::Color color);
    void drawShrink(Arrow* arrow, sf::Color color);
    void drawFadeIn(Arrow* arrow, sf::Color color);
    void drawFadeOut(Arrow* arrow, sf::Color color);

    // List of arrows
    void draw(List<Arrow>* list, int i, sf::Color color);
    void draw(List<Arrow>* list, int from, int to, sf::Color color);
    void draw(List<Arrow>* list, sf::Color color);
    void drawGrow(List<Arrow>* list, int i, sf::Color color);
    void drawGrow(List<Arrow>* list, int from, int to, sf::Color color);
    void drawGrow(List<Arrow>* list, sf::Color color);

    void draw();

private:
    sf::RenderWindow* window;
    sf::Text* text;
    sf::CircleShape* circle;
    ArrowFigure* arrowFig;

    VisualDir dir;
    VisualType type;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};

#endif // GRAPH_H