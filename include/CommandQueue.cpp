#include <CommandQueue.hpp>

void CommandQueue::push(const Command &command)
{
    mQueue.push(command);
}