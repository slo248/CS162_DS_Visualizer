#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

int DArr::search(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DArr/search.txt");

    // when empty
    if(num.value==0){
        graph.addStep(1);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);
        graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&num,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        return -1;
    }

    for(int i=0; i<num.value; i++)
    {
        // step 1: highlight a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, 0, i-1, WHITE, BLUE, BLUE);
        graph.draw(&listNodeIndex, SQUARE, i, curMaxNode-1, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);

        graph.draw(&listNodeA, SQUARE, 0, i-1, WHITE, ORANGE, ORANGE);
        graph.draw(&listNodeA, SQUARE, i, curMaxNode-1, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&listNodeA, SQUARE, i, i, ORANGE, ORANGE, WHITE);

        graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&num,"n", RED, LEFT);

        graph.draw(&codeBox,2);
        //

        // step 2: found
        if(listNodeA.begin()->getNext(i)->data.value==value)
        {
            graph.addStep(0.5*FPS);

            graph.draw(&listNodeIndex, SQUARE, 0, i-1, WHITE, BLUE, BLUE);
            graph.draw(&listNodeIndex, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
            graph.draw(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);

            graph.draw(&listNodeA, SQUARE, 0, i-1, WHITE, ORANGE, ORANGE);
            graph.draw(&listNodeA, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
            graph.draw(&listNodeA, SQUARE, i, i, ORANGE, ORANGE, WHITE);
            graph.drawFadeIn(&listNodeA, SQUARE, i, i, GREEN, GREEN, WHITE);

            graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

            graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
            graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
            graph.drawSubscript(&num,"n", RED, LEFT);

            graph.draw(&codeBox,3);
            return i;
        }

        // step 3: fade out a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, 0, i-1, WHITE, BLUE, BLUE);
        graph.draw(&listNodeIndex, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
        graph.draw(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);
        graph.drawFadeIn(&listNodeIndex, SQUARE, i, i, WHITE, BLUE, BLUE);

        graph.draw(&listNodeA, SQUARE, 0, i-1, WHITE, ORANGE, ORANGE);
        graph.draw(&listNodeA, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i, i, ORANGE, ORANGE, WHITE);
        graph.drawFadeIn(&listNodeA, SQUARE, i, i, WHITE, ORANGE, ORANGE);

        graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&num,"n", RED, LEFT);

        if(i<num.value-1)
            graph.draw(&codeBox,1);
        else
            graph.draw(&codeBox,4);
        //
    }

    return -1;
}
