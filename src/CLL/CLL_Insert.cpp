#include "CLL.h"
#include "Config.h"

using namespace Config::CLL;

void CLL::insertFront(int val)
{
    if(listNode.size()==MAX_NODE) return;

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/insertFront.txt");

    listNode.pushFront(val);
    listNode.begin()->data.position=CENTER;

    listArrow.rbegin()->data.dest=&listNode.begin()->data;
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->getNext()->data));
    listArrow.pushBack(Arrow(&listNode.rbegin()->data, &listNode.begin()->data));

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=&listNode.begin()->getNext()->data;

    graph.addStep(0.5*FPS);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.draw(&codeBox,9);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
}