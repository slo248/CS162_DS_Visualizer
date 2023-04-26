#ifndef SArr_H
#define SArr_H

#include "Graph.h"
#include "Global.h"

class SArr
{
public:
    sf::Vector2f    START_POSITION_INDEX    = sf::Vector2f(150, 100);
    sf::Vector2f    START_POSITION_A        = sf::Vector2f(150, 200);
    sf::Vector2f    START_POSITION_N        = sf::Vector2f(150, 300);
    float           DISTANCE                = Config::Square::WIDTH+Config::Square::THICKNESS;

public:
    SArr(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~SArr();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile();
    void randomList();
    void randomList(int n);
    void makeList();

    // access
    int access(int pos);

    // update
    void update(int pos, int value);

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

    Node num;
    List<Node> listNodeA;
    List<Node> listNodeIndex;
    Node tmpNode;

    std::vector<Node*> deletedNode;
};

#endif // SArr_H