#pragma once

#include <Animation.hpp>
#include <queue>

class AnimationQueue
{
    public:
        void        update();
        void        push(Animation::Ptr animation);
        void        pop();
        void        clear();
        bool        empty();
        Animation*  front();

    private:
        std::queue<Animation::Ptr>  mQueue;
};