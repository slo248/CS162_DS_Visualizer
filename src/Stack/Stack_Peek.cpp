#include "Stack.h"

void Stack::peek()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("code/Stack/peek.txt");

    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.empty()) return;

    // step 1: return head.value
    graph.addStep(0.5*FPS);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,1);
    //
}