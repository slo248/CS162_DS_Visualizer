#ifndef Stack_H
#define Stack_H

#include "Graph.h"
#include "Global.h"

class Stack
{
public:
    const sf::Vector2f    START_POSITION  = sf::Vector2f(750, 500);
    const float           DISTANCE        = 80.f;
    const int             MAX_NODE        = 7;

public:
    Stack(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~Stack();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile();
    void randomList();
    void randomList(int n);
    void makeList();

    // peek
    void peek();

    // push
    void pushWhenEmpty(int value);
    void push(int value);

    // pop
    void popWhenSingle();
    void pop();

    void draw();
    bool isDoneAllSteps();
    void pause();
    void play();
    void nextStep();
    void prevStep();
    void goToBegin();
    void goToEnd();

private:
    int FPS;
    sf::RenderWindow* window;
    sf::Font* sanf;
    sf::Font* cons;
    
    Graph graph;
    CodeBox codeBox;

    List<Node> listNode;
    List<Arrow> listArrow;
    Node tmpNode;
    Arrow tmpArrow;

    std::vector<Node*> deletedNode;
    std::vector<Arrow*> deletedArrow;
};

#endif // Stack_H