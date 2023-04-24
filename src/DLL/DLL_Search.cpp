#include "DLL.h"
#include "Config.h"

int DLL::search(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();

    codeBox.loadFromFile("code/DLL/search.txt");

    int n=listNode.size();
    if(n==0){ 
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return -1;
    }

    // step 1: index=0, temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/temp",RED);
    graph.draw(&codeBox,1);
    //

    // step 2: while temp->value!=value
    int i=0;
    ListElement<Node>* temp=listNode.begin();
    for(;temp && temp->data.value!=value; i++, temp=temp->next){        
        // substep 1: change color of temp
        graph.addStep(0.5*FPS);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/temp",RED);
        graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
        graph.draw(&listNode,i+1,n-1,WHITE,BLACK,BLACK);
        graph.drawFadeOut(&temp->data,ORANGE,ORANGE,WHITE);
        graph.draw(&listArrowNext,0,i-1,ORANGE);
        graph.draw(&listArrowNext,i,listArrowNext.size()-1,BLACK);
        graph.draw(&listArrowPrev,BLACK);
        graph.draw(&codeBox,2);
        //

        if(temp->next){
            // substep 2: temp=temp->next, index++
            graph.addStep(0.5*FPS);

            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/temp",RED);
            graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
            graph.draw(&listNode,i+1,n-1,WHITE,BLACK,BLACK);
            graph.drawFadeIn(&temp->next->data,ORANGE,ORANGE,WHITE);
            graph.draw(&listArrowNext,0,i-1,ORANGE);
            graph.draw(&listArrowNext,i,listArrowNext.size()-1,BLACK);
            graph.drawGrow(&listArrowNext.begin()->getNext(i)->data,ORANGE);
            graph.draw(&listArrowPrev,BLACK);
            graph.draw(&codeBox,34);
            //
        }
        else{
            // substep 3: return -1
            graph.addStep(0.5*FPS);

            graph.draw(&listNode,WHITE,ORANGE,ORANGE);
            graph.draw(&listArrowNext,ORANGE);
            graph.draw(&listArrowPrev,BLACK);
            graph.drawSubscript(&listNode.begin()->data,"head",RED);
            graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",RED);
            graph.draw(&codeBox,45);
            //

            return -1;
        }
    }
    //

    graph.addStep(0.5*FPS);

    if(i){
        graph.drawSubscript(&listNode.begin()->data,"head",RED);
        graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/temp",RED);
    graph.draw(&listNode,0,i,WHITE,ORANGE,ORANGE);
    graph.draw(&listNode,i+1,n-1,WHITE,BLACK,BLACK);
    graph.draw(&temp->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrowNext,0,i-1,ORANGE);
    graph.draw(&listArrowNext,i,listArrowNext.size()-1,BLACK);
    graph.draw(&listArrowPrev,BLACK);
    graph.draw(&codeBox,6);

    return i;
}
