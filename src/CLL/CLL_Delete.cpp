#include "CLL.h"
#include "Config.h"

using namespace Config::CLL;

void CLL::deleteFirst()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/deleteFirst.txt");

    if(listNode.empty())
    {
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return;
    }
    
    if(listNode.size()==1)
    {
        graph.addStep(0.5*FPS);

        graph.drawShrink(&listNode.begin()->data,CIRCLE,WHITE,BLACK,BLACK);
        graph.draw(&codeBox,12);

        deletedNode.push_back(listNode.popFront());
        return;
    }

    Node* deletedN=listNode.popFront();
    Arrow* deletedA=listArrow.popFront();

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    listArrow.rbegin()->data.dest=&listNode.begin()->data;

    tmpNode.position=deletedN->position;

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);

    graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,0,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);

    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);

    graph.draw(&codeBox,3);
    //

    // step 2: head=head->next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);

    graph.draw(deletedA,BLACK);
    graph.drawGrow(deletedA,ORANGE);
    graph.draw(&listArrow,0,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);

    graph.drawSubscript(deletedN,"tmp",RED);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);

    graph.draw(&codeBox,4);
    //

    // step 3: tail->next=head
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.drawMove(&tmpNode,CIRCLE,deletedN->position,listNode.begin()->data.position,BLANK,BLANK,BLANK);

    graph.draw(deletedA,ORANGE);
    graph.draw(&listArrow,0,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.drawFadeIn(&tmpArrow,ORANGE);

    graph.drawSubscript(deletedN,"tmp",RED);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);

    graph.draw(&codeBox,5);
    //

    // step 4: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);

    graph.drawShrink(deletedA,ORANGE);
    graph.draw(&listArrow,BLACK);
    graph.drawFadeOut(&listArrow,m-1,m-1,ORANGE);

    graph.drawSubscript(deletedN,"tmp",RED);
    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);

    graph.draw(&codeBox,6);
    //
}