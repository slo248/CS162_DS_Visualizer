#include "SLL.h"

void SLL::deleteWhenSingle()
{
    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.size()==0) return;

    graph.draw(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    
    // step 1: temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=null
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(listNode.popFront());
}

void SLL::deleteFirst()
{
    int sz=listNode.size();
    if(sz<=1){
        deleteWhenSingle();
        return;
    }

    // step 1: assign temp=head
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/temp",Colors::RED);
    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    //

    // step 2: assign head to next node
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,Colors::BLACK);
        graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawFadeIn(&listArrow.begin()->data,Colors::GREEN);
    }
    //

    // step 3: delete temp
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.draw(&listNode,1,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listNode,2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
        graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawShrink(&listArrow.begin()->data,Colors::GREEN);
    }
    else{
        graph.addStep(0.5*FPS);

        graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    }
    
    
    // step 4: move the rest of the list to the left
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.drawMove(&listNode,1,sf::Vector2f(-DISTANCE,0),Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawMove(&listNode,2,listNode.size()-1,sf::Vector2f(-DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
    }
    

    deletedNode.push_back(listNode.popFront());
    deletedArrow.push_back(listArrow.popFront());
}

void SLL::deleteLast()
{
    int sz=listNode.size();
    if(sz<=1){
        deleteWhenSingle();
        return;
    }

    const int n=listNode.size();

    // step 1: assign pre=head
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    //

    // step 2: 
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->next->data,"tail",Colors::RED);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->next->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 3: traverse tail
    int i;
    for(i=1; i<n; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        if(i==1)
            graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"pre",Colors::RED);
        }
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
        graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-2,Colors::ORANGE);
        graph.draw(&listArrow.begin()->getNext(i-1)->data,Colors::GREEN);
        graph.drawFadeIn(&listArrow.begin()->getNext(i-1)->data,Colors::BLACK);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        //

        if(i==n-1) break;

        // substep 2
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"pre",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,"tail",Colors::RED);
        graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i-1)->data,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listArrow,0,i-2,Colors::ORANGE);
        graph.draw(&listArrow,i-1,listArrow.size()-1,Colors::BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i-1)->data,Colors::ORANGE);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,Colors::GREEN);
        //
    }

    // step 4: shrink the last arrow
    graph.addStep(0.5*FPS);

    if(i>1)
        graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"tail",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
    graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,i-2,Colors::ORANGE);
    graph.drawShrink(&listArrow.begin()->getNext(i-1)->data,Colors::BLACK);
    graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
    //

    // step 5: delete tail
    graph.addStep(0.5*FPS);

    if(i>1)
        graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"tail",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
    graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawFadeIn(&listNode,0,i-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawFadeIn(&listNode.begin()->getNext(i-1)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawShrink(&listNode.begin()->getNext(i)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,i-2,Colors::ORANGE);
    graph.drawFadeIn(&listArrow,0,i-2,Colors::BLACK);
    graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
    //

    deletedNode.push_back(listNode.popBack());
    deletedArrow.push_back(listArrow.popBack());
}

void SLL::deleteMiddle(int pos)
{
    int n=listNode.size();
    if(n<=1) deleteWhenSingle();
    else if(pos==0) deleteFirst();
    else if(pos==n-1) deleteLast();
    else{
        n--;

        Node *deletedN=listNode.pop(pos);
        deletedNode.push_back(deletedN);

        Arrow *deletedA=listArrow.pop(pos);
        deletedArrow.push_back(deletedA);
        if(deletedA)
            listArrow.begin()->getNext(pos-1)->data.dest=deletedA->dest;
        else
            listArrow.begin()->getNext(pos-1)->data.dest=nullptr;

        tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
        tmpArrow.dest=deletedN;

        // step 1: assign pre=head
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
        graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(deletedA,Colors::BLACK);
        graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
        //

        // step 2: move pre to the node before the node to be deleted
        for(int i=0; i<pos-1; i++){
            graph.addStep(0.5*FPS);

            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",Colors::RED);
            graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
            graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
            graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
            graph.drawFadeOut(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
            graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
            graph.draw(&listArrow,0,i-1,Colors::ORANGE);
            graph.draw(&listArrow,i,pos-2,Colors::BLACK);
            graph.draw(&tmpArrow,Colors::BLACK);
            graph.draw(deletedA,Colors::BLACK);
            graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
            graph.drawFadeIn(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        }
        //

        // step 3: assign del=pre->next, aft=del->next
        graph.addStep(0.5*FPS);

        if(pos>1){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.drawSubscript(deletedN,std::to_string(pos)+"/del",Colors::RED);
        if(pos<n)
            graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos+1)+"/aft",Colors::RED);
        graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,pos,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(deletedN,Colors::RED,Colors::RED,Colors::WHITE);
        if(pos<n)
            graph.drawFadeIn(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);

        graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
        // graph.draw(&listArrow,pos-1,listArrow.size()-1,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(deletedA,Colors::BLACK);
        graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
        graph.drawFadeIn(&tmpArrow,Colors::ORANGE);
        graph.drawFadeIn(deletedA,Colors::ORANGE);
        //

        // step 4: pre->next=aft
        graph.addStep(0.5*FPS);

        if(pos>1){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.drawSubscript(deletedN,std::to_string(pos)+"/del",Colors::RED);
        if(pos<n)
            graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos+1)+"/aft",Colors::RED);
        graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,pos,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawMove(deletedN,sf::Vector2f(0,DISTANCE),Colors::RED,Colors::RED,Colors::WHITE);
        if(pos<n)
            graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);

        graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
        graph.drawGrow(&listArrow,pos-1,Colors::ORANGE);
        graph.draw(deletedA,Colors::ORANGE);
        graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
        //

        // step 5: delete del
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawShrink(deletedN,Colors::RED,Colors::RED,Colors::WHITE);
        if(pos<n)
            graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);

        graph.draw(&listArrow,0,pos-1,Colors::ORANGE);
        graph.drawShrink(deletedA,Colors::ORANGE);
        graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
        //

        // step 6: move nodes from the right of del to the left
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.drawFadeIn(&listNode,0,pos-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawMove(&listNode,pos+1,n-1,sf::Vector2f(-DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
        if(pos<n)
            graph.drawMove(&listNode.begin()->getNext(pos)->data,sf::Vector2f(-DISTANCE,0),Colors::GREEN,Colors::GREEN,Colors::WHITE);

        graph.draw(&listArrow,0,pos-1,Colors::ORANGE);
        graph.drawFadeIn(&listArrow,0,pos-1,Colors::BLACK);
        graph.draw(&listArrow,pos,listArrow.size()-1,Colors::BLACK);
        //
    }
}
