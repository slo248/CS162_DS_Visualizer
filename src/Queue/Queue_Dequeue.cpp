#include "Queue.h"
#include "Config.h"

void Queue::dequeueWhenSingle()
{
    assert(listNode.size()<=1);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/dequeue.txt");
    
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
}