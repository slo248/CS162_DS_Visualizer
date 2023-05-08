#include "CLL.h"
#include "Config.h"

using namespace Config::CLL;

void CLL::deleteFirst()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/deleteFirst.txt");

    if(listNode.empty())
    {
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return;
    }
    
    if(listNode.size()==1)
    {
        graph.addStep(0.5*FPS);

        graph.drawShrink(&listNode.begin()->data,CIRCLE,WHITE,BLACK,BLACK);
        graph.draw(&codeBox,12);

        deletedNode.push_back(listNode.popFront());
        return;
    }

    Node* deletedN=listNode.popFront();
    Arrow* deletedA=listArrow.popFront();

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    listArrow.rbegin()->data.dest=&listNode.begin()->data;

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=deletedN;
}