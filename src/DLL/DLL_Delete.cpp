#include "DLL.h"

void DLL::deleteWhenSingle()
{
    if(listNode.empty()) return;

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/deleteWhenSingle.txt");

    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.size()==0) return;

    graph.draw(&listNode.begin()->data,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    
    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=null
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
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

    // step 1: tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawSubscript(deletedN,"head/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=head->next
    graph.addStep(0.5*FPS);

    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(deletedANext,BLACK);
    graph.drawGrow(deletedANext,GREEN);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.drawShrink(deletedANext,GREEN);
    graph.draw(&listArrowNext,BLACK);
    graph.drawShrink(deletedAPrev,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: move the list to the left
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode.begin()->data,CIRCLE,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,CIRCLE,1,listNode.size()-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
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

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawSubscript(deletedN,"tail/tmp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: assign tail to previous node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.rbegin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.drawGrow(deletedAPrev,GREEN);
    graph.drawSubscript(deletedN,"tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete tmp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.drawShrink(deletedANext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawShrink(deletedAPrev,GREEN);
    graph.drawSubscript(deletedN,"tmp",RED);
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

    graph.finishAllSteps();
    codeBox.loadFromFile("code/DLL/deleteMiddle.txt");

    Node* deletedN=listNode.pop(pos);
    Arrow* deletedANext=listArrowNext.pop(pos);
    Arrow* deletedAPrev=listArrowPrev.pop(pos-1);
    tmpArrowNext.flag=tmpArrowPrev.flag=deletedANext->flag;
    tmpArrowNext.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrowNext.dest=deletedN;
    tmpArrowPrev.src=&listNode.begin()->getNext(pos)->data;
    tmpArrowPrev.dest=deletedN;

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedANext);
    deletedArrow.push_back(deletedAPrev);

    listArrowNext.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    listArrowPrev.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos-1)->data;

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    // step 1: pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);

    graph.draw(&listArrowNext,0,pos-2,BLACK);
    graph.draw(&tmpArrowNext,BLACK);
    graph.draw(deletedANext,BLACK);
    graph.draw(&listArrowNext,pos,mNext-1,BLACK);

    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.draw(deletedAPrev,BLACK);
    graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);

    graph.draw(&codeBox,1);
    //

    // step 2: traverse to node before deleted node
    for(int i=0; i<pos; i++)
    {
        // substep 1: highlight current node
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,CIRCLE,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,i,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
        
        graph.draw(&listArrowNext,0,i-1,ORANGE);
        graph.draw(&listArrowNext,i,pos-2,BLACK);
        graph.draw(&tmpArrowNext,BLACK);
        graph.draw(deletedANext,BLACK);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);

        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&tmpArrowPrev,BLACK);
        graph.draw(deletedAPrev,BLACK);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);

        graph.draw(&codeBox,2);
        //

        if(i==pos-1) break;

        // substep 2: go next node
        graph.addStep(0.5*FPS);

        //node
        graph.draw(&listNode,CIRCLE,0,i,WHITE,ORANGE,ORANGE);
        graph.drawFadeOut(&listNode,CIRCLE,i,i,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode,CIRCLE,i+1,i+1,ORANGE,ORANGE,WHITE);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
        
        graph.draw(&listArrowNext,0,i-1,ORANGE);
        graph.draw(&listArrowNext,i,pos-2,BLACK);
        graph.drawGrow(&listArrowNext,i,i,ORANGE);
        graph.draw(&tmpArrowNext,BLACK);
        graph.draw(deletedANext,BLACK);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);

        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&tmpArrowPrev,BLACK);
        graph.draw(deletedAPrev,BLACK);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",RED);

        graph.draw(&codeBox,3);
        //
    }
    //

    // step 3: del=pre->next, aft=del->next
    graph.addStep(0.5*FPS);

        // node
        graph.draw(&listNode,CIRCLE,0,pos-2,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,pos-1,ORANGE,ORANGE,WHITE);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
        graph.drawFadeIn(deletedN,CIRCLE,RED,RED,WHITE);
        graph.draw(&listNode,CIRCLE,pos,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode,CIRCLE,pos,pos,GREEN,GREEN,WHITE);
        
        // arrow
        graph.draw(&listArrowNext,0,pos-2,ORANGE);
        graph.draw(&tmpArrowNext,BLACK);
        graph.drawGrow(&tmpArrowNext,ORANGE);
        graph.draw(deletedANext,BLACK);
        graph.drawGrow(deletedANext,ORANGE);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);
        
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(deletedAPrev,BLACK);
        graph.drawGrow(deletedAPrev,ORANGE);
        graph.draw(&tmpArrowPrev,BLACK);
        graph.drawGrow(&tmpArrowPrev,ORANGE);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        // subscript
        if(pos>1){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(deletedN,std::to_string(pos)+"/del",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos+1)+"/aft",RED);

        // codebox
        graph.draw(&codeBox,4);
    //
    
    // step 4: pre->next = aft, aft->prev = pre
    graph.addStep(0.5*FPS);

        // node
        graph.draw(&listNode,CIRCLE,0,pos-2,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,pos-1,ORANGE,ORANGE,WHITE);
        graph.drawMove(deletedN,CIRCLE,sf::Vector2f(0,-DISTANCE),RED,RED,WHITE);
        graph.draw(&listNode,CIRCLE,pos,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode,CIRCLE,pos,pos,GREEN,GREEN,WHITE);
        
        // arrow
        graph.draw(&listArrowNext,0,pos-2,ORANGE);
        graph.drawGrow(&listArrowNext,pos-1,pos-1,ORANGE);
        graph.draw(deletedANext,ORANGE);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);
        
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.drawGrow(&listArrowPrev,pos-1,pos-1,ORANGE);
        graph.draw(&tmpArrowPrev,ORANGE);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        // subscript
        if(pos>1){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(deletedN,"del",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/aft",RED);

        // codebox
        graph.draw(&codeBox,5);
    //

    // step 5: delete del
    graph.addStep(0.5*FPS);

        // node
        graph.draw(&listNode,CIRCLE,0,pos-2,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,pos-1,ORANGE,ORANGE,WHITE);
        graph.drawShrink(deletedN,CIRCLE,RED,RED,WHITE);
        graph.draw(&listNode,CIRCLE,pos,GREEN,GREEN,WHITE);
        graph.draw(&listNode,CIRCLE,pos+1,n-1,WHITE,BLACK,BLACK);
        
        // arrow
        graph.draw(&listArrowNext,0,pos-2,ORANGE);
        graph.draw(&listArrowNext,pos-1,pos-1,ORANGE);
        graph.drawShrink(deletedANext,ORANGE);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);
        
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&listArrowPrev,pos-1,pos-1,ORANGE);
        graph.drawShrink(&tmpArrowPrev,ORANGE);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        // subscript
        if(pos>1){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(deletedN,"del",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/aft",RED);

        // codebox
        graph.draw(&codeBox,6);
    //

    // step 6: normal the list
    graph.addStep(0.5*FPS);

        // node
        graph.draw(&listNode,CIRCLE,0,pos-2,WHITE,ORANGE,ORANGE);
        graph.drawFadeIn(&listNode,CIRCLE,0,pos-2,WHITE,BLACK,BLACK);
        graph.draw(&listNode,CIRCLE,pos-1,ORANGE,ORANGE,WHITE);
        graph.drawMove(&listNode,CIRCLE,pos,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
        graph.drawMove(&listNode,CIRCLE,pos+1,n-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
        
        // arrow
        graph.draw(&listArrowNext,0,pos-1,ORANGE);
        graph.drawFadeIn(&listArrowNext,0,pos-1,BLACK);
        graph.draw(&listArrowNext,pos,mNext-1,BLACK);
        
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&listArrowPrev,pos-1,pos-1,ORANGE);
        graph.drawFadeIn(&listArrowPrev,pos-1,pos-1,BLACK);
        graph.draw(&listArrowPrev,pos,mPrev-1,BLACK);

        // subscript
        graph.drawSubscript(&listNode.begin()->data,"head",RED);

        // codebox
        graph.draw(&codeBox,7);
    //
}
