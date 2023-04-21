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
}