#ifndef SLL_H
#define SLL_H

#include "Graph.h"
#include "Global.h"

class SLL
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(150, 200);
    float           DISTANCE        = 120.f;

public:
    SLL(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure* arrowFigure);
    ~SLL();

    // create
    void empty();
    void loadFromFile(std::string path);
    void randomList(int n);
    void makeList();

    // insert
    void insertWhenEmpty(int value);
    void insertFront(int value);
    void insertBack(int value);
    void insertMiddle(int value, int after);

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

private:
    bool isPause;

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

#endif // SLL_H