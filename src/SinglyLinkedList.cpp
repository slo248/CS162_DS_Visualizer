#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList(sf::RenderWindow &window):
    mWindow(window),
    pHead(nullptr)
{
}

void SinglyLinkedList::draw()
{
    mWindow.draw(mSceneGraph);
}

void SinglyLinkedList::buildScene()
{
    for(int i=0; i<Layer::NumLayer; i++){
        SceneNode::Ptr layer(new SceneNode);
        mSceneLayers[i]=layer.get();
        mSceneGraph.attachChild(std::move(layer));
    }

    std::unique_ptr<Node> leader(new Node);
    pHead=leader.get();
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));
}
