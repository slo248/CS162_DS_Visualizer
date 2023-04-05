#include "AnimationQueue.hpp"

Animation::Ptr AnimationQueue::pop()
{
    if(mQueue.empty()) return nullptr;
    Animation::Ptr res=std::move(mQueue.front());
    mQueue.pop();
    return res;
}

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