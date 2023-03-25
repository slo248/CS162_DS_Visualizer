#include <Arrow.hpp>
#include <cstdlib>
#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList(sf::RenderWindow &window,sf::Font& font):
    mWindow(window),
    mFont(font),
    pHead(nullptr),
    mNumNode(0)
{
    buildScene();
}

void SinglyLinkedList::draw()
{
    mWindow.draw(mSceneGraph);
}

int getRand(int l, int r){
    return l+rand()%(r-l+1);
}

void SinglyLinkedList::setRandom()
{
    srand(time(NULL));
    mNumNode=getRand(2,MAX_NUM_NODE);

    std::unique_ptr<Node> leader(new Node(mFont,getRand(1,MAX_NUM)));
    pHead=leader.get();
    leader->setPosition(100.f,200.f);
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));

    Node *pre=pHead;

    for(int i=0; i<mNumNode-1; i++){
        sf::Vector2f vec(2*pHead->RADIUS+pHead->OUTLINE_THICKNESS,0);

        std::unique_ptr<Arrow> arrow(new Arrow(DEFAULT_DIST-vec-sf::Vector2f(pHead->OUTLINE_THICKNESS/2,0)));
        arrow->setPosition(vec-sf::Vector2f(0,arrow->HEIGHT_EACH/2));
        pre->attachChild(std::move(arrow));

        std::unique_ptr<Node> node(new Node(mFont,getRand(1,MAX_NUM)));
        Node *tmp=node.get();
        node->setPosition(DEFAULT_DIST);
        pre->attachChild(std::move(node));
        pre->setNext(tmp);
        pre=tmp;
    }
}

void SinglyLinkedList::buildScene()
{
    for(int i=0; i<Layer::NumLayer; i++){
        SceneNode::Ptr layer(new SceneNode);
        mSceneLayers[i]=layer.get();
        mSceneGraph.attachChild(std::move(layer));
    }
    
    setRandom();
}
