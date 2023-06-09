#include "Stack.h"

void Stack::pushWhenEmpty(int value)
{
    assert(listNode.empty());

    graph.finishAllSteps();

    codeBox.loadFromFile("code/Stack/push.txt");

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.drawGrow(&listNode,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx.next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,10);
    //

    // step 3: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //
}

void Stack::push(int value)
{
    if(listNode.empty()){
        pushWhenEmpty(value);
        return;
    }

    if(listNode.size()==MAX_NODE) return;

    graph.finishAllSteps();
    
    codeBox.loadFromFile("code/Stack/push.txt");

    listNode.pushFront(value);
    listNode.begin()->data.position=listNode.begin()->next->data.position-sf::Vector2f(0,DISTANCE);
    listArrow.pushFront(Arrow(&listNode.begin()->data,&listNode.begin()->next->data));

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: appear new arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
    graph.draw(&codeBox,1);
    //

    // step 3: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.drawFadeIn(&listArrow.begin()->data,BLACK);
    graph.draw(&listArrow,1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //
}
