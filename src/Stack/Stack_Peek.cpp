#include "Stack.h"

void Stack::peek()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("code/Stack/peek.txt");

    if(listNode.empty()){ 
        graph.addStep(0.5*FPS);
        graph.draw(&codeBox,0);
        return;
    }
}