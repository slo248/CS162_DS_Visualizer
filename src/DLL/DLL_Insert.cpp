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

    assert(0<pos && pos<listNode.size());
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/insertMiddle.txt");
    // actual
    listNode.insert(value,pos);
    listNode.begin()->getNext(pos)->data.position=listNode.begin()->getNext(pos+1)->data.position+sf::Vector2f(0,DISTANCE);
    listArrowNext.insert(Arrow(&listNode.begin()->getNext(pos)->data, &listNode.begin()->getNext(pos+1)->data, true),pos);
    listArrowPrev.insert(Arrow(&listNode.begin()->getNext(pos)->data, &listNode.begin()->getNext(pos-1)->data, true),pos-1);

    listArrowNext.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    listArrowPrev.begin()->getNext(pos)->data.dest=&listNode.begin()->getNext(pos)->data;
    //
    tmpNode.position=listNode.begin()->getNext(pos+1)->data.position;
    tmpArrowNext.flag=tmpArrowPrev.flag=true;
    tmpArrowNext.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrowNext.dest=&tmpNode;
    tmpArrowPrev.src=&tmpNode;
    tmpArrowPrev.dest=&listNode.begin()->getNext(pos-1)->data;

    const int n=listNode.size();
    const int mNext=listArrowNext.size();
    const int mPrev=listArrowPrev.size();

    // step 1: pre=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,0,pos-2,BLACK);
    graph.draw(&tmpArrowNext,BLACK);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: traverse to before pos
    for(int i=0; i<pos; i++){
        // substep 1: fade in node[i]
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,WHITE,ORANGE,ORANGE);
        if(i){
            graph.draw(&listNode.begin()->getNext(i)->data,WHITE,BLACK,BLACK);
            graph.drawFadeIn(&listNode.begin()->getNext(i)->data,ORANGE,ORANGE,WHITE);
        }
        else
            graph.draw(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.draw(&listArrowNext,0,i-1,ORANGE);
        graph.draw(&listArrowNext,i,pos-2,BLACK);
        graph.draw(&tmpArrowNext,BLACK);
        graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&tmpArrowPrev,BLACK);
        graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
        graph.draw(&codeBox,1);
        //

        if(i==pos-1) break;
        
        // step 2: pre=pre->next
        graph.addStep(0.5*FPS);

        graph.draw(&listNode,0,i-1,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode.begin()->getNext(i)->data,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.draw(&listArrowNext,0,i-1,ORANGE);
        graph.draw(&listArrowNext,i,pos-2,BLACK);
        graph.drawGrow(&listArrowNext,i,ORANGE);
        graph.draw(&tmpArrowNext,BLACK);
        graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
        graph.draw(&listArrowPrev,0,pos-2,BLACK);
        graph.draw(&tmpArrowPrev,BLACK);
        graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"pre",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
        graph.draw(&codeBox,2);
        //
    }
    //

    // step 3: aft=pre->next
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode,pos+1,pos+1,BLUE,BLUE,WHITE);
    graph.draw(&listArrowNext,0,pos-2,ORANGE);
    graph.draw(&tmpArrowNext,BLACK);
    graph.drawGrow(&tmpArrowNext,ORANGE);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    if(pos+1<n-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos)+"/tail/aft",RED);
    graph.draw(&codeBox,3);
    //

    // step 4: create new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawGrow(&listNode,pos,GREEN,GREEN,WHITE);
    graph.draw(&listNode,pos+1,BLUE,BLUE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,0,pos-2,ORANGE);
    graph.draw(&tmpArrowNext,ORANGE);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",RED);
    if(pos+1<n-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos)+"/tail/aft",RED);
    graph.draw(&codeBox,4);
    //

    // step 5: vtx.next = aft, aft.prev = vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos,GREEN,GREEN,WHITE);
    graph.draw(&listNode,pos+1,BLUE,BLUE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,0,pos-2,ORANGE);
    graph.draw(&tmpArrowNext,ORANGE);
    graph.drawGrow(&listArrowNext,pos,GREEN);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.drawGrow(&listArrowPrev,pos,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",RED);
    if(pos+1<n-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos)+"/tail/aft",RED);
    graph.draw(&codeBox,5);
    //

    // step 6: pre.next = vtx, vtx.prev = pre
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,pos,GREEN,GREEN,WHITE);
    graph.draw(&listNode,pos+1,BLUE,BLUE,WHITE);
    graph.draw(&listNode,pos+2,n-1,WHITE,BLACK,BLACK);
    graph.drawMove(&tmpNode,sf::Vector2f(0,DISTANCE),BLANK,BLANK,BLANK);
    graph.draw(&listArrowNext,0,pos-2,ORANGE);
    graph.draw(&tmpArrowNext,ORANGE);
    graph.draw(&listArrowNext,pos,GREEN);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-2,BLACK);
    graph.draw(&tmpArrowPrev,BLACK);
    graph.draw(&listArrowPrev,pos,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"/pre",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",RED);
    if(pos+1<n-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos+1)+"/aft",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos+1)+"/tail/aft",RED);
    graph.draw(&codeBox,6);
    //

    // step 7: move the new node to correct position
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,0,pos-2,WHITE,ORANGE,ORANGE);
    graph.drawFadeIn(&listNode,0,pos-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode,pos-1,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode,pos-1,pos-1,WHITE,BLACK,BLACK);
    graph.drawMove(&listNode,pos,sf::Vector2f(0,-DISTANCE),GREEN,GREEN,WHITE);
    graph.drawMove(&listNode,pos+1,sf::Vector2f(DISTANCE,0),BLUE,BLUE,WHITE);
    graph.drawFadeIn(&listNode,pos+1,pos+1,WHITE,BLACK,BLACK);
    graph.drawMove(&listNode,pos+2,n-1,sf::Vector2f(DISTANCE,0),WHITE,BLACK,BLACK);
    graph.draw(&listArrowNext,0,pos-1,ORANGE);
    graph.drawFadeIn(&listArrowNext,0,pos-1,BLACK);
    graph.draw(&listArrowNext,pos,GREEN);
    graph.drawFadeIn(&listArrowNext,pos,pos,BLACK);
    graph.draw(&listArrowNext,pos+1,mNext-1,BLACK);
    graph.draw(&listArrowPrev,0,pos-1,BLACK);
    graph.draw(&listArrowPrev,pos,BLACK);
    graph.draw(&listArrowPrev,pos+1,mPrev-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,7);
    //
}
