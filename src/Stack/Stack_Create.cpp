#include "Stack.h"
#include "Random.h"
#include "Config.h"

void Stack::empty()
{
    listNode.clear();
    listArrow.clear();
    graph.clear();
}

void Stack::manual(const std::vector<int> &list)
{
    empty();
    assert(list.size()<=10);

    for(int x: list){
        assert(0<=x && x<=99);
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
        assert(0<=val && val<=99);
        if(listNode.size()==10) break;
        listNode.pushBack(Node(val));
    }
    fi.close();
}

void Stack::randomList(int n)
{
    assert(0<=n && n<=10);
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(0,99)));
}

void Stack::makeList()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next){
        node->data.position=node->prev->data.position+sf::Vector2f(0, DISTANCE);
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