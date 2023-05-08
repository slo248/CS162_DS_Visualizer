#include "CLL.h"
#include "Random.h"
#include "Config.h"
#include "FileIO.h"

using namespace Config::CLL;

void CLL::empty()
{
    listNode.clear();
    listArrow.clear();
    graph.clear();
}

void CLL::manual(const std::vector<int> &list)
{
    empty();
    assert(MIN_NODE<=list.size() && list.size()<=MAX_NODE);

    for(int x: list){
        assert(Config::MIN_VALUE<=x && x<=Config::MAX_VALUE);
        listNode.pushBack(Node(x));
    }
}

void CLL::loadFromFile()
{
    manual(openWindowExplorer());
}

void CLL::randomList()
{
    randomList(getRand(MIN_NODE,MAX_NODE));
}

void CLL::randomList(int n)
{
    assert(MIN_NODE<=n && n<=MAX_NODE);
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(Config::MIN_VALUE,Config::MAX_VALUE)));
}

void CLL::makeList()
{
    if(listNode.empty()) return;

    // gen node
    float startAngle=acos(-1)/2;
    float angleBtwNode=2*acos(-1)/listNode.size();
    for(int i=0; i<listNode.size(); i++){
        sf::Vector2f pos=CENTER+sf::Vector2f(RADIUS,0);
        listNode.begin()->getNext(i)->data.position=sf::Vector2f(
            pos.x*cos(startAngle-i*angleBtwNode)-pos.y*sin(startAngle-i*angleBtwNode),
            pos.x*sin(startAngle-i*angleBtwNode)+pos.y*cos(startAngle-i*angleBtwNode)
        );
    }

    for(int i=0; i<listNode.size(); i++){
        listArrow.pushBack(Arrow(
            &listNode.begin()->getNext(i)->data,
            &listNode.begin()->getNext((i+1)%listNode.size())->data
        ));
    }
    //

    graph.finishAllSteps();

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,BLACK);
}