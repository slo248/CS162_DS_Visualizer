#include "SceneNode.hpp"
#include <assert.h>

void SceneNode::attachChild(Ptr &child)
{
    child->mParent=this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &child)
{
    auto found=std::find_if(mChildren.begin(),mChildren.end(),
        [&] (Ptr& ptr) -> bool {return ptr.get()==&child;});

    assert(found!=mChildren.end());

    Ptr res=std::move(*found);
    res->mParent=nullptr;
    mChildren.erase(found);
    return res;
}
