#include "CLL.h"
#include "Config.h"

int CLL::search(int value)
{
    if(!(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE))
        throw std::out_of_range("CLL::search() : value out of range");

    graph.finishAllSteps();
    codeBox.loadFromFile("code/CLL/search.txt");

    int n=listNode.size();
    if(n==0){ 
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return -1;
    }

    // step 1: index=0, tmp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,CIRCLE,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/tmp",RED);
    graph.draw(&codeBox,12);
    //

    // step 2: while tmp->value!=value
    int i=0;
    ListElement<Node>* tmp=listNode.begin();
    for(;tmp && tmp->data.value!=value; i++, tmp=tmp->next){        
        // substep 1: change color of tmp
        graph.addStep(0.5*FPS);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&tmp->data,std::to_string(i)+"/tmp",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/tmp",RED);
        graph.draw(&listNode,CIRCLE,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeOut(&tmp->data,CIRCLE,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrow,0,i-1,ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
        graph.draw(&codeBox,3);
        //

        if(tmp->next){
            // substep 2: tmp=tmp->next, index++
            graph.addStep(0.5*FPS);

            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/tmp",RED);
            graph.draw(&listNode,CIRCLE,0,i,WHITE,ORANGE,ORANGE);
            graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
            graph.drawFadeIn(&tmp->next->data,CIRCLE,ORANGE,ORANGE,WHITE);
            graph.draw(&listArrow,0,i-1,ORANGE);
            graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
            graph.drawGrow(&listArrow.begin()->getNext(i)->data,ORANGE);
            graph.draw(&codeBox,45);
            //
        }
        else{
            // substep 3: return -1
            graph.addStep(0.5*FPS);

            graph.draw(&listNode,CIRCLE,WHITE,ORANGE,ORANGE);
            graph.draw(&listArrow,0,listArrow.size()-2,ORANGE);
            graph.draw(&listArrow.rbegin()->data,BLACK);
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&tmp->data,std::to_string(i)+"/tmp",RED);
            graph.draw(&codeBox,56);
            //

            return -1;
        }
    }
    //

    graph.addStep(0.5*FPS);

    if(i){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&tmp->data,std::to_string(i)+"/tmp",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/tmp",RED);
    graph.draw(&listNode,CIRCLE,0,i,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,CIRCLE,i+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&tmp->data,CIRCLE,ORANGE,ORANGE,WHITE);
    graph.drawFadeIn(&tmp->data,CIRCLE,GREEN,GREEN,WHITE);
    graph.draw(&listArrow,0,i-1,ORANGE);
    graph.draw(&listArrow,i,listArrow.size()-1,BLACK);
    graph.draw(&codeBox,7);

    return i;
}
