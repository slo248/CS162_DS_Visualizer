#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::insertFront(int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertFront.txt");

    // step 1: move the list to the right
    for(int i=num.value-1; i>0; i--)
    {
        // substep 1: highlight a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&listNodeIndex, SQUARE, i+1, i+1, BLUE, BLUE, WHITE);

        graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&listNodeA, SQUARE, i+1, i+1, ORANGE, ORANGE, WHITE);

        graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&num,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        //
    }
    //
}