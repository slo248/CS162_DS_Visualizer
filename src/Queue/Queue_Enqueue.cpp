#include "Queue.h"
#include "Config.h"

void Queue::enqueueWhenEmpty(int value)
{
    assert(listNode.size()==0);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/enqueue.txt");

    listNode.pushBack(value);
}