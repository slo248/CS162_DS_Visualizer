#include "AnimationQueue.hpp"

bool AnimationQueue::empty()
{
    return mQueue.empty();
}

Animation *AnimationQueue::front()
{
    if(mQueue.empty()) return nullptr;
    return mQueue.front().get();
}