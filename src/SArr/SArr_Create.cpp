#include "SArr.h"
#include "Random.h"
#include "Config.h"
#include "FileIO.h"

using namespace Config::SArr;

void SArr::empty()
{
    num.value=0;
    listNodeIndex.clear();
    listNodeA.clear();
    graph.clear();
}

void SArr::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    num.value=list.size();

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNodeA.pushBack(x);
    }
}

void SArr::loadFromFile()
{
    manual(openWindowExplorer());
}

void SArr::randomList()
{
    randomList(getRand(MIN_NODE,MAX_NODE));
}

void SArr::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    num.value=n;
    while(n--)
        listNodeA.pushBack(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void SArr::makeList()
{
    graph.finishAllSteps();

    graph.addStep(0.5*FPS);

    for(int i=0; i<MAX_NODE; i++)
        listNodeIndex.pushBack(i);
    
    listNodeIndex.begin()->data.position=START_POSITION_INDEX;
    for(int i=1; i<MAX_NODE; i++)
        listNodeIndex.begin()->getNext(i)->data.position=listNodeIndex.begin()->data.position+sf::Vector2f(i*DISTANCE, 0);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.drawSubscript(&listNodeIndex.begin()->data, "index", RED, LEFT);

    for(int i=num.value; i<MAX_NODE; i++)
        listNodeA.pushBack(Node(-1));

    for(int i=0; i<MAX_NODE; i++)
        listNodeA.begin()->getNext(i)->data.position=START_POSITION_A+sf::Vector2f(i*DISTANCE, 0);

    // draw nodes to graph
    graph.draw(&listNodeA,SQUARE,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);

    // draw num node
    graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);
    graph.drawSubscript(&num,"n",RED,LEFT);
    //
}