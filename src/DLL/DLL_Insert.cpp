#include "DLL.h"
#include "Config.h"

void DLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/insertWhenEmpty.txt");

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,WHITE,BLACK,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.draw(&codeBox,0);
}

void DLL::insertFront(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/insertFront.txt");

    listNode.pushFront(value);
    listNode.begin()->data.position=START_POSITION+sf::Vector2f(0, DISTANCE);
    listArrowNext.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data, true));
    listArrowPrev.pushFront(Arrow(&listNode.begin()->next->data, &listNode.begin()->data, true));

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,1,mPrev-1,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx.next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawGrow(&listArrowNext.begin()->data,ORANGE);
    graph.draw(&listArrowNext,1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,1,mPrev-1,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,1);
    //

    // step 3: head.prev=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext.begin()->data,ORANGE);
    graph.draw(&listArrowNext,1,mNext-1,BLACK);
    graph.drawGrow(&listArrowPrev.begin()->data,ORANGE);
    graph.draw(&listArrowPrev,1,mPrev-1,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->next->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
    graph.draw(&codeBox,2);
    //

    // step 4: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrowNext.begin()->data,ORANGE);
    graph.drawFadeIn(&listArrowNext.begin()->data,BLACK);
    graph.draw(&listArrowNext,1,mNext-1,BLACK);
    graph.draw(&listArrowPrev.begin()->data,ORANGE);
    graph.drawFadeIn(&listArrowPrev.begin()->data,BLACK);
    graph.draw(&listArrowPrev,1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,3);
    //

    // step 5: move the list to correct position
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,n-1,sf::Vector2f(DISTANCE,0),WHITE,BLACK,BLACK);
    graph.drawMove(&listNode.begin()->data,sf::Vector2f(0,-DISTANCE),GREEN,GREEN,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,4);
    //
}

void DLL::insertBack(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/insertBack.txt");

    listNode.pushBack(value);
    listArrowNext.pushBack(Arrow(&listNode.rbegin()->prev->data, &listNode.rbegin()->data, true));
    listArrowPrev.pushBack(Arrow(&listNode.rbegin()->data, &listNode.rbegin()->prev->data, true));
}
/*
void DLL::insertMiddle(int pos, int value)
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

    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/insertMiddle.txt");

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
        graph.draw(&listArrow,0,i,ORANGE);
        graph.draw(&listArrow,i+1,pos-2,BLACK);
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
    if(pos>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
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
    if(pos>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
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
    if(pos>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
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
    if(pos>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
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
*/