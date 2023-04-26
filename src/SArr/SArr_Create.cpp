#include "SArr.h"
#include "Random.h"
#include "Config.h"
#include "FileIO.h"

using namespace Config::SArr;

void SArr::empty()
{
    listNode.clear();
    graph.clear();
}

void SArr::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNode.pushBack(Node(x));
    }
}

void SArr::loadFromFile()
{
    manual(openWindowExplorer());
}

void SArr::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void SArr::makeList()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next)
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,SQUARE,WHITE,BLACK,BLACK);
}