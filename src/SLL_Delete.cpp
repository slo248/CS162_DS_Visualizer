#include "SLL.h"

void SLL::deleteWhenSingle()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/deleteFirst.txt");

    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.size()==0) return;

    graph.draw(&listNode.begin()->data,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    
    // step 1: temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: head=null
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.drawShrink(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,3);
    //

    deletedNode.push_back(listNode.popFront());
}

void SLL::deleteFirst()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/deleteFirst.txt");

    int sz=listNode.size();

    // step 1: assign temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/temp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: assign head to next node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->getNext()->data,GREEN,GREEN,WHITE);
    graph.drawFadeIn(&listArrow.begin()->data,GREEN);
    graph.drawSubscript(&listNode.begin()->data,"temp",RED);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: delete temp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,GREEN,GREEN,WHITE);
    graph.draw(&listNode,2,listNode.size()-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,1,listArrow.size()-1,BLACK);
    graph.drawShrink(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawShrink(&listArrow.begin()->data,GREEN);
    graph.drawSubscript(&listNode.begin()->data,"temp",RED);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
    graph.draw(&codeBox,3);
    //
    
    // step 4: move the rest of the list to the left
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,sf::Vector2f(-DISTANCE,0),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,2,listNode.size()-1,sf::Vector2f(-DISTANCE,0),WHITE,BLACK,BLACK);
    graph.draw(&listArrow,1,listArrow.size()-1,BLACK);
    graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
    graph.draw(&codeBox,4);
    //    

    deletedNode.push_back(listNode.popFront());
    deletedArrow.push_back(listArrow.popFront());
}

void SLL::deleteLast()
{
    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/deleteLast.txt");

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: assign pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: temp=head->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,BLACK);
    graph.drawFadeIn(&listNode.begin()->next->data,GREEN,GREEN,WHITE);
    graph.drawGrow(&listArrow.begin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
    graph.drawSubscript(&listNode.begin()->next->data,"temp",RED);
    graph.draw(&codeBox,2);
    //

    // step 3: traverse tail
    int i;
    for(i=1; i<n; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-2,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i-1,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,i,GREEN,GREEN,WHITE);
        graph.draw(&listNode,i+1,n-1,WHITE,BLACK,BLACK);
        graph.draw(&listArrow,0,i-2,ORANGE);
        graph.draw(&listArrow.begin()->getNext(i-1)->data,GREEN);
        graph.drawFadeIn(&listArrow.begin()->getNext(i-1)->data,BLACK);
        graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
        if(i==1)
            graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"pre",RED);
        }
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"temp",RED);
        graph.draw(&codeBox,3);
        //

        if(i==n-1) break;

        // substep 2
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-2,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i-1,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i-1)->data,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i,GREEN,GREEN,WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,i+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,GREEN,GREEN,WHITE);
        graph.draw(&listArrow,0,i-2,ORANGE);
        graph.draw(&listArrow,i-1,listArrow.size()-1,BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i-1)->data,ORANGE);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,GREEN);
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"pre",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,"temp",RED);
        graph.draw(&codeBox,4);
        //
    }

    // step 4: shrink the last arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-3,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,n-2,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,n-1,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,m-2,ORANGE);
    graph.drawShrink(&listArrow.begin()->getNext(m-1)->data,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"pre",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(n-1)->data,"temp",RED);
    graph.draw(&codeBox,5);
    //

    // step 5: delete temp
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-3,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,n-2,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode,n-2,n-2,GREEN,GREEN,WHITE);
    graph.drawShrink(&listNode.begin()->getNext(n-1)->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,m-2,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,6);
    //

    deletedNode.push_back(listNode.popBack());
    deletedArrow.push_back(listArrow.popBack());
}

void SLL::deleteMiddle(int pos)
{
    graph.finishAllSteps();

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
