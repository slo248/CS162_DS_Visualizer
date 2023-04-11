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
    SLL(sf::RenderWindow* window, sf::Font* sanf, int FPS, sf::CircleShape* hCircle, sf::CircleShape* sCircle, ArrowFigure* arrowFigure);

    // create
    void empty();
    void loadFromFile(std::string path);
    void randomList(int n);
    void makeList();

    // insert
    void insertWhenEmpty(int value);

    void processInput();
    void render();
    void run();

private:
    int FPS;
    sf::RenderWindow* window;
    
    Graph graph;

    List<Node> listNode;
    List<Arrow> listArrow;

    Button::Type curBtn;

    Button* createBtn;
        Button* emptyBtn;
        Button* randomBtn;
        Button* loadFromFileBtn;

    Button* insertBtn;

    Button* updateBtn;

    Button* searchBtn;

    Button* removeBtn;
};

#endif // SLL_H