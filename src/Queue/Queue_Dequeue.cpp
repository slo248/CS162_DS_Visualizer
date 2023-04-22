#include "Queue.h"
#include "Config.h"

void Queue::dequeueWhenSingle()
{
    assert(listNode.size()<=1);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/dequeueWhenSingle.txt");
    
    if(listNode.size()==1){
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return;
    }

    Node* deletedN=listNode.popFront();
    deletedNode.push_back(deletedN);

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"head/tail/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"head/tail/tmp",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: head=tail=null
    graph.addStep(1);
    graph.draw(&codeBox,3);
    //
}

void Queue::dequeue()
{
    if(listNode.size()<=1){ 
        dequeueWhenSingle();
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/dequeue.txt");

    Node* deletedN=listNode.popFront();
    Arrow* deletedA=listArrow.popFront();
    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head.next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.draw(deletedA,BLACK);
    graph.drawGrow(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.drawShrink(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,3);
    //
}
