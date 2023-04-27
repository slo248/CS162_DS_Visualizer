#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::deleteFirst()
{
    assert(!listNodeA.empty());

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/deleteFirst.txt");    

    // remember old list
    tmpNode=num;
    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.begin()->getNext(i)->data=listNodeA.begin()->getNext(i)->data;

    // actual delete
    for(int i=0; i<num.value-1; i++)
        listNodeA.begin()->getNext(i)->data.value=listNodeA.begin()->getNext(i+1)->data.value;
    listNodeA.begin()->getNext(num.value-1)->data.value=-1;
    num.value--;

    // update graph
    // step 1: move the list to the left
    for(int i=0; i<tmpNode.value; i++)
    {
        // substep 1: fade out a[i-1]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&listNodeIndex,SQUARE,i-1,i-1,BLUE,BLUE,WHITE);
        
        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,MAX_NODE-1,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&listNodeA,SQUARE,i-1,i-1,GREEN,GREEN,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        graph.draw(&codeBox,0);
        //

        // substep 2: fade in a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);
        
        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,MAX_NODE-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        if(i<tmpNode.value-1) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,2);
        //

        // substep 3: a[i]=a[i+1]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.draw(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);
        
        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);
        graph.draw(&tmpListNode,SQUARE,i+1,MAX_NODE-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNodeA,SQUARE,i,i,GREEN,GREEN,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        if(i<tmpNode.value-1) graph.draw(&codeBox,0);
        else graph.draw(&codeBox,2);
        //
    }
}