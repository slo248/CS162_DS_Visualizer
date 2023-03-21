#include "SceneNode.hpp"

void SceneNode::add(Ptr &child)
{
    mChildren.push_back(child);
}