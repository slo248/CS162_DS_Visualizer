#ifndef DLL_H
#define DLL_H

#include "Graph.h"
#include "Global.h"

class DLL
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(150, 200);
    float           DISTANCE        = 120.f;

public:
    DLL(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~DLL();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile();
    void randomList();
    void randomList(int n);
    void makeList();

    // insert
    void insertWhenEmpty(int value);
    void insertFront(int value);
    void insertBack(int value);
    void insertMiddle(int pos, int value);

    // search
    int search(int value);

    // update
    void update(int pos, int newValue);

    // delete
    void deleteWhenSingle();
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int pos);

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
    List<Arrow> listArrowNext, listArrowPrev;
    Node tmpNode;
    Arrow tmpArrowNext, tmpArrowPrev;

    std::vector<Node*> deletedNode;
    std::vector<Arrow*> deletedArrow;
};

#endif // DLL_H