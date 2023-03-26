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
        addArrow(pre,DEFAULT_DIST);

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

float getLength(sf::Vector2f vec){
    return sqrt(vec.x*vec.x+vec.y*vec.y);
}

void SinglyLinkedList::addArrow(Node *node, sf::Vector2f dist)
{
    float ratio=(2*(node->RADIUS+node->OUTLINE_THICKNESS))/getLength(dist);
    dist.x*=ratio; dist.y*=ratio;

    std::unique_ptr<Arrow> arr(new Arrow(dist));
    arr->move(node->RADIUS,-arr->HEIGHT_EACH/2);
    node->attachChild(std::move(arr));
}
