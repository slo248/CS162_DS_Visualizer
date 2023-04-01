#include "SceneNode.hpp"
#include <assert.h>

void SceneNode::attachChild(Ptr child)
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

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform=sf::Transform::Identity;
    for(const SceneNode* cur=this; cur; cur=cur->mParent)
        transform=cur->getTransform()*transform;
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform()*sf::Vector2f();
}

void SceneNode::clearChildren()
{
    mChildren.clear();
}

int SceneNode::getCategory() const
{
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform*=getTransform();
    drawCurrent(target,states);
    drawChildren(target,states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(const Ptr& child: mChildren)
        child->draw(target,states);
}
