#include "Queue.h"

void Queue::peekFront()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("code/Queue/peekFront.txt");

    if(listNode.empty()){
        graph.addStep(0.5*FPS);
        graph.draw(&codeBox,0);
        return;
    }

    // step 1: return head.value
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    if(listNode.size()>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,1);
    //
}

void Queue::peekBack()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("code/Queue/peekBack.txt");

    if(listNode.empty()){
        graph.addStep(0.5*FPS);
        graph.draw(&codeBox,0);
        return;
    }

    // step 1: return head.value
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.rbegin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    if(listNode.size()>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,1);
    //
}
