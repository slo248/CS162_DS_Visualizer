#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

int SArr::search(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/search.txt");

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
}
