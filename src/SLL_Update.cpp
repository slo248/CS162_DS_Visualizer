#include "SLL.h"

void SLL::update(int pos, int newValue)
{
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

    graph.draw(&listNode,0,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&tmpNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    if(pos)
        graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    else
        graph.drawFadeIn(&tmpNode,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/cur",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: while index<pos
    for(int i=0; i<pos; i++){
        // substep 1: change color of cur
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&tmpNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeOut(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/cur",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/cur",Colors::RED);
        graph.draw(&codeBox,2);
        //

        // substep 2: cur=cur->next, index++
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&tmpNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        if(i<pos-1)
            graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        else
            graph.drawFadeIn(&tmpNode,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        graph.drawFadeIn(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/cur",Colors::RED);
        graph.draw(&codeBox,3);
        //
    }
    //

    // step 3: cur->value=newValue
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&tmpNode,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawFadeIn(&listNode,0,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,pos-1,Colors::ORANGE);
    graph.drawFadeIn(&listArrow,0,pos-1,Colors::BLACK);
    graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
    if(pos>0){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/cur",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/cur",Colors::RED);
    graph.draw(&codeBox,4);
    //
}
