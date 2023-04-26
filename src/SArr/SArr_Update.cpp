#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::update(int pos, int value)
{
    assert(0<=pos && pos<num.value);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/update.txt");

    tmpNode.value=listNodeA.begin()->getNext(pos)->data.value;
    tmpNode.position=listNodeA.begin()->getNext(pos)->data.position;

    listNodeA.begin()->getNext(pos)->data.value=value;

    // step 1: highlight a[i]
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&listNodeIndex, SQUARE, pos, pos, BLUE, BLUE, WHITE);

    graph.draw(&listNodeA,SQUARE,0,pos-1,WHITE,BLACK,BLACK);
    graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);
    graph.draw(&listNodeA,SQUARE,pos+1,MAX_NODE-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&tmpNode,SQUARE,ORANGE,ORANGE,WHITE);

    graph.draw(&num, SQUARE, WHITE, BLACK, BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&num,"n", RED, LEFT);

    graph.draw(&codeBox,0);
    //
}