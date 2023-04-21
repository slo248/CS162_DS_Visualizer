#include "SLL.h"

void SLL::update(int pos, int newValue)
{
    if(pos<0 || pos>=listNode.size()) return;

    assert(0<=pos && pos<listNode.size());
    assert(0<=newValue && newValue<100);

    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/update.txt");

    int n=listNode.size();
    if(n==0 || pos<0 || pos>=n){ 
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return;
    }

    tmpNode.value=listNode.begin()->getNext(pos)->data.value;
    tmpNode.position=listNode.begin()->getNext(pos)->data.position;
    listNode.begin()->getNext(pos)->data.value=newValue;

    // step 1: assign cur=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,WHITE,BLACK,BLACK);
    graph.draw(&tmpNode,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    if(pos)
        graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    else
        graph.drawFadeIn(&tmpNode,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/cur",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: while index<pos
    for(int i=0; i<pos; i++){
        // substep 1: change color of cur
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpNode,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeOut(&listNode.begin()->getNext(i)->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/cur",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/cur",RED);
        graph.draw(&codeBox,2);
        //

        // substep 2: cur=cur->next, index++
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&tmpNode,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        if(i<pos-1)
            graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,ORANGE,ORANGE,WHITE);
        else
            graph.drawFadeIn(&tmpNode,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/cur",RED);
        graph.draw(&codeBox,3);
        //
    }
    //

    // step 3: cur->value=newValue
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,WHITE,ORANGE,ORANGE);
    graph.draw(&tmpNode,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->getNext(pos)->data,GREEN,GREEN,WHITE);
    graph.drawFadeIn(&listNode,0,pos-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-1,ORANGE);
    graph.drawFadeIn(&listArrow,0,pos-1,BLACK);
    graph.draw(&listArrow,pos,listArrow.size()-1,BLACK);
    if(pos>0){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/cur",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/cur",RED);
    graph.draw(&codeBox,4);
    //
}
