#pragma once

#include <Animation.hpp>
#include <queue>

class AnimationQueue
{
    public:
        void                update(sf::Time dt);
        void                push(Animation::Ptr animation);
        Animation::Ptr      pop();
        void                clear();
        bool                empty();
        Animation*          front();

    private:
        std::queue<Animation::Ptr>  mQueue;
};