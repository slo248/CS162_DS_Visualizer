#include "CLL.h"
#include "Config.h"

using namespace Config::CLL;

void CLL::insertFront(int value)
{
    if(listNode.size()==MAX_NODE) return;

    if(value<Config::MIN_VALUE && value>Config::MAX_VALUE)
        throw std::out_of_range("CLL::insertMiddle() : value out of range");

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/insertFront.txt");

    sf::Vector2f insPos;
    if(listNode.size()<=2) insPos=INSF_POS_LESS;
    else insPos=CENTER;

    listNode.pushFront(value);
    listNode.begin()->data.position=insPos;

    if(listNode.size()==1)
    {
        listArrow.pushBack(Arrow(&listNode.begin()->data, &listNode.begin()->data));

        // step 1: appear new node
        graph.addStep(0.5*FPS);

        graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
        graph.draw(&codeBox,0);
        //

        // step 2: head=tail=vtx
        graph.addStep(0.5*FPS);

        graph.drawMove(&listNode.begin()->data,CIRCLE,CENTER-sf::Vector2f(0,RADIUS)-insPos,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"head/tail/vtx",RED);
        graph.draw(&codeBox,12);
        //

        return;
    }

    listArrow.rbegin()->data.dest=&listNode.begin()->data;
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->getNext()->data));

    tmpNode.position=CENTER-sf::Vector2f(0,RADIUS);

    tmpArrow.src=&listNode.rbegin()->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx->next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawGrow(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,4);
    //

    // step 3: tail->next=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawMove(&tmpNode,CIRCLE,insPos-(CENTER-sf::Vector2f(0,RADIUS)),BLANK,BLANK,BLANK);
    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.drawFadeIn(&tmpArrow,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.begin()->data,"tmp",RED);
    graph.draw(&codeBox,5);
    //

    // step 4: head=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&tmpArrow,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head/tmp",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.draw(&codeBox,6);
    //

    // step 5: move to correct position
    graph.addStep(0.5*FPS);

    float preAngle=2*acos(-1)/(n-1);
    float curAngle=2*acos(-1)/n;
    for(int i=1; i<n; i++){
        Node &node=listNode.begin()->getNext(i)->data;
        graph.drawMove(&node,CIRCLE,CENTER,0,i*curAngle-(i-1)*preAngle,WHITE,BLACK,BLACK);
    }
    graph.drawMove(&listNode.begin()->data,CIRCLE,CENTER-sf::Vector2f(0,RADIUS)-insPos,GREEN,GREEN,WHITE);

    graph.draw(&listArrow.begin()->data,ORANGE);
    graph.drawFadeIn(&listArrow.begin()->data,BLACK);
    graph.draw(&listArrow,1,m-2,BLACK);
    graph.draw(&listArrow,m-1,ORANGE);
    graph.drawFadeIn(&listArrow,m-1,m-1,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);

    graph.draw(&codeBox,9);
    //
}

void CLL::insertBack(int value)
{
    if(listNode.size()==MAX_NODE) return;

    if(value<Config::MIN_VALUE && value>Config::MAX_VALUE)
        throw std::out_of_range("CLL::insertMiddle() : value out of range");

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/insertBack.txt");

    sf::Vector2f insPos;
    if(listNode.size()<=2) insPos=INSB_POS_LESS;
    else insPos=CENTER;

    listNode.pushBack(value);
    listNode.rbegin()->data.position=insPos;

    if(listNode.size()==1)
    {
        listArrow.pushBack(Arrow(&listNode.begin()->data, &listNode.begin()->data));

        // step 1: appear new node
        graph.addStep(0.5*FPS);

        graph.drawGrow(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"vtx",RED);
        graph.draw(&codeBox,0);
        //

        // step 2: head=tail=vtx
        graph.addStep(0.5*FPS);

        graph.drawMove(&listNode.begin()->data,CIRCLE,CENTER-sf::Vector2f(0,RADIUS)-insPos,ORANGE,ORANGE,WHITE);
        graph.drawFadeIn(&listNode.begin()->data,CIRCLE,GREEN,GREEN,WHITE);
        graph.drawSubscript(&listNode.begin()->data,"head/tail/vtx",RED);
        graph.draw(&codeBox,12);
        //

        return;
    }

    listArrow.rbegin()->data.dest=&listNode.rbegin()->data;
    listArrow.pushBack(Arrow(&listNode.rbegin()->data, &listNode.begin()->data));

    tmpNode.position=listNode.begin()->data.position;

    tmpArrow.src=&listNode.rbegin()->prev->data;
    tmpArrow.dest=&tmpNode;

    const int n=listNode.size();
    const int m=listArrow.size();

    // step 1: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,0,n-2,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.rbegin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,0,m-3,BLACK);
    graph.draw(&tmpArrow,BLACK);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tmp",RED);
    graph.draw(&codeBox,0);
    //

    // step 2: vtx->next=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,0,n-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,0,m-3,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.drawGrow(&listArrow.rbegin()->data,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tmp",RED);
    graph.draw(&codeBox,4);
    //

    // step 3: tail->next=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,0,n-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawMove(&tmpNode,CIRCLE,insPos-(CENTER-sf::Vector2f(0,RADIUS)),BLANK,BLANK,BLANK);
    graph.draw(&listArrow,0,m-3,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.drawFadeIn(&tmpArrow,ORANGE);
    graph.draw(&listArrow.rbegin()->data,ORANGE);
    if(n>2){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"head/tail",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tmp",RED);
    graph.draw(&codeBox,5);
    //

    // step 4: tail=vtx
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,0,n-2,WHITE,BLACK,BLACK);
    graph.draw(&listNode.rbegin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&listNode.rbegin()->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,m-3,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(&tmpArrow,ORANGE);
    graph.draw(&listArrow.rbegin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail/tmp",RED);
    graph.draw(&codeBox,6);
    //

    // step 5: move to correct position
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,CIRCLE,WHITE,BLACK,BLACK);

    float preAngle=2*acos(-1)/(n-1);
    float curAngle=2*acos(-1)/n;
    for(int i=1; i<n-1; i++){
        Node &node=listNode.begin()->getNext(i)->data;
        graph.drawMove(&node,CIRCLE,CENTER,0,i*(curAngle-preAngle),WHITE,BLACK,BLACK);
    }

    sf::Vector2f dest;
    {
        sf::Vector2f pos=sf::Vector2f(0,-RADIUS);
        dest=sf::Vector2f(
            CENTER.x+pos.x*cos((n-1)*curAngle)-pos.y*sin((n-1)*curAngle),
            CENTER.y+pos.x*sin((n-1)*curAngle)+pos.y*cos((n-1)*curAngle)
        );
    }

    graph.drawMove(&listNode.rbegin()->data,CIRCLE,dest-insPos,GREEN,GREEN,WHITE);

    graph.draw(&listArrow,BLACK);
    graph.drawFadeOut(&listArrow.rbegin()->prev->data,ORANGE);
    graph.drawFadeOut(&listArrow.rbegin()->data,ORANGE);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);

    graph.draw(&codeBox,9);
    //
}

void CLL::insertMiddle(int pos, int value)
{
    if(!(0<pos && pos<listNode.size()))
        throw std::out_of_range("CLL::insertMiddle() : pos out of range");

    if(value<Config::MIN_VALUE && value>Config::MAX_VALUE)
        throw std::out_of_range("CLL::insertMiddle() : value out of range");

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/insertMiddle.txt");

    sf::Vector2f insPos;
    if(listNode.size()<=2) insPos=INSM_POS_LESS;
    else insPos=CENTER;

    listNode.insert(pos,value);
    listNode.begin()->getNext(pos)->data.position=insPos;

    listArrow.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    listArrow.insert(Arrow(&listNode.begin()->getNext(pos)->data,&listNode.begin()->getNext(pos+1)->data),pos);

    // graph.addStep(0.5*FPS);
    // graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    // graph.draw(&listArrow,BLACK);
    // graph.drawSubscript(&listNode.begin()->data,"head",RED);
    // graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    // graph.draw(&codeBox,0);

    const int n=listNode.size();
    const int m=listArrow.size();

    tmpNode.position=listNode.begin()->getNext(pos+1)->data.position;

    tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrow.dest=&tmpNode;

    // step 1: traverse to before pos
    for(int i=0; i<pos; i++)
    {
        // substep 1: highlight current node and lowlight previous node
        graph.addStep(0.5*FPS);
        
        graph.draw(&listNode,CIRCLE,0,i-1,WHITE,ORANGE,ORANGE);
        graph.drawFadeOut(&listNode,CIRCLE,i-1,i-1,ORANGE,ORANGE,WHITE);
        graph.draw(&listNode,CIRCLE,i,pos-1,WHITE,BLACK,BLACK);
        graph.draw(&listNode,CIRCLE,pos+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeIn(&listNode,CIRCLE,i,i,ORANGE,ORANGE,WHITE);

        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,pos-2,BLACK);
        graph.draw(&tmpArrow,BLACK);
        graph.draw(&listArrow,pos+1,m-1,BLACK);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",RED);
        }
        else 
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
        graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);

        if(i) graph.draw(&codeBox,2); else graph.draw(&codeBox,12);
        //
    }
    //

    // step 2: appear new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,0,pos-1,WHITE,BLACK,BLACK);
    graph.drawGrow(&listNode.begin()->getNext(pos)->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listNode,CIRCLE,pos+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&listArrow,0,pos-2,BLACK);
    graph.draw(&tmpArrow,BLACK);
    graph.draw(&listArrow,pos+1,m-1,BLACK);
    if(pos>1){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&listNode.begin()->getNext(pos-1)->data,std::to_string(pos-1)+"pre",RED);
    }
    else 
        graph.drawSubscript(&listNode.begin()->data,"0/head/pre",RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail",RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",RED);
    graph.draw(&codeBox,4);
    //
}
