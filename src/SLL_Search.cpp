#include "SLL.h"

int SLL::search(int value)
{
    codeBox.loadFromFile("media/code/search.txt");

    int n=listNode.size();
    if(n==0){ 
        graph.addStep(1);
        graph.draw(&codeBox,0);
        return -1;
    }

    // step 1: index=0, temp=head
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"0/head/temp",Colors::RED);
    graph.draw(&codeBox,1);
    //

    // step 2: while temp->value!=value
    int i=0;
    ListElement<Node>* temp=listNode.begin();
    for(;temp && temp->data.value!=value; i++, temp=temp->next){        
        // substep 1: change color of temp
        graph.addStep(0.5*FPS);

        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/temp",Colors::RED);
        graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeOut(&temp->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        graph.draw(&codeBox,2);
        //

        if(temp->next){
            // substep 2: temp=temp->next, index++
            graph.addStep(0.5*FPS);

            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i+1)->data,std::to_string(i+1)+"/temp",Colors::RED);
            graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
            graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
            graph.drawFadeIn(&temp->next->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
            graph.draw(&listArrow,0,i-1,Colors::ORANGE);
            graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
            graph.drawFadeIn(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
            graph.draw(&codeBox,34);
            //
        }
        else{
            // substep 3: return -1
            graph.addStep(0.5*FPS);

            graph.draw(&listNode,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
            graph.draw(&listArrow,Colors::ORANGE);
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",Colors::RED);
            graph.draw(&codeBox,45);
            //

            return -1;
        }
    }
    //

    graph.addStep(0.5*FPS);

    if(i){
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&temp->data,std::to_string(i)+"/temp",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.begin()->data,"0/head/temp",Colors::RED);
    graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&temp->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,0,i-1,Colors::ORANGE);
    graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
    graph.draw(&codeBox,6);

    return i;
}
