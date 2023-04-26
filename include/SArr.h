#ifndef SArr_H
#define SArr_H

#include "Graph.h"
#include "Global.h"

class SArr
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(150, 200);
    float           DISTANCE        = 120.f;

public:
    SArr(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~SArr();

    // // create
    // void empty();
    // void manual(const std::vector<int>& list);
    // void loadFromFile();
    // void randomList(int n);
    // void makeList();

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
    Node tmpNode;

    std::vector<Node*> deletedNode;
};

#endif // SArr_H