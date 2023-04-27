#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::deleteFirst()
{
    assert(!listNodeA.empty());

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/deleteFirst.txt");    

    // remember old list
    tmpNode=num;
    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.begin()->getNext(i)->data=listNodeA.begin()->getNext(i)->data;

    // actual delete
    for(int i=0; i<num.value-1; i++)
        listNodeA.begin()->getNext(i)->data=listNodeA.begin()->getNext(i+1)->data;
    listNodeA.begin()->getNext(num.value-1)->data=-1;
    num.value--;
}