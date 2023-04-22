#include "Queue.h"
#include "Config.h"

void Queue::dequeueWhenSingle()
{
    assert(listNode.size()<=1);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/Queue/dequeue.txt");

    Node* deletedN=listNode.popFront();
    deletedNode.push_back(deletedN);
}