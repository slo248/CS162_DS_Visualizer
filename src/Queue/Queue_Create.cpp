#include "Queue.h"
#include "Random.h"
#include "Config.h"

using namespace Config::Queue;

void Queue::empty()
{
    listNode.clear();
    listArrow.clear();
    graph.clear();
}

void Queue::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNode.pushFront(Node(x));
    }
}

void Queue::loadFromFile(std::string path)
{
    empty();

    std::ifstream fi(path);
    if(!fi.is_open()) return;
    int val;
    while(fi>>val){
        assert(Config::MIN_VALUE<=val && val<=Config::MAX_VALUE);
        if(listNode.size()==MAX_NODE) break;
        listNode.pushFront(Node(val));
    }
    fi.close();
}

void Queue::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    while(n--)
        listNode.pushFront(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void Queue::makeList()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next){
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);
        listArrow.pushBack(Arrow(&node->prev->data, &node->data));
    }

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,BLACK);
}