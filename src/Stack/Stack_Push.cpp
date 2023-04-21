#include "Stack.h"

void Stack::pushWhenEmpty(int value)
{
    assert(listNode.empty());

    codeBox.loadFromFile("code/Stack/push.txt");

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.drawGrow(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx.next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,10);
    //

    // step 3: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //
}

void Stack::push(int value)
{
    if(listNode.empty()) pushWhenEmpty(value);

    listNode.pushFront(value);
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data));


}
