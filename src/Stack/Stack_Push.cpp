#include "Stack.h"

void Stack::pushWhenEmpty(int value)
{
    assert(listNode.empty());

    codeBox.loadFromFile("code/Stack/push.txt");

    listNode.pushBack(value);

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.drawGrow(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //
}