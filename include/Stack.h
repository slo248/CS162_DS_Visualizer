#ifndef Stack_H
#define Stack_H

#include "Graph.h"
#include "Global.h"

class Stack
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(500, 5);
    float           DISTANCE        = 90.f;

public:
    Stack(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure* arrowFigure);
    ~Stack();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile(std::string path);
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

    void handleEvent(sf::Event& event);
    void draw();
    bool isDoneAllSteps();
    void pause();
    void play();
    void nextStep();
    void prevStep();

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