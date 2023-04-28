#ifndef DArr_H
#define DArr_H

#include "Graph.h"
#include "Global.h"
#include <queue>
#include <utility>

class DArr
{
public:
    sf::Vector2f    START_POSITION_INDEX    = sf::Vector2f(150, 100);
    sf::Vector2f    START_POSITION_A        = sf::Vector2f(150, 200);
    sf::Vector2f    START_POSITION_N        = sf::Vector2f(150, 300);
    float           DISTANCE                = Config::Square::WIDTH+Config::Square::THICKNESS;

    enum Command
    {
        INSERT_FRONT,
        INSERT_BACK,
        INSERT_MIDDLE,
        ALL
    };

public:
    DArr(sf::RenderWindow* window, sf::Font* sanf, sf::Font* cons, int FPS);
    ~DArr();

    void saveOldMem();

    // create
    void empty();
    void manual(const std::vector<int>& list);
    void loadFromFile();
    void randomList();
    void randomList(int n);
    void makeList();

    // insert
    bool checkSize();
    void insertFront(int value);
    void insertBack(int value);
    void insertMiddle(int pos, int value);

    // delete
    void deleteFirst();
    void deleteLast();
    // void deleteMiddle(int pos);

    // search
    int search(int value);

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

    int curMaxNode;
    std::queue<std::pair<Command,std::pair<int,int> > > commandQueue;

    Node num;
    List<Node> listNodeA;
    List<Node> listNodeIndex;
    List<Node> tmpListNode, tmpListNode2;
    Node tmpNode;

    std::vector<Node*> deletedNode;
};

#endif // DArr_H