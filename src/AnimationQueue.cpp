#include "AnimationQueue.hpp"

void AnimationQueue::clear()
{
    while(!mQueue.empty()) mQueue.pop();
}

bool AnimationQueue::empty()
{
    return mQueue.empty();
}

Animation *AnimationQueue::front()
{
    if(mQueue.empty()) return nullptr;
    return mQueue.front().get();
}