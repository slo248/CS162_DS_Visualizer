#include "SArr.h"

void SArr::update(int pos, int value)
{
    assert(0<=pos && pos<num.value);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/update.txt");

    tmpNode.value=listNodeA.begin()->getNext(pos)->data.value;
    tmpNode.position=listNodeA.begin()->getNext(pos)->data.position;

    listNodeA.begin()->getNext(pos)->data.value=value;
}