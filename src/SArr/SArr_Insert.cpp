#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::insertFront(int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertFront.txt");

    // remember old list
    tmpNode=num;
    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.begin()->getNext(i)->data = listNodeA.begin()->getNext(i)->data;

    // actually insert
    for(int i=num.value-1; i>=0; i--)
        listNodeA.begin()->getNext(i+1)->data.value = listNodeA.begin()->getNext(i)->data.value;
    listNodeA.begin()->data.value = value;
    num.value++;
    //

    // step 1: move the list to the right
    for(int i=tmpNode.value; i>=0; i--)
    {
        // substep 1: highlight a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);

        graph.draw(&tmpListNode, SQUARE, 0, i, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i+1, MAX_NODE-1, WHITE, BLACK, BLACK);
        graph.drawFadeIn(&tmpListNode, SQUARE, i, i, ORANGE, ORANGE, WHITE);

        graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&tmpNode,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        //

        // substep 2: a[i+1]=a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        graph.draw(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);

        graph.draw(&tmpListNode, SQUARE, 0, i, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i+1, MAX_NODE-1, WHITE, BLACK, BLACK);
        graph.draw(&tmpListNode, SQUARE, i, i, ORANGE, ORANGE, WHITE);
        graph.drawFadeIn(&listNodeA, SQUARE, i, i, GREEN, GREEN, WHITE);

        graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&tmpNode,"n", RED, LEFT);

        if(i) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,2);
        //

        // substep 3: fade out a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        graph.drawFadeOut(&listNodeIndex, SQUARE, i, i, BLUE, BLUE, WHITE);

        graph.draw(&tmpListNode, SQUARE, 0, i, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i, MAX_NODE-1, WHITE, BLACK, BLACK);
        graph.drawFadeOut(&listNodeA, SQUARE, i, i, GREEN, GREEN, WHITE);

        graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&tmpNode,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        //
    }
    //

    // step 2: n++
    // substep 1: highlight n
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&tmpNode, SQUARE, ORANGE, ORANGE, WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&tmpNode,"n", RED, LEFT);

    graph.draw(&codeBox,3);
    //
    //substep 2: n++
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&tmpNode, SQUARE, ORANGE, ORANGE, WHITE);
    graph.drawFadeIn(&num, SQUARE, GREEN, GREEN, WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&tmpNode,"n", RED, LEFT);

    graph.draw(&codeBox,4);
    //
    //
}

void SArr::insertBack(int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/inserBack.txt");

    listNodeA.begin()->getNext(num.value)->data.value = value;
    num.value++;

    
}
