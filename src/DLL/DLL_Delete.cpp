#include "DLL.h"

void DLL::deleteWhenSingle()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/deleteWhenSingle.txt");

    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.size()==0) return;

    graph.draw(&listNode.begin()->data,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    
    // step 1: temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=null
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.drawShrink(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(listNode.popFront());
}

void DLL::deleteFirst()
{
    if(listNode.size()<=1){
        deleteWhenSingle();
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DLL/deleteFirst.txt");

    Node* deletedN=listNode.popFront();
    Arrow* deletedANext=listArrowNext.popFront();
    Arrow* deletedAPrev=listArrowPrev.popFront();

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedANext);
    deletedArrow.push_back(deletedAPrev); 

    // step 1: temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawSubscript(deletedN,"head/temp",RED);
    graph.draw(&codeBox,1);
    //
}

void DLL::deleteLast()
{
    if(listNode.size()<=1){
        deleteWhenSingle();
        return;
    }

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DLL/deleteLast.txt");

    Node* deletedN=listNode.popBack();
    Arrow* deletedANext=listArrowNext.popBack();
    Arrow* deletedAPrev=listArrowPrev.popBack();

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedANext);
    deletedArrow.push_back(deletedAPrev);

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    // step 1: assign tmp=tail
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawSubscript(deletedN,"tail/temp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: assign tail to previous node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.draw(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawGrow(deletedAPrev,GREEN);
    graph.drawSubscript(deletedN,"tail/temp",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.drawShrink(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.drawShrink(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawShrink(deletedAPrev,GREEN);
    graph.drawSubscript(deletedN,"temp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,3);
    //
}
/*
void DLL::deleteMiddle(int pos)
{
    if(listNode.size()<=1){
        deleteWhenSingle();
        return;
    }

    assert(1<pos && pos<listNode.size()-1);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/deleteMiddle.txt");

    Node* deletedN=listNode.pop(pos);
    Arrow* deletedA=listArrow.pop(pos);
    listArrow.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrow.dest=deletedN;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,pos,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: for loop
    for(int i=0; i<pos; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(deletedN,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos,n-1,WHITE,BLACK,BLACK);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,pos-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(deletedA,BLACK);
        graph.draw(&listArrow,pos,m-1,BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.draw(&codeBox,2);
        //
        if(i==pos-1) break;
        // substep 2
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(deletedN,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeOut(&listNode,i,i,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode,i+1,i+1,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,pos-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(deletedA,BLACK);
        graph.draw(&listArrow,pos,m-1,BLACK);
        graph.drawGrow(&listArrow,i,ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",RED);
        graph.draw(&codeBox,3);
        //
    }
    //

    // step 3: del=pre->next, aft=del->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(deletedN,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos,n-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,RED,RED,WHITE);
    graph.drawFadeIn(&listNode,pos,pos,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(deletedA,BLACK);
    graph.draw(&listArrow,pos,m-1,BLACK);
    graph.drawGrow(&tmpArrow,ORANGE);
    graph.drawGrow(deletedA,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(deletedN,std::to_string(pos)+"/del",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos+1)+"/aft",RED);
    graph.draw(&codeBox,4);
    //

    // step 4: pre->next=aft
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawMove(deletedN,sf::Vector2f(0,DISTANCE),RED,RED,WHITE);
    graph.draw(&listNode,pos,GREEN,GREEN,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(deletedA,ORANGE);
    graph.draw(&listArrow,pos,m-1,BLACK);
    graph.drawGrow(&listArrow,pos-1,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(deletedN,"del",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/aft",RED);
    graph.draw(&codeBox,5);
    //

    // step 5: delete del
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawShrink(deletedN,RED,RED,WHITE);
    graph.draw(&listNode,pos,GREEN,GREEN,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-1,ORANGE);
    graph.draw(&listArrow,pos,m-1,BLACK);
    graph.drawShrink(deletedA,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,6);
    //

    // step 6: normalize
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawMove(&listNode,pos,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,pos+1,n-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode,0,pos-2,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-1,ORANGE);
    graph.draw(&listArrow,pos,m-1,BLACK);
    graph.drawFadeIn(&listArrow,0,pos-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,7);
    //
}
*/