#include "Queue.h"
#include "Config.h"

void Queue::enqueueWhenEmpty(int value)
{
    assert(listNode.size()==0);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/enqueueWhenEmpty.txt");

    listNode.pushBack(value);
    
    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.drawGrow(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx.next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,1);
    //
}