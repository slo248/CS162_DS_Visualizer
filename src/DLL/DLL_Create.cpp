#include "DLL.h"
#include "Random.h"
#include "Config.h"

using namespace Config::DLL;

void DLL::empty()
{
    listNode.clear();
    listArrowNext.clear();
    listArrowPrev.clear();
    graph.clear();
}

void DLL::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNode.pushBack(Node(x));
    }
}

void DLL::loadFromFile(std::string path)
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

void DLL::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void DLL::makeList()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next){
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);
        listArrowNext.pushBack(Arrow(&node->prev->data, &node->data));
        listArrowPrev.pushBack(Arrow(&node->data, &node->prev->data));
    }

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,WHITE,BLACK,BLACK);
    if(listNode.size()>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrowNext,BLACK);
    graph.drawGrow(&listArrowPrev,BLACK);
}