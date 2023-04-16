#include "SLL.h"

void SLL::deleteWhenSingle()
{
    codeBox.loadFromFile("media/code/deleteFirst.txt");

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
    codeBox.loadFromFile("media/code/deleteFirst.txt");

    int sz=listNode.size();

    // step 1: assign temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/temp",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: assign head to next node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawFadeIn(&listNode.begin()->getNext()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawFadeIn(&listArrow.begin()->data,Colors::GREEN);
    graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
    graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawShrink(&listArrow.begin()->data,Colors::GREEN);
    graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
    graph.draw(&codeBox,3);
    //
    
    // step 4: move the rest of the list to the left
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,sf::Vector2f(-DISTANCE,0),Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawMove(&listNode,2,listNode.size()-1,sf::Vector2f(-DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
    graph.draw(&codeBox,4);
    //    

    deletedNode.push_back(listNode.popFront());
    deletedArrow.push_back(listArrow.popFront());
}

void SLL::deleteLast()
{
    codeBox.loadFromFile("media/code/deleteLast.txt");

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: assign pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: temp=head->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->next->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->next->data,"temp",Colors::RED);
    graph.draw(&codeBox,2);
    //

    // step 3: traverse tail
    int i;
    for(i=1; i<n; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-2,Colors::ORANGE);
        graph.draw(&listArrow.begin()->getNext(i-1)->data,Colors::GREEN);
        graph.drawFadeIn(&listArrow.begin()->getNext(i-1)->data,Colors::BLACK);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        if(i==1)
            graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"pre",Colors::RED);
        }
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"temp",Colors::RED);
        graph.draw(&codeBox,3);
        //

        if(i==n-1) break;

        // substep 2
        graph.addStep(0.5*FPS);

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
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"pre",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,"temp",Colors::RED);
        graph.draw(&codeBox,4);
        //
    }

    // step 4: shrink the last arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-3,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,n-2,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,n-1,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,m-2,Colors::ORANGE);
    graph.drawShrink(&listArrow.begin()->getNext(m-1)->data,Colors::BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"pre",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(n-1)->data,"temp",Colors::RED);
    graph.draw(&codeBox,5);
    //

    // step 5: delete temp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-3,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,n-2,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawFadeIn(&listNode,n-2,n-2,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawShrink(&listNode.begin()->getNext(n-1)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,m-2,Colors::ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    graph.draw(&codeBox,6);
    //

    deletedNode.push_back(listNode.popBack());
    deletedArrow.push_back(listArrow.popBack());
}

void SLL::deleteMiddle(int pos)
{
    codeBox.loadFromFile("media/code/deleteMiddle.txt");

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

    graph.draw(&listNode,0,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,pos,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,pos-2,Colors::BLACK);
    graph.draw(&tmpArrow,Colors::BLACK);
    graph.draw(deletedA,Colors::BLACK);
    graph.draw(&listArrow,pos,m-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: for loop
    for(int i=0; i<pos; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(deletedA,Colors::BLACK);
        graph.draw(&listArrow,pos,m-1,Colors::BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.draw(&codeBox,2);
        //
        if(i==pos-1) break;
        // substep 2
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(deletedN,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeOut(&listNode,i,i,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode,i+1,i+1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(deletedA,Colors::BLACK);
        graph.draw(&listArrow,pos,m-1,Colors::BLACK);
        graph.drawGrow(&listArrow,i,Colors::ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",Colors::RED);
        graph.draw(&codeBox,3);
        //
    }
    //
}
