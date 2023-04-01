#include <CommandQueue.hpp>

void CommandQueue::push(const Command &command)
{
    mQueue.push(command);
}

Command CommandQueue::pop()
{
    Command res=mQueue.front();
    mQueue.pop();
    return res;
}