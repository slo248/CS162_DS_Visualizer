#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

void DArr::deleteFirst()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/DArr/deleteFirst.txt"); 

    if(!num.value)
    {
        graph.addStep(1);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.draw(&listNodeA,SQUARE,WHITE,BLACK,BLACK);
        graph.draw(&num,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        graph.draw(&codeBox,0);
        return;
    }

    saveOldMem();

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
        graph.draw(&tmpListNode,SQUARE,i,curMaxNode-1,WHITE,BLACK,BLACK);
        if(i)
            graph.drawFadeOut(&listNodeA,SQUARE,i-1,i-1,GREEN,GREEN,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        graph.draw(&codeBox,1);
        //

        // substep 2: fade in a[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);
        
        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,curMaxNode-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        if(i<tmpNode.value-1) graph.draw(&codeBox,2);
        else graph.draw(&codeBox,3);
        //

        // substep 3: a[i]=a[i+1]
        graph.addStep(0.5*FPS);

        graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
        graph.draw(&listNodeIndex,SQUARE,i,i,BLUE,BLUE,WHITE);
        
        graph.draw(&listNodeA,SQUARE,0,i-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i+1,curMaxNode-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpListNode,SQUARE,i,i,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNodeA,SQUARE,i,i,GREEN,GREEN,WHITE);

        graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);

        graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
        graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
        graph.drawSubscript(&num,"n",RED,LEFT);

        if(i<tmpNode.value-1) graph.draw(&codeBox,1);
        else graph.draw(&codeBox,3);
        //
    }

    // step 2: n--
    // substep 1: fade in n
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
    
    graph.draw(&listNodeA,SQUARE,WHITE,BLACK,BLACK);

    graph.draw(&tmpNode,SQUARE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&tmpNode,SQUARE,ORANGE,ORANGE,WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&num,"n",RED,LEFT);

    graph.draw(&codeBox,4);
    //
    // substep 2: n--;
    graph.addStep(0.5*FPS);

    graph.draw(&listNodeIndex,SQUARE,WHITE,BLACK,BLACK);
    
    graph.draw(&listNodeA,SQUARE,WHITE,BLACK,BLACK);

    graph.draw(&tmpNode,SQUARE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&num,SQUARE,GREEN,GREEN,WHITE);

    graph.drawSubscript(&listNodeIndex.begin()->data,"index",RED,LEFT);
    graph.drawSubscript(&listNodeA.begin()->data,"a",RED,LEFT);
    graph.drawSubscript(&num,"n",RED,LEFT);

    graph.draw(&codeBox,5);
    //
}
