#include <Arrow.hpp>
#include <cstdlib>
#include <fstream>
// #include <cassert>
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

    std::unique_ptr<Node> leader(new Node(mFont,true,getRand(1,MAX_NUM)));
    pHead=leader.get();
    leader->setPosition(200.f,200.f);
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));

    Node *pre=pHead;

    for(int i=0; i<mNumNode-1; i++){
        addArrow(pre,DEFAULT_DIST);

        std::unique_ptr<Node> node(new Node(mFont,false,getRand(1,MAX_NUM)));
        Node *tmp=node.get();
        node->setPosition(DEFAULT_DIST);
        pre->attachChild(std::move(node));
        pre->setNext(tmp);
        pre=tmp;
    }
}

void SinglyLinkedList::loadFromFile(std::string dir)
{
    std::ifstream fi(dir);
    fi>>mNumNode;
    // assert(0<=mNumNode && mNumNode<=MAX_NUM_NODE);
    Node* cur=nullptr;
    for(int i=0; i<mNumNode; i++){
        int val; fi>>val;
        // assert(0<=val && val<=MAX_NUM);
        std::unique_ptr<Node> newNode(new Node(mFont,i==0,val));
        if(cur==nullptr){ 
            pHead=cur=newNode.get();
            pHead->setPosition(200.f,200.f);
            mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
        }
        else{
            addArrow(cur,DEFAULT_DIST);
            newNode->setPosition(DEFAULT_DIST);
            cur->setNext(newNode.get());
            cur->attachChild(std::move(newNode));
            cur=cur->getNext();
        }
        
    }
    fi.close();
}

void SinglyLinkedList::handleRealTimeInput(sf::Time dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pHead->moveUp(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        pHead->moveLeft(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        pHead->moveDown(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        pHead->moveRight(dt);
}

void SinglyLinkedList::buildScene()
{
    for(int i=0; i<Layer::NumLayer; i++){
        SceneNode::Ptr layer(new SceneNode);
        mSceneLayers[i]=layer.get();
        mSceneGraph.attachChild(std::move(layer));
    }
    
    // setRandom();
    loadFromFile("inp.txt");
}

float getLength(sf::Vector2f vec){
    return sqrt(vec.x*vec.x+vec.y*vec.y);
}

void SinglyLinkedList::addArrow(Node *node, sf::Vector2f dist)
{
    float angle=atan(dist.y/dist.x);
    float ratio=1-2*(node->RADIUS+node->OUTLINE_THICKNESS)/getLength(dist);
    dist.x*=ratio; dist.y*=ratio;

    std::unique_ptr<Arrow> arr(new Arrow(dist));
    arr->setPosition(node->RADIUS+node->OUTLINE_THICKNESS,0);
    sf::Vector2f cur=arr->getPosition();
    arr->setPosition(
        cos(angle)*cur.x-sin(angle)*cur.y,
        sin(angle)*cur.x+cos(angle)*cur.y
    );

    arr->rotate(angle*180.0/3.14);
    node->attachChild(std::move(arr));
}
