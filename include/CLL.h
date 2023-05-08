#ifndef CLL_H
#define CLL_H

#include "Graph.h"
#include "Global.h"

class CLL
{
public:
    CLL(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~CLL();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile();
    void randomList();
    void randomList(int n);
    void makeList();

    // insert
    void insertFront(int value);
    void insertBack(int value);
    void insertMiddle(int pos, int value);

    // search
    int search(int value);

    // update
    void update(int pos, int newValue);

    // delete
    void deleteFirst();
    void deleteLast();
    // void deleteMiddle(int pos);

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

#endif // CLL_H