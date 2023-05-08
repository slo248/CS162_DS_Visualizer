#ifndef GRAPH_H
#define GRAPH_H

#include "Global.h"
#include "Node.h"
#include "List.h"
#include "Arrow.h"
#include "CodeBox.h"
#include "Figure.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::Font* sanf);

    void clear();
    void finishAllSteps();
    void addStep(int frames);
    void goToBegin();
    void goToEnd();
    bool isDoneAllSteps();

    void nextStep();
    void prevStep();

    void setVisualDir(VisualDir d);
    void setVisualType(VisualType t);

    // Node
    void draw(Node* node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(Node* node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(Node* node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeIn(Node* node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeOut(Node* node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(Node* node, NodeType type, sf::Vector2f src, sf::Vector2f dest,sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(Node* node, NodeType type, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(Node* node, NodeType type, sf::Vector2f origin, float alpha, float beta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawSubscript(Node* node, std::string str, sf::Color textColor, SubscriptDir dir=DOWN);
    //

    // List of nodes
    void draw(List<Node>* list, NodeType type, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void draw(List<Node>* list, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, NodeType type, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawGrow(List<Node>* list, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(List<Node>* list, NodeType type, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(List<Node>* list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawShrink(List<Node>* list, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, NodeType type, int i, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, NodeType type, int from, int to, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawMove(List<Node>* list, NodeType type, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeIn(List<Node>* list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);
    void drawFadeOut(List<Node>* list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor);

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
    void drawFadeIn(List<Arrow>* list, int from, int to, sf::Color color);
    void drawFadeOut(List<Arrow>* list, int from, int to, sf::Color color);

    // CodeBox
    void draw(CodeBox* codeBox, int pos);

    void draw();

private:
    sf::RenderWindow* window;
    sf::Text* text;
    
    Figure figure;

    VisualDir dir;
    VisualType type;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};

#endif // GRAPH_H