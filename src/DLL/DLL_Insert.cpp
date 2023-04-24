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

    // step 2: vtx.next=head, head.prev=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.drawGrow(&listArrowNext.begin()->data,ORANGE);
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
    graph.draw(&codeBox,12);
    //

    // step 3: head=vtx
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

    // step 4: move the list to correct position
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
    listNode.rbegin()->data.position=listNode.rbegin()->prev->data.position+sf::Vector2f(DISTANCE,0);
    listArrowNext.pushBack(Arrow(&listNode.rbegin()->prev->data, &listNode.rbegin()->data, true));
    listArrowPrev.pushBack(Arrow(&listNode.rbegin()->data, &listNode.rbegin()->prev->data, true));

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    // step 1: create new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.rbegin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,0,mNext-2,BLACK);
    graph.draw(&listArrowPrev,0,mPrev-2,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"vtx",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: tail.next = vtx, vtx.prev = tail
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.rbegin()->prev->data,GREEN,GREEN,WHITE);
    graph.draw(&listNode.rbegin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,0,mNext-2,BLACK);
    graph.drawGrow(&listArrowNext.rbegin()->data,ORANGE);
    graph.draw(&listArrowPrev,0,mPrev-2,BLACK);
    graph.drawGrow(&listArrowPrev.rbegin()->data,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"vtx",RED);
    graph.draw(&codeBox,12);
    //

    // step 3: vtx = tail
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,n-2,WHITE,BLACK,BLACK);
    graph.drawFadeOut(&listNode.rbegin()->prev->data,GREEN,GREEN,WHITE);
    graph.draw(&listNode.rbegin()->data,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.rbegin()->data,GREEN,GREEN,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.drawFadeOut(&listArrowNext.rbegin()->data,ORANGE);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawFadeOut(&listArrowPrev.rbegin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,3);
    //
}

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
}
