#include "SLL.h"

void SLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/insertEmpty.txt");

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,0);
}

void SLL::insertFront(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/insertFront.txt");

    listNode.pushFront(value);
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data));
    listNode.begin()->data.position=START_POSITION+sf::Vector2f(0, DISTANCE);

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: draw new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->data,"node",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: draw new arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,1,m-1,BLACK);
    graph.drawGrow(&listArrow.begin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->data,"node",RED);
    graph.draw(&codeBox,1);
    //

    // step 3: assign head to new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,1,listNode.size()-1,WHITE,BLACK,BLACK);    
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawFadeOut(&listArrow.begin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/node",RED);
    graph.draw(&codeBox,2);
    //

    // step 4: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,listNode.size()-1,sf::Vector2f(DISTANCE, 0),WHITE,BLACK,BLACK);
    graph.drawMove(&listNode.begin()->data,START_POSITION-listNode.begin()->data.position,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/node",RED);
    graph.draw(&codeBox,3);
    //
}

void SLL::insertBack(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/insertBack.txt");

    listNode.pushBack(value);
    listArrow.pushBack(Arrow(&listNode.rbegin()->prev->data, &listNode.rbegin()->data));
    listNode.rbegin()->data.position=START_POSITION+sf::Vector2f(DISTANCE*(listNode.size()-1), 0);

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: assign tail=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,n-3,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,0);

    //

    // step 2: traverse from head to tail
    for(int i=0; i<n-1; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,n-2,WHITE,BLACK,BLACK);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,m-2,BLACK);   
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
     
        graph.draw(&codeBox,1);
        //

        if(i==n-2) break;

        // substep 2
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,n-2,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,m-2,BLACK);
        graph.drawFadeIn(&listArrow.begin()->getNext(i)->data,ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,"tail",RED);
        graph.draw(&codeBox,2);
        //
    }
    //

    // step 3: new node
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.rbegin()->data,"node",RED);
    graph.draw(&listNode,0,n-2,WHITE,ORANGE,ORANGE);
    graph.drawGrow(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,m-2,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: assign tail->next=node
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.rbegin()->data,"node",RED);
    graph.draw(&listNode,0,n-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,m-2,ORANGE);
    graph.drawGrow(&listArrow.rbegin()->data,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,4);
    //

    // step 4: move tail to node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,ORANGE,ORANGE);
    graph.drawFadeIn(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,ORANGE);
    graph.drawFadeIn(&listArrow,0,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"node/tail",RED);
    graph.draw(&codeBox,5);
    //
}

void SLL::insertMiddle(int value, int pos)
{
    if(pos<0 || pos>listNode.size()){
        std::cout << "Invalid position!" << std::endl;
        return;
    }
    if(pos==0){
        insertFront(value);
        return;
    }
    if(pos==listNode.size()){
        insertBack(value);
        return;
    }

    graph.finishAllSteps();

    codeBox.loadFromFile("media/code/insertMiddle.txt");

    listNode.insert(value,pos);
    listNode.begin()->getNext(pos)->data.position=START_POSITION+sf::Vector2f(DISTANCE*pos, DISTANCE);
    listArrow.insert(Arrow(&listNode.begin()->getNext(pos)->data, &listNode.begin()->getNext(pos+1)->data),pos);
    listArrow.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    tmpNode.position=listNode.begin()->getNext(pos+1)->data.position;
    tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: assign pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,0,pos-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
    graph.draw(&codeBox,0);
    //

    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,pos-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,0,pos-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
    graph.draw(&codeBox,1);

    // step 2: traverse to node before the insert node
    for(int i=0; i<pos-1; i++){
        // substep 1: 
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeOut(&listNode.begin()->getNext(i)->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,pos-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(&listArrow,pos+1,m-1,BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,ORANGE);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.draw(&codeBox,2);
        //

        // substep 2:
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,pos-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(&listArrow,pos+1,m-1,BLACK);
        graph.draw(&listArrow.begin()->getNext(i)->data,ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",RED);
        graph.draw(&codeBox,1);
        //
    }
    //

    // step 3: aft=pre->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->getNext(pos+1)->data,BLUE,BLUE,WHITE);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawGrow(&tmpArrow,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: vtx=new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,BLUE,BLUE,WHITE);
    graph.drawGrow(&listNode.begin()->getNext(pos)->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(&tmpArrow,ORANGE);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",RED);

    graph.draw(&codeBox,4);
    //

    // step 5: vtx->next=aft
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,BLUE,BLUE,WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(&tmpArrow,ORANGE);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawGrow(&listArrow,pos,GREEN);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",RED);
    graph.draw(&codeBox,5);
    //

    // step 6: pre->next=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,BLUE,BLUE,WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,GREEN,GREEN,WHITE);
    graph.drawMove(&tmpNode,sf::Vector2f(0,DISTANCE),BLANK,BLANK,BLANK);
    graph.draw(&listArrow,0,pos-2,ORANGE);
    graph.draw(&tmpArrow,ORANGE);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.draw(&listArrow,pos,GREEN);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos+1)+"/aft",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",RED);
    graph.draw(&codeBox,6);
    //

    // step 7: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.drawFadeIn(&listNode,0,pos-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode,pos-1,pos-1,WHITE,BLACK,BLACK);
    graph.drawMove(&listNode,pos,sf::Vector2f(0,-DISTANCE),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,pos+1,sf::Vector2f(DISTANCE,0),BLUE,BLUE,WHITE);
    graph.drawFadeIn(&listNode,pos+1,pos+1,WHITE,BLACK,BLACK);
    graph.drawMove(&listNode,pos+2,n-1,sf::Vector2f(DISTANCE,0),WHITE,BLACK,BLACK);

    graph.draw(&listArrow,0,pos-1,ORANGE);
    graph.drawFadeIn(&listArrow,0,pos-1,BLACK);
    graph.draw(&listArrow,pos,GREEN);
    graph.drawFadeIn(&listArrow,pos,pos,BLACK);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",RED);
    graph.draw(&codeBox,7);
    //
}
