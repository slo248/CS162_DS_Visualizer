#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList(sf::RenderWindow &window,sf::Font& font):
    mWindow(window),
    mFont(font),
    pHead(nullptr)
{
    buildScene();
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

    std::unique_ptr<Node> leader(new Node(mFont,1));
    pHead=leader.get();
    leader->setPosition(200.f,300.f);
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));
}
