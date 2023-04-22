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
}