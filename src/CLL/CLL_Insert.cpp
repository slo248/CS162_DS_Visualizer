#include "CLL.h"
#include "Config.h"

using namespace Config::CLL;

void CLL::insertFront(int val)
{
    if(listNode.size()==MAX_NODE) return;

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/insertFront.txt");

    listNode.pushFront(val);
    listNode.begin()->data.position=CENTER;

    if(listNode.size()==1)
    {
        // step 1: appear new node
        graph.addStep(0.5*FPS);

        graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
        graph.draw(&codeBox,0);
        //

        // step 2: head=tail=vtx
        graph.addStep(0.5*FPS);

        graph.drawMove(&listNode.begin()->data,CIRCLE,sf::Vector2f(0,-RADIUS),ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"head/tail/vtx",RED);
        graph.draw(&codeBox,12);
        //

        return;
    }

    listArrow.rbegin()->data.dest=&listNode.begin()->data;
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->getNext()->data));

    tmpNode.position=CENTER-sf::Vector2f(0,RADIUS);

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx->next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawGrow(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,4);
    //

    // step 3: tail->next=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawMove(&tmpNode,CIRCLE,sf::Vector2f(0,RADIUS),BLANK,BLANK,BLANK);
    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.drawFadeIn(&tmpArrow,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,5);
    //

    // step 4: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,6);
    //
}