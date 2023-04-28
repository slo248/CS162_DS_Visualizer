#include "DArr.h"

int DArr::access(int pos)
{
    assert(0<=pos && pos<num.value);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DArr/access.txt");

    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&listNodeIndex, SQUARE, pos, pos, BLUE, BLUE, WHITE);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&listNodeA, SQUARE, pos, pos, GREEN, GREEN, WHITE);

    graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&num,"n", RED, LEFT);

    graph.draw(&codeBox,0);

    return listNodeA.begin()->getNext(pos)->data.value;
}