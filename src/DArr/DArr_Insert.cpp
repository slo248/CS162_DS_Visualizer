#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

bool DArr::checkSize()
{
    if(num.value<curMaxNode) return false;

    // actually allocate new array with size double of current size

    tmpListNode2.clear();
    for(int i=0; i<curMaxNode; i++)
        tmpListNode2.pushBack(listNodeA.begin()->getNext(i)->data);

    for(int i=curMaxNode; i<2*curMaxNode; i++){
        listNodeIndex.pushBack(i);
        listNodeIndex.rbegin()->data.position=START_POSITION_INDEX+sf::Vector2f(i*DISTANCE, 0);

        listNodeA.pushBack(-1);
        listNodeA.rbegin()->data.position=START_POSITION_A+sf::Vector2f(i*DISTANCE, 0);
    }

    curMaxNode<<=1;

    tmpListNode.clear();
    for(int i=0; i<curMaxNode; i++){
        tmpListNode.pushBack(-1);
        tmpListNode.rbegin()->data.position=START_POSITION_A+sf::Vector2f(i*DISTANCE, 100);
        listNodeA.begin()->getNext(i)->data.position+=sf::Vector2f(0,100);
    }
    //

    // update graph
    graph.finishAllSteps();
    codeBox.loadFromFile("code/DArr/checkSize.txt");
    
    // step 1: create new Arr
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNodeIndex,SQUARE,curMaxNode>>1,curMaxNode-1,WHITE,BLACK,BLACK);

    graph.draw(&tmpListNode2,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);

    graph.drawGrow(&tmpListNode,SQUARE,0,curMaxNode-1,WHITE,BLACK,BLACK);

    num.position+=sf::Vector2f(0,100);
    graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
    graph.drawSubscript(&tmpListNode2.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&tmpListNode.begin()->data,"newA",RED,LEFT);
    graph.drawSubscript(&num,"n",RED,LEFT);

    graph.draw(&codeBox,12);
    //

    // step 2: copy old Arr to new Arr
    for(int i=0; i<=num.value; i++)
    {
        // substep 1: highlight newA[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&listNodeIndex,SQUARE,i-1,i-1,BLUE,BLUE,WHITE);
        if(i<num.value)
            graph.drawFadeIn(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);

        graph.draw(&tmpListNode2,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&tmpListNode2,SQUARE,i-1,i-1,GREEN,GREEN,WHITE);

        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,curMaxNode-1,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&listNodeA,SQUARE,i-1,i-1,GREEN,GREEN,WHITE);
        if(i<num.value)
            graph.drawFadeIn(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);

        graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&tmpListNode2.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&tmpListNode.begin()->data,"newA",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        graph.draw(&codeBox,4);
        //

        if(i==num.value) break;

        // substep 2: newA[i]=a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.draw(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);

        graph.draw(&tmpListNode2,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&tmpListNode2,SQUARE,i,i,GREEN,GREEN,WHITE);

        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,curMaxNode-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNodeA,SQUARE,i,i,GREEN,GREEN,WHITE);

        graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&tmpListNode2.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&tmpListNode.begin()->data,"newA",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        graph.draw(&codeBox,3);
        //
    }
    //

    // step 3: delete old Arr
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);

    graph.drawShrink(&tmpListNode2,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);

    graph.drawMove(&listNodeA,SQUARE,sf::Vector2f(0,-100),WHITE,BLACK,BLACK);

    graph.drawMove(&num,SQUARE,sf::Vector2f(0,-100),WHITE,BLACK,BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
    graph.drawSubscript(&tmpListNode2.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&num,"n",RED,LEFT);

    graph.draw(&codeBox,56);
    //

    return true;
}

void DArr::insertFront(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    if(checkSize()){
        commandQueue.push({INSERT_FRONT, value});
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertFront.txt");

    saveOldMem();

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
        graph.draw(&listNodeA, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
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
        graph.draw(&listNodeA, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
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
        graph.draw(&listNodeA, SQUARE, i+1, curMaxNode-1, WHITE, BLACK, BLACK);
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

    graph.draw(&codeBox,4);
    //
    //
}

void DArr::insertBack(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    if(checkSize()){
        commandQueue.push({INSERT_BACK, value});
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DArr/insertBack.txt");

    saveOldMem();

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
