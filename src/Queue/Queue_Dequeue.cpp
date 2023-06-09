#include "Queue.h"
#include "Config.h"

void Queue::dequeueWhenSingle()
{
    assert(listNode.size()<=1);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/dequeueWhenSingle.txt");
    
    if(listNode.empty()){
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return;
    }

    Node* deletedN=listNode.popFront();
    deletedNode.push_back(deletedN);

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(deletedN,"head/tail/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
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

    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head.next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(deletedA,BLACK);
    graph.drawGrow(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.drawShrink(deletedA,GREEN);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: move the queue to the left
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode.begin()->data,CIRCLE,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,CIRCLE,1,n-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,3);
    //
}
