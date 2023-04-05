#include "AnimationQueue.hpp"

Animation *AnimationQueue::front()
{
    if(mQueue.empty()) return nullptr;
    return mQueue.front().get();
}