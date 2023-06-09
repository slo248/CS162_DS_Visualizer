#include "Stack.h"

void Stack::popWhenSingle()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/Stack/pop.txt");

    if(listNode.empty()){
        graph.addStep(0.5*FPS);
        graph.draw(&codeBox,0);
        return;
    }

    assert(listNode.size()==1);

    Node* deletedN=listNode.popFront();

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head.next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.draw(&codeBox,2);
    //
    
    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(deletedN);
}

void Stack::pop()
{
    if(listNode.size()<=1){ 
        popWhenSingle();
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Stack/pop.txt");

    Node* deletedN=listNode.popFront();
    Arrow* deletedA=listArrow.popFront();

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    if(deletedA) graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head.next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
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

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    if(deletedA) graph.drawShrink(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(deletedN);
    if(deletedA) deletedArrow.push_back(deletedA);
}