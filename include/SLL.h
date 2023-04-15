#ifndef SLL_H
#define SLL_H

#include "Graph.h"
#include "HNeed.h"
#include "Button.h"

class SLL
{
public:
    sf::Vector2f    START_POSITION  = sf::Vector2f(150, 200);
    float           DISTANCE        = 120.f;

public:
    SLL(sf::RenderWindow* window, sf::Font* sanf, sf::Sprite* bg, int FPS, sf::CircleShape* circle, ArrowFigure* arrowFigure);
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
    void search(int value);

    // delete
    void deleteWhenSingle();
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int pos);

    // a frame
    void processInput();
    void update();
    void render();

    // run
    void run();

private:
    bool isPause;

    int FPS;
    sf::RenderWindow* window;
    sf::Sprite* bg;
    
    Graph graph;

    List<Node> listNode;
    List<Arrow> listArrow;
    Node tmpNode;
    Arrow tmpArrow;

    Button::Type curBtn;

    Button* createBtn;
        Button* emptyBtn;
        Button* randomBtn;
        Button* loadFromFileBtn;

    Button* insertBtn;
        Button* insertFrontBtn;
        Button* insertBackBtn;
        Button* insertMiddleBtn;

    Button* updateBtn;

    Button* searchBtn;

    Button* deleteBtn;
        Button* deleteFirstBtn;
        Button* deleteLastBtn;
        Button* deleteMiddleBtn;

    std::vector<Node*> deletedNode;
    std::vector<Arrow*> deletedArrow;
};

#endif // SLL_H