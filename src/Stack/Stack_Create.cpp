#include "Stack.h"
#include "Random.h"
#include "Config.h"

using namespace Config::Stack;

void Stack::empty()
{
    listNode.clear();
    listArrow.clear();
    graph.clear();
}

void Stack::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNode.pushBack(Node(x));
    }
}

void Stack::loadFromFile(std::string path)
{
    empty();

    std::ifstream fi(path);
    if(!fi.is_open()) return;
    int val;
    while(fi>>val){
        assert(Config::MIN_VALUE<=val && val<=Config::MAX_VALUE);
        if(listNode.size()==MAX_NODE) break;
        listNode.pushBack(Node(val));
    }
    fi.close();
}

void Stack::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void Stack::makeList()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    ListElement<Node>* node=listNode.rbegin();
    node->data.position=START_POSITION;
    for(node=node->prev; node!=listNode.end(); node=node->prev){
        node->data.position=node->next->data.position-sf::Vector2f(0, DISTANCE);
        listArrow.pushBack(Arrow(&node->data, &node->next->data));
    }

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,BLACK);
}