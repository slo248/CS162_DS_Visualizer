#include <cstdlib>
#include <fstream>
#include <cassert>
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
    mSceneLayers[Layer::Front]->clearChildren();

    srand(time(NULL));
    mNumNode=getRand(2,MAX_NUM_NODE);

    std::unique_ptr<Node> leader(new Node(mFont,true,getRand(1,MAX_NUM)));
    pHead=leader.get();
    leader->setPosition(DEFAULT_POS);
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));

    Node *pre=pHead;

    for(int i=1; i<mNumNode; i++){
        std::unique_ptr<Node> node(new Node(mFont,false,getRand(1,MAX_NUM)));
        Node *tmp=node.get();
        node->setPosition(pHead->getPosition()+float(i)*DEFAULT_DIST);
        pre->setArrowNext(makeArrow(pre,tmp));
        mSceneLayers[Layer::Front]->attachChild(std::move(std::move(node)));
        pre->setNext(tmp);
        pre=tmp;
    }
}

void SinglyLinkedList::loadFromFile(std::string dir)
{
    mSceneLayers[Layer::Front]->clearChildren();

    std::ifstream fi(dir);
    fi>>mNumNode;
    assert(0<=mNumNode && mNumNode<=MAX_NUM_NODE);
    Node* cur=nullptr;
    for(int i=1; i<=mNumNode; i++){
        int val; fi>>val;
        assert(0<=val && val<=MAX_NUM);
        std::unique_ptr<Node> newNode(new Node(mFont,i==1,val));
        if(cur==nullptr){ 
            pHead=cur=newNode.get();
            pHead->setPosition(DEFAULT_POS);
        }
        else{
            newNode->setPosition(pHead->getPosition()+float(i-1)*DEFAULT_DIST);
            cur->setArrowNext(makeArrow(cur,newNode.get()));
            cur->setNext(newNode.get());
            cur=cur->getNext();
        }
        mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
    }
    fi.close();
}

void SinglyLinkedList::update(sf::Time dt)
{
    Animation* animation=mAnimationQueue.front();
    if(animation!=nullptr){
        animation->elapsedTime+=dt;
        if(animation->elapsedTime>=animation->duration)
            animation->elapsedTime=animation->duration;
        mSceneGraph.onAnimation(animation, dt);
        mAnimationQueue.update();
    }
}

void SinglyLinkedList::processInput(sf::Event event)
{
    switch (event.type){
        case sf::Event::KeyPressed:
        {
            switch (event.key.code){
                case sf::Keyboard::R:
                    setRandom();
                    break;
                case sf::Keyboard::F:
                    loadFromFile("inp.txt");
                    break;
            }
            break;
        }
        default:
            break;
    }

    sf::Vector2f mousePos(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow)));
    for(Button* btn: mButtons)
        if(btn->getScale().x>0 && btn->isMouseOver(mousePos)){
            btn->setBackGroundColor(ButtonConfig::BG_COLOR_HOVER);
            int type=btn->getCategory();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                std::unique_ptr<Animation> disappear(new Animation);
                disappear->category=Category::AllSubButton;
                disappear->elapsedTime=sf::seconds(1);
                disappear->duration=sf::seconds(1);
                disappear->animator=derivedAnimator<Button>(SNAnimation::Shrink());
                switch (type){
                    case Category::ButtonCreate:
                    {
                        mAnimationQueue.push(std::move(disappear));

                        std::unique_ptr<Animation> appear(new Animation);
                        appear->category=Category::ButtonEmpty|Category::ButtonSetRandom|Category::ButtonLoadFromFile;
                        appear->elapsedTime=sf::seconds(1);
                        appear->duration=sf::seconds(1);
                        appear->animator=derivedAnimator<Button>(SNAnimation::Grow());
                        mAnimationQueue.push(std::move(appear));
                        break;
                    }
                        case Category::ButtonEmpty:
                        {
                            pHead=nullptr;
                            mSceneLayers[Layer::Front]->clearChildren();
                            break;
                        }
                        case Category::ButtonSetRandom:
                        {
                            setRandom();
                            std::unique_ptr<Animation> animation(new Animation);
                            animation->category=Category::Node|Category::Arrow;
                            animation->elapsedTime=sf::Time::Zero;
                            animation->duration=NodeConfig::SCALE_TIME;
                            animation->animator=derivedAnimator<SceneNode>(SNAnimation::Grow());
                            mAnimationQueue.push(std::move(animation));
                            break;
                        }
                        case Category::ButtonLoadFromFile:
                        {
                            loadFromFile("inp.txt");
                            std::unique_ptr<Animation> animation(new Animation);
                            animation->category=Category::Node|Category::Arrow;
                            animation->elapsedTime=sf::Time::Zero;
                            animation->duration=NodeConfig::SCALE_TIME;
                            animation->animator=derivedAnimator<SceneNode>(SNAnimation::Grow());
                            mAnimationQueue.push(std::move(animation));
                            break;
                        }
                    case Category::ButtonInsert:
                    {
                        mAnimationQueue.push(std::move(disappear));

                        std::unique_ptr<Animation> appear(new Animation);
                        appear->category=Category::ButtonInsertFront|Category::ButtonInsertMiddle|Category::ButtonInsertBack;
                        appear->elapsedTime=sf::seconds(1);
                        appear->duration=sf::seconds(1);
                        appear->animator=derivedAnimator<Button>(SNAnimation::Grow());
                        mAnimationQueue.push(std::move(appear));
                        break;
                    }
                        case Category::ButtonInsertFront:
                        {
                            insertFront();
                            break;
                        }
                    case Category::ButtonUpdate:
                        mAnimationQueue.push(std::move(disappear));
                        break;
                    case Category::ButtonRemove:
                        mAnimationQueue.push(std::move(disappear));
                        break;
                }
            }
        }
        else
            btn->setBackGroundColor(ButtonConfig::BG_COLOR);
}

void SinglyLinkedList::buildScene()
{
    for(int i=0; i<Layer::NumLayer; i++){
        SceneNode::Ptr layer(new SceneNode);
        mSceneLayers[i]=layer.get();
        mSceneGraph.attachChild(std::move(layer));
    }

    sf::Vector2f size=mWindow.getView().getSize();
    {
        std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonCreate,sf::Vector2f(0.f,size.y-5*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
        mButtons.push_back(btn.get());
        mSceneLayers[Layer::Background]->attachChild(std::move(btn));
    }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonEmpty,sf::Vector2f(ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-5*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonSetRandom,sf::Vector2f(2*ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-5*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonLoadFromFile,sf::Vector2f(3*ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-5*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
    {
        std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonInsert,sf::Vector2f(0.f,size.y-4*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
        mButtons.push_back(btn.get());
        mSceneLayers[Layer::Background]->attachChild(std::move(btn));
    }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonInsertFront,sf::Vector2f(ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-4*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonInsertMiddle,sf::Vector2f(2*ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-4*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
        {
            std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonInsertBack,sf::Vector2f(3*ButtonConfig::DEFAULT_SIZE.x+10.f,size.y-4*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
            btn->setScale(0,0);
            mButtons.push_back(btn.get());
            mSceneLayers[Layer::Background]->attachChild(std::move(btn));
        }
    {
        std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonUpdate,sf::Vector2f(0.f,size.y-3*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
        mButtons.push_back(btn.get());
        mSceneLayers[Layer::Background]->attachChild(std::move(btn));
    }
    {
        std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonRemove,sf::Vector2f(0.f,size.y-2*ButtonConfig::DEFAULT_SIZE.y-3*ButtonConfig::THICK)));
        mButtons.push_back(btn.get());
        mSceneLayers[Layer::Background]->attachChild(std::move(btn));
    }
    {
        std::unique_ptr<Button> btn(new Button(mFont,Category::ButtonSearch,sf::Vector2f(0.f,size.y-ButtonConfig::DEFAULT_SIZE.y-2*ButtonConfig::THICK)));
        mButtons.push_back(btn.get());
        mSceneLayers[Layer::Background]->attachChild(std::move(btn));
    }
}

float getLength(sf::Vector2f vec){
    return sqrt(vec.x*vec.x+vec.y*vec.y);
}

Arrow* SinglyLinkedList::makeArrow(Node *a, Node *b)
{
    sf::Vector2f dist=b->getPosition()-a->getPosition();

    float angle=atan(dist.y/dist.x);
    float ratio=1-2*(NodeConfig::RADIUS+NodeConfig::OUTLINE_THICKNESS)/getLength(dist);
    dist.x*=ratio; dist.y*=ratio;

    std::unique_ptr<Arrow> arr(new Arrow(dist));
    arr->setPosition(NodeConfig::RADIUS+NodeConfig::OUTLINE_THICKNESS,0);
    sf::Vector2f cur=arr->getPosition();
    arr->setPosition(
        cos(angle)*cur.x-sin(angle)*cur.y,
        sin(angle)*cur.x+cos(angle)*cur.y
    );
    arr->move(a->getPosition());


    arr->rotate(angle*180.0/3.14);
    Arrow* res=arr.get();
    mSceneLayers[Layer::Front]->attachChild(std::move(arr));
    return res;
}

void SinglyLinkedList::removeSubButton()
{
    while(!mButtons.empty()){
        int type=mButtons.back()->getCategory();
        if(type&Category::AllFixedButtons) break;
        mSceneLayers[Layer::Background]->detachChild(*mButtons.back());
        mButtons.pop_back();
    }
}

void SinglyLinkedList::insertFront()
{
    // Add new node
    {
        std::unique_ptr<Node> newNode(new Node(mFont,false,getRand(1,MAX_NUM)));
        newNode->setChosen(true);
        newNode->setPosition(DEFAULT_POS);
        newNode->move(0,DEFAULT_LEN);
        newNode->setSubscript("vtx");
        newNode->setNumColor(NodeConfig::VTX_NUM_COLOR);
        newNode->setBGColor(NodeConfig::VTX_BG_COLOR);

        std::unique_ptr<Animation> appear(new Animation);
        appear->exactly=true;
        appear->category=Category::Node|Category::Chosen;
        appear->elapsedTime=sf::Time::Zero;
        appear->duration=NodeConfig::SCALE_TIME;
        appear->animator=derivedAnimator<SceneNode>(SNAnimation::Grow());
        mAnimationQueue.push(std::move(appear));

        mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
    }
}
