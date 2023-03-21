#include "SceneNode.hpp"

void SceneNode::add(Ptr &child)
{
    child->mParent=this;
    mChildren.push_back(std::move(child));
}