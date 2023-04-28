#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

void DArr::checkSize()
{
    if(num.value<curMaxNode) return;

    // actually allocate new array with size double of current size

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
    }
    //

    // update graph
    // step 1: create new Arr
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNodeIndex,SQUARE,curMaxNode>>1,curMaxNode-1,WHITE,BLACK,BLACK);

    graph.draw(&listNodeA,SQUARE,0,(curMaxNode>>1)-1,WHITE,BLACK,BLACK);

    graph.drawGrow(&tmpListNode,SQUARE,0,curMaxNode-1,WHITE,BLACK,BLACK);

    num.position+=sf::Vector2f(0,100);
    graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&tmpListNode.begin()->data,"newA",RED,LEFT);
    graph.drawSubscript(&num,"n",RED,LEFT);
    //
    //
}