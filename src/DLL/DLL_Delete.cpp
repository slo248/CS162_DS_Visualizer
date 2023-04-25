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

    // step 2: head=head->next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.draw(deletedANext,BLACK);
    graph.drawGrow(deletedANext,GREEN);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(deletedN,"temp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.drawShrink(deletedANext,GREEN);
    graph.draw(&listArrowNext,BLACK);
    graph.drawShrink(deletedAPrev,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(deletedN,"temp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: move the list to the left
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode.begin()->data,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,1,listNode.size()-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,4);
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
    graph.drawSubscript(deletedN,"temp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
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

void DLL::deleteMiddle(int pos)
{
    if(listNode.size()<=1){
        deleteWhenSingle();
        return;
    }

    assert(0<pos && pos<listNode.size()-1);

    Node* deletedN=listNode.pop(pos);
    Arrow* deletedANext=listArrowNext.pop(pos);
    Arrow* deletedAPrev=listArrowPrev.pop(pos-1);

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedANext);
    deletedArrow.push_back(deletedAPrev);

    listArrowNext.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    listArrowPrev.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos-1)->data;

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
}
