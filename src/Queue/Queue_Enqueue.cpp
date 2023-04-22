#include "Queue.h"
#include "Config.h"

void Queue::enqueueWhenEmpty(int value)
{
    assert(listNode.empty());

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

    // step 3: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 4: tail=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,3);
    //
}

void Queue::enqueue(int value)
{
    if(listNode.empty()){
        enqueueWhenEmpty(value);
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/enqueue.txt");

    listNode.pushBack(value);
    listArrow.pushBack(Arrow(&listNode.rbegin()->prev->data,&listNode.rbegin()->data));

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.rbegin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,0,m-2,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //
}
