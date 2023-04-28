#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

void DArr::checkSize()
{
    if(num.value<curMaxNode) return;

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
        //
    }
    //
}