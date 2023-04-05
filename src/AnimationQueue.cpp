#include "AnimationQueue.hpp"

void AnimationQueue::update(sf::Time dt)
{
    if(mQueue.empty()) return;
    Animation* animation=mQueue.front().get();
    animation->elapsedTime+=dt;
    if(animation->elapsedTime>=animation->duration) mQueue.pop();
}

void AnimationQueue::push(Animation::Ptr animation)
{
    mQueue.push(std::move(animation));
}

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