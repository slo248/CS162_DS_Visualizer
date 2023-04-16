#include "SLL.h"

void SLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
}

void SLL::insertFront(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    listNode.pushFront(value);
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data));
    listNode.begin()->data.position=START_POSITION+sf::Vector2f(0, DISTANCE);

    // step 1: draw new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.drawGrow(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->next->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"vtx",Colors::RED);
    graph.draw(&codeBox,0);
    //

    // step 2: draw new arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    graph.drawSubscript(&listNode.begin()->next->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"vtx",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 3: assign head to new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);    
    graph.drawFadeIn(&listNode.begin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeOut(&listArrow.begin()->data,Colors::ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/vtx",Colors::RED);
    graph.draw(&codeBox,2);
    //

    // step 4: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,listNode.size()-1,sf::Vector2f(DISTANCE, 0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawMove(&listNode.begin()->data,START_POSITION-listNode.begin()->data.position,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/vtx",Colors::RED);
    graph.draw(&codeBox,3);
    //
}

void SLL::insertBack(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    listNode.pushBack(value);
    listArrow.pushBack(Arrow(&listNode.rbegin()->prev->data, &listNode.rbegin()->data));
    listNode.rbegin()->data.position=START_POSITION+sf::Vector2f(DISTANCE*(listNode.size()-1), 0);

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: assign tail=head
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    graph.draw(&listNode,0,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,n-3,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&codeBox,0);

    //

    // step 2: traverse from head to tail
    for(int i=0; i<n-1; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,m-2,Colors::BLACK);        
        graph.draw(&codeBox,1);
        //

        if(i==n-2) break;

        // substep 2
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,"tail",Colors::RED);
        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,m-2,Colors::BLACK);
        graph.drawFadeIn(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        graph.draw(&codeBox,2);
        //
    }
    //

    // step 3: new node
    graph.addStep(0.5*FPS);

    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    graph.drawSubscript(&listNode.rbegin()->data,"node",Colors::RED);
    graph.draw(&listNode,0,n-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawGrow(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,m-2,Colors::ORANGE);
    graph.draw(&codeBox,3);
    //

    // step 4: assign tail->next=node
    graph.addStep(0.5*FPS);

    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(n-2)->data,"tail",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    graph.drawSubscript(&listNode.rbegin()->data,"node",Colors::RED);
    graph.draw(&listNode,0,n-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,m-2,Colors::ORANGE);
    graph.drawGrow(&listArrow.rbegin()->data,Colors::ORANGE);
    graph.draw(&codeBox,4);
    //

    // step 4: move tail to node
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.rbegin()->data,"node/tail",Colors::RED);
    graph.draw(&listNode,0,n-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawFadeIn(&listNode,0,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::ORANGE);
    graph.drawFadeIn(&listArrow,0,m-1,Colors::BLACK);
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

    graph.draw(&listNode,0,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,0,pos-2,Colors::BLACK);
    graph.draw(&tmpArrow,Colors::BLACK);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
    graph.draw(&codeBox,0);
    //

    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,0,pos-2,Colors::BLACK);
    graph.draw(&tmpArrow,Colors::BLACK);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
    graph.draw(&codeBox,1);

    // step 2: traverse to node before the insert node
    for(int i=0; i<pos-1; i++){
        // substep 1: 
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeOut(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.draw(&codeBox,2);
        //

        // substep 2:
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
        graph.draw(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/pre",Colors::RED);
        graph.draw(&codeBox,1);
        //
    }
    //

    // step 3: aft=pre->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,pos+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::BLACK);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawGrow(&tmpArrow,Colors::ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",Colors::RED);
    graph.draw(&codeBox,3);
    //

    // step 4: vtx=new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,pos+2,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.drawGrow(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",Colors::RED);

    graph.draw(&codeBox,4);
    //

    // step 5: vtx->next=aft
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,pos+2,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawGrow(&listArrow,pos,Colors::GREEN);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",Colors::RED);
    graph.draw(&codeBox,5);
    //

    // step 6: pre->next=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,pos+2,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawMove(&tmpNode,sf::Vector2f(0,DISTANCE),Colors::BLANK,Colors::BLANK,Colors::BLANK);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.draw(&listArrow,pos,Colors::GREEN);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos+1)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",Colors::RED);
    graph.draw(&codeBox,6);
    //

    // step 7: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawFadeIn(&listNode,0,pos-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawFadeIn(&listNode,pos-1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawMove(&listNode,pos,sf::Vector2f(0,-DISTANCE),Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawMove(&listNode,pos+1,sf::Vector2f(DISTANCE,0),Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.drawFadeIn(&listNode,pos+1,pos+1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawMove(&listNode,pos+2,n-1,sf::Vector2f(DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);

    graph.draw(&listArrow,0,pos-1,Colors::ORANGE);
    graph.drawFadeIn(&listArrow,0,pos-1,Colors::BLACK);
    graph.draw(&listArrow,pos,Colors::GREEN);
    graph.drawFadeIn(&listArrow,pos,pos,Colors::BLACK);
    graph.draw(&listArrow,pos+1,m-1,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",Colors::RED);
    graph.draw(&codeBox,7);
    //
}
