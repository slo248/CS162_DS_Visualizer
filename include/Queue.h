#ifndef Queue_H
#define Queue_H

#include "Graph.h"
#include "Global.h"

class Queue
{
public:
    const sf::Vector2f    START_POSITION  = sf::Vector2f(750, 450);
    const float           DISTANCE        = 70.f;

public:
    Queue(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure* arrowFigure);
    ~Queue();

    // // create
    // void empty();
    // void manual(const std::vector<int>& list);
    // void loadFromFile(std::string path);
    // void randomList(int n);
    // void makeList();

    // // peek
    // void peek();

    // // push
    // void pushWhenEmpty(int value);
    // void push(int value);

    // // pop
    // void popWhenSingle();
    // void pop();

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

#endif // Queue_H