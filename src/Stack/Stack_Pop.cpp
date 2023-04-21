#include "Stack.h"

void Stack::pop()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/Stack/pop.txt");

    if(listNode.empty()){
        graph.addStep(0.5*FPS);
        graph.draw(&codeBox,0);
        return;
    }

    Node* deletedN=listNode.popFront();
    Arrow* deletedA=listArrow.popFront();

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    if(deletedA) graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head.next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    if(deletedA){ 
        graph.draw(deletedA,BLACK);
        graph.drawGrow(deletedA,GREEN);
    }
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    if(deletedA) graph.drawShrink(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(deletedN);
    if(deletedA) deletedArrow.push_back(deletedA);
}