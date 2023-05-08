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
    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeOut(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);

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

    // step 5: organizing the list
    graph.addStep(0.5*FPS);

    float preAngle=2*acos(-1)/(n+1);
    float curAngle=2*acos(-1)/n;
    for(int i=0; i<n; i++){
        Node &node=listNode.begin()->getNext(i)->data;
        graph.drawMove(&node,CIRCLE,CENTER,0,i*curAngle-(i+1)*preAngle,WHITE,BLACK,BLACK);
    }

    graph.draw(&listArrow,BLACK);

    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);

    graph.draw(&codeBox,7);
    //
}

void CLL::deleteLast()
{
    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/deleteLast.txt");

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

    Node* deletedN=listNode.popBack();
    Arrow* deletedA=listArrow.popBack();

    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    listArrow.rbegin()->data.dest=&listNode.begin()->data;

    tmpNode.position=deletedN->position;

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: traverse to the node before the last node
    for(int i=0; i<=n; i++)
    {
        // substep 1: highlight current node and lowlight previous node
        graph.addStep(0.5*FPS);
        
        graph.draw(&listNode,CIRCLE,0,i-1,WHITE,ORANGE,ORANGE);
        graph.drawFadeOut(&listNode,CIRCLE,i-1,i-1,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i,n-1,WHITE,BLACK,BLACK);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);
        if(i<n)
            graph.drawFadeIn(&listNode,CIRCLE,i,i,ORANGE,ORANGE,WHITE);
        else
            graph.drawFadeIn(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);

        if(i<n){
            graph.draw(&listArrow,0,i-1,ORANGE);
            graph.draw(&listArrow,i,m-2,BLACK);
            graph.draw(&tmpArrow,BLACK);
            graph.draw(deletedA,BLACK);
        }
        else{
            graph.draw(&listArrow,0,m-2,ORANGE);
            graph.draw(&tmpArrow,ORANGE);
            graph.draw(deletedA,BLACK);
        }

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,"pre",RED);
        }
        else 
            graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
        graph.drawSubscript(deletedN,"tail",RED);

        if(i) graph.draw(&codeBox,4); else graph.draw(&codeBox,34);
        //

        if(i==n) break;

        // substep 2: move to next node
        graph.addStep(0.5*FPS);
        
        graph.draw(&listNode,CIRCLE,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,i,i,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);

        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,m-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(deletedA,BLACK);
        if(i==n-1) graph.drawGrow(&tmpArrow,ORANGE);
        else graph.drawGrow(&listArrow,i,i,ORANGE);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,"pre",RED);
        }
        else 
            graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
        graph.drawSubscript(deletedN,"tail",RED);

        graph.draw(&codeBox,5);
        //
    }
    //

    // step 2: pre->next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,ORANGE,ORANGE);
    graph.draw(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawMove(&tmpNode,CIRCLE,deletedN->position,listNode.begin()->data.position,BLANK,BLANK,BLANK);
    
    graph.draw(&listArrow,0,m-2,ORANGE);
    graph.draw(&tmpArrow,ORANGE);
    graph.draw(deletedA,BLACK);

    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"pre",RED);
    graph.drawSubscript(deletedN,"tail",RED);

    graph.draw(&codeBox,6);
    //

    // step 3: delete tail, tail=pre
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,ORANGE,ORANGE);
    graph.drawFadeIn(&listNode,CIRCLE,0,n-1,WHITE,BLACK,BLACK);
    graph.drawShrink(deletedN,CIRCLE,ORANGE,ORANGE,WHITE);
    
    graph.draw(&listArrow,ORANGE);
    graph.drawFadeIn(&listArrow,0,m-1,BLACK);
    graph.drawShrink(deletedA,BLACK);

    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);

    graph.draw(&codeBox,7);
    //

    // step 4: organinze list
    graph.addStep(0.5*FPS);

    float preAngle=2*acos(-1)/(n+1);
    float curAngle=2*acos(-1)/n;
    for(int i=0; i<n; i++){
        Node &node=listNode.begin()->getNext(i)->data;
        graph.drawMove(&node,CIRCLE,CENTER,0,i*(curAngle-preAngle),WHITE,BLACK,BLACK);
    }

    graph.draw(&listArrow,BLACK);

    if(n>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);

    graph.draw(&codeBox,8);
    //
}

void CLL::deleteMiddle(int pos)
{
    if(!(0<pos && pos<listNode.size()))
        throw std::out_of_range("CLL::insertMiddle() : pos out of range");
    
    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/deleteMiddle.txt");

    Node* deletedN=listNode.pop(pos);
    Arrow* deletedA=listArrow.pop(pos);
    deletedNode.push_back(deletedN);
    deletedArrow.push_back(deletedA);

    listArrow.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;

    tmpNode.position=deletedN->position;

    tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // graph.addStep(1);
    // graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    // graph.draw(&listArrow,BLACK);
    // graph.draw(&tmpArrow,BLACK);

    // step 1: traverse to node before deleted node
    for(int i=0; i<pos; i++)
    {
        // substep 1: highlight cur node and lowlight pre node
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,CIRCLE,0,i-1,WHITE,ORANGE,ORANGE);
        graph.drawFadeOut(&listNode,CIRCLE,i-1,i-1,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode,CIRCLE,i,i,ORANGE,ORANGE,WHITE);
        graph.draw(deletedN,CIRCLE,WHITE,BLACK,BLACK);

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

        if(i) graph.draw(&codeBox,2); else graph.draw(&codeBox,12);
        //

        if(i==pos-1) break;
    }
    //
}
