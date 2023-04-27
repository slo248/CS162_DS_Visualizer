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
        tmpListNode.begin()->getNext(i)->data=listNodeA.begin()->getNext(i)->data;

    // actually insert
    for(int i=num.value-1; i>=0; i--)
        listNodeA.begin()->getNext(i+1)->data.value = listNodeA.begin()->getNext(i)->data.value;
    listNodeA.begin()->data.value = value;
    num.value++;
    //

    // step 1: move the list to the right
    for(int i=tmpNode.value; i>=0; i--)
    {
        // substep 1: fade out a[i+1]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        if(i<tmpNode.value)
            graph.drawFadeOut(&listNodeIndex, SQUARE, i+1, i+1, BLUE, BLUE, WHITE);

        graph.draw(&tmpListNode, SQUARE, 0, i, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i+1, MAX_NODE-1, WHITE, BLACK, BLACK);
        if(i<tmpNode.value)
            graph.drawFadeOut(&listNodeA, SQUARE, i+1, i+1, GREEN, GREEN, WHITE);

        graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&tmpNode,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        //

        // substep 2: highlight a[i]
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

        if(i) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,2);
        //

        // substep 3: a[i+1]=a[i]
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

    graph.draw(&codeBox,3);
    //
    // substep 3: fade out n
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&num, SQUARE, GREEN, GREEN, WHITE);
    graph.drawFadeIn(&num, SQUARE, WHITE, BLACK, BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&num,"n", RED, LEFT);

    graph.draw(&codeBox,4);
    //
    //
}

void SArr::insertBack(int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertBack.txt");

    tmpNode=num;
    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.begin()->getNext(i)->data=listNodeA.begin()->getNext(i)->data;

    listNodeA.begin()->getNext(num.value)->data.value = value;
    num.value++;

    // step 1: a[n+1]=v
    // substep 1: highlight n+1
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&listNodeIndex, SQUARE, tmpNode.value, tmpNode.value, BLUE, BLUE, WHITE);

    graph.draw(&tmpListNode, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&tmpListNode, SQUARE, tmpNode.value, tmpNode.value, ORANGE, ORANGE, WHITE);

    graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&tmpListNode.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&tmpNode,"n", RED, LEFT);

    graph.draw(&codeBox,0);
    //
    // substep 2: a[n+1]=v
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.draw(&listNodeIndex, SQUARE, tmpNode.value, tmpNode.value, BLUE, BLUE, WHITE);

    graph.draw(&tmpListNode, SQUARE, WHITE, BLACK, BLACK);
    graph.draw(&tmpListNode, SQUARE, tmpNode.value, tmpNode.value, ORANGE, ORANGE, WHITE);
    graph.drawFadeIn(&listNodeA, SQUARE, tmpNode.value, tmpNode.value, GREEN, GREEN, WHITE);

    graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeIn(&tmpNode, SQUARE, ORANGE, ORANGE, WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&tmpListNode.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&tmpNode,"n", RED, LEFT);

    graph.draw(&codeBox,1);
    //
    //

    // step 2: n++
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeOut(&listNodeIndex, SQUARE, tmpNode.value, tmpNode.value, BLUE, BLUE, WHITE);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);
    graph.drawFadeOut(&listNodeA, SQUARE, tmpNode.value, tmpNode.value, GREEN, GREEN, WHITE);

    graph.draw(&tmpNode, SQUARE, ORANGE, ORANGE, WHITE);
    graph.drawFadeIn(&num, SQUARE, GREEN, GREEN, WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&num,"n", RED, LEFT);

    graph.draw(&codeBox,2);
    //
}

void SArr::insertMiddle(int pos, int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(0<pos && pos<num.value-1);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertMiddle.txt");

    // remember old list
    tmpNode=num;
    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.begin()->getNext(i)->data=listNodeA.begin()->getNext(i)->data;

    // actually insert
    for(int i=num.value-1; i>=pos; i--)
        listNodeA.begin()->getNext(i+1)->data.value = listNodeA.begin()->getNext(i)->data.value;
    listNodeA.begin()->getNext(pos)->data.value = value;
    num.value++;
    //

    // step 1: move [pos,n-1] to the right
    for(int i=tmpNode.value; i>=pos; i--)
    {
        // substep 1: fade out a[i+1]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);
        if(i<tmpNode.value)
            graph.drawFadeOut(&listNodeIndex, SQUARE, i+1, i+1, BLUE, BLUE, WHITE);

        graph.draw(&tmpListNode, SQUARE, 0, i, WHITE, BLACK, BLACK);
        graph.draw(&listNodeA, SQUARE, i+1, MAX_NODE-1, WHITE, BLACK, BLACK);
        if(i<tmpNode.value)
            graph.drawFadeOut(&listNodeA, SQUARE, i+1, i+1, GREEN, GREEN, WHITE);

        graph.draw(&tmpNode, SQUARE, WHITE, BLACK, BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
        graph.drawSubscript(&tmpNode,"n", RED, LEFT);

        graph.draw(&codeBox,0);
        //

        // substep 2: highlight a[i]
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

        if(i>pos) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,2);
        //

        // substep 3: a[i+1]=a[i]
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

        if(i>pos) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,2);
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

    graph.draw(&codeBox,3);
    //
    // substep 3: fade out n
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&listNodeA, SQUARE, WHITE, BLACK, BLACK);

    graph.draw(&num, SQUARE, GREEN, GREEN, WHITE);
    graph.drawFadeIn(&num, SQUARE, WHITE, BLACK, BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index", RED, LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a", RED, LEFT);
    graph.drawSubscript(&num,"n", RED, LEFT);

    graph.draw(&codeBox,4);
    //
    //
}
