#include <cstdlib>
#include <fstream>
#include <cassert>
#include "SinglyLinkedList.hpp"
#include <iostream>

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
    leader->setPrePos(leader->getPosition());
    mSceneLayers[Layer::Front]->attachChild(std::move(leader));

    Node *pre=pHead;

    for(int i=1; i<mNumNode; i++){
        std::unique_ptr<Node> node(new Node(mFont,false,getRand(1,MAX_NUM)));
        Node *tmp=node.get();
        node->setPosition(pHead->getPosition()+float(i)*DEFAULT_DIST);
        node->setPrePos(node->getPosition());
        node->setPrev(pre);
        std::unique_ptr<Arrow> arr=pre->makeArrow(tmp);
        pre->setArrowNext(arr.get());
        mSceneLayers[Layer::Front]->attachChild(std::move(node));
        mSceneLayers[Layer::Front]->attachChild(std::move(arr));
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
            std::unique_ptr<Arrow> arr=cur->makeArrow(newNode.get());
            cur->setArrowNext(arr.get());
            cur->setNext(newNode.get());
            newNode->setPrev(cur);
            cur=cur->getNext();
            mSceneLayers[Layer::Front]->attachChild(std::move(arr));
        }
        newNode->setPrePos(newNode->getPosition());
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
                disappear->animators.push_back(derivedAnimator<Button>(SNAnimation::Scale(1)));
                switch (type){
                    case Category::ButtonCreate:
                    {
                        mAnimationQueue.push(std::move(disappear));

                        std::unique_ptr<Animation> appear(new Animation);
                        appear->category=Category::ButtonEmpty|Category::ButtonSetRandom|Category::ButtonLoadFromFile;
                        appear->elapsedTime=sf::seconds(1);
                        appear->duration=sf::seconds(1);
                        appear->animators.push_back(derivedAnimator<Button>(SNAnimation::Scale(0)));
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
                            animation->duration=Motion::CREATE_TIME;
                            animation->animators.push_back(derivedAnimator<SceneNode>(SNAnimation::Scale(0)));
                            mAnimationQueue.push(std::move(animation));
                            break;
                        }
                        case Category::ButtonLoadFromFile:
                        {
                            loadFromFile("inp.txt");
                            std::unique_ptr<Animation> animation(new Animation);
                            animation->category=Category::Node|Category::Arrow;
                            animation->elapsedTime=sf::Time::Zero;
                            animation->duration=Motion::CREATE_TIME;
                            animation->animators.push_back(derivedAnimator<SceneNode>(SNAnimation::Scale(0)));
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
                        appear->animators.push_back(derivedAnimator<Button>(SNAnimation::Scale(0)));
                        mAnimationQueue.push(std::move(appear));
                        break;
                    }
                        case Category::ButtonInsertFront:
                        {
                            if(pHead)
                                insertFront();
                            else
                                insertWhenEmpty();
                            mNumNode++;
                            break;
                        }
                        case Category::ButtonInsertBack:
                        {
                            if(pHead)
                                insertBack();
                            else
                                insertWhenEmpty();
                            mNumNode++;
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

void SinglyLinkedList::removeSubButton()
{
    while(!mButtons.empty()){
        int type=mButtons.back()->getCategory();
        if(type&Category::AllFixedButtons) break;
        mSceneLayers[Layer::Background]->detachChild(*mButtons.back());
        mButtons.pop_back();
    }
}

void SinglyLinkedList::removeAllChosen()
{
    // remove all chosen
    {
        std::unique_ptr<Animation> remove(new Animation);
        remove->category=Category::AllChosen;
        remove->elapsedTime=Motion::INSERT_TIME;
        remove->duration=Motion::INSERT_TIME;
        remove->animators.push_back(derivedAnimator<SceneNode>(SNAnimation::RemoveChosen()));
        mAnimationQueue.push(std::move(remove));
    }
}

void SinglyLinkedList::normallizeAll()
{
    if(pHead)
        for(Node* cur=pHead; cur; cur=cur->getNext())
            cur->normalize();
}

void SinglyLinkedList::appearNewNode()
{                
    {
        std::unique_ptr<Animation> appear(new Animation);
        appear->exactly=true;
        appear->category=Category::Node|Category::Chosen1;
        appear->elapsedTime=sf::Time::Zero;
        appear->duration=Motion::INSERT_TIME;
        appear->animators.push_back(derivedAnimator<SceneNode>(SNAnimation::Scale(0)));
        mAnimationQueue.push(std::move(appear));
    }
}

void SinglyLinkedList::moveList(sf::Vector2f delta)
{
    {
        std::unique_ptr<Animation> move(new Animation);
        move->exactly=true;
        move->category=Category::Node|Category::Chosen2;
        move->elapsedTime=sf::Time::Zero;
        move->duration=Motion::INSERT_TIME;
        move->animators.push_back(derivedAnimator<Node>(NodeAnimation::Move(delta,mSceneLayers[Layer::Front])));
        mAnimationQueue.push(std::move(move));
    }
}

void SinglyLinkedList::becomeHead()
{
    {
        std::unique_ptr<Animation> becomeHead(new Animation);
        becomeHead->exactly=true;
        becomeHead->category=Category::Node|Category::Chosen1;
        becomeHead->elapsedTime=Motion::INSERT_TIME;
        becomeHead->duration=Motion::INSERT_TIME;
        becomeHead->animators.push_back(derivedAnimator<Node>(NodeAnimation::BecomeHead()));
        mAnimationQueue.push(std::move(becomeHead));
    }
}

void SinglyLinkedList::changeVtxColor(sf::Color color)
{
    {
        std::unique_ptr<Animation> changeColor(new Animation);
        changeColor->exactly=true;
        changeColor->category=Category::Node|Category::Chosen1;
        changeColor->elapsedTime=Motion::INSERT_TIME;
        changeColor->duration=Motion::INSERT_TIME;
        changeColor->animators.push_back(derivedAnimator<Node>(NodeAnimation::ChangeColor(color)));
        mAnimationQueue.push(std::move(changeColor));
    }
}

void SinglyLinkedList::moveVtx(sf::Vector2f delta)
{
    {
        std::unique_ptr<Animation> move(new Animation);
        move->exactly=true;
        move->category=Category::Node|Category::Chosen1;
        move->elapsedTime=sf::Time::Zero;
        move->duration=Motion::INSERT_TIME;
        move->animators.push_back(derivedAnimator<Node>(NodeAnimation::Move(delta,mSceneLayers[Layer::Front])));
        mAnimationQueue.push(std::move(move));
    }
}

void SinglyLinkedList::changeArrowColor(sf::Color color)
{
    {
        std::unique_ptr<Animation> changeColor(new Animation);
        changeColor->exactly=true;
        changeColor->category=Category::Arrow|Category::Chosen1;
        changeColor->elapsedTime=Motion::INSERT_TIME;
        changeColor->duration=Motion::INSERT_TIME;
        changeColor->animators.push_back(derivedAnimator<Arrow>(ArrowAnimation::ChangeColor(color)));
        mAnimationQueue.push(std::move(changeColor));
    }
}

std::unique_ptr<Node> SinglyLinkedList::createNode(sf::Vector2f pos, int value)
{
    std::unique_ptr<Node> newNode(new Node(mFont,false,value));
    newNode->setChosen(Category::Chosen1);
    newNode->setPosition(pos);
    newNode->setPrePos(newNode->getPosition());

    // make new node
    {
        std::unique_ptr<Animation> makeNew(new Animation);
        makeNew->exactly=true;
        makeNew->category=Category::Node|Category::Chosen1;
        makeNew->elapsedTime=Motion::INSERT_TIME;
        makeNew->duration=Motion::INSERT_TIME;
        makeNew->animators.push_back(derivedAnimator<Node>(NodeAnimation::MakeNew()));
        mAnimationQueue.push(std::move(makeNew));
    }

    return std::move(newNode);
}

std::unique_ptr<Arrow> SinglyLinkedList::createArrow(Node *a, Node *b, sf::Color color)
{
    // Add new arrow
    std::unique_ptr<Arrow> arr=a->makeArrow(b);
    {
        a->setArrowNext(arr.get());
        arr->setChosen(Category::Chosen1);
        
        {
            std::unique_ptr<Animation> applyColor(new Animation);
            applyColor->exactly=true;
            applyColor->category=Category::Arrow|Category::Chosen1;
            applyColor->elapsedTime=Motion::INSERT_TIME;
            applyColor->duration=Motion::INSERT_TIME;
            applyColor->animators.push_back(derivedAnimator<Arrow>(ArrowAnimation::ChangeColor(color)));
            mAnimationQueue.push(std::move(applyColor));
        }

        // appear
        {
            std::unique_ptr<Animation> appear(new Animation);
            appear->exactly=true;
            appear->category=Category::Arrow|Category::Chosen1;
            appear->elapsedTime=sf::Time::Zero;
            appear->duration=Motion::INSERT_TIME;
            appear->animators.push_back(derivedAnimator<SceneNode>(SNAnimation::Scale(0)));
            mAnimationQueue.push(std::move(appear));
        }
    }

    return std::move(arr);
}

void SinglyLinkedList::insertWhenEmpty()
{
    // normal head config
    normallizeAll();

    std::unique_ptr<Node> newNode=createNode(DEFAULT_POS,getRand(1,MAX_NUM));

    appearNewNode();

    // change vtx color to green
    changeVtxColor(NodeConfig::HEAD_BG_COLOR);

    becomeHead();

    removeAllChosen();

    pHead=newNode.get();
    mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
}

void SinglyLinkedList::insertFront()
{
    normallizeAll();

    std::unique_ptr<Node> newNode=createNode(DEFAULT_POS+sf::Vector2f(0,DEFAULT_LEN),getRand(1,MAX_NUM));
    newNode->setNext(pHead);
    pHead->setPrev(newNode.get());

    appearNewNode();

    std::unique_ptr<Arrow> arr=createArrow(newNode.get(),pHead,Colors::ORANGE);

    // change vtx color to green
    changeVtxColor(Colors::GREEN);

    // change arrow color to black
    changeArrowColor(Colors::BLACK);

    becomeHead();

    for(Node* cur=pHead; cur; cur=cur->getNext())
        cur->setChosen(Category::Chosen2);

    // move original list to the right
    moveList(sf::Vector2f(DEFAULT_LEN,0));

    // move vtx to same row
    moveVtx(sf::Vector2f(0,-DEFAULT_LEN));

    removeAllChosen();

    pHead=newNode.get();
    mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
    mSceneLayers[Layer::Front]->attachChild(std::move(arr));
}

void SinglyLinkedList::insertBack()
{
    normallizeAll();

    std::unique_ptr<Node> newNode=createNode(DEFAULT_POS+1.f*mNumNode*sf::Vector2f(DEFAULT_LEN,0),getRand(1,MAX_NUM));

    appearNewNode();

    pHead->setChosen(Category::Chosen2);
    for(int i=0; i<mNumNode; ++i){
        // set subscript by preSubscript of pre node
        {
            std::unique_ptr<Animation> animation(new Animation);
            animation->exactly=true;
            animation->category=Category::Node|Category::Chosen2;
            animation->elapsedTime=Motion::INSERT_TIME;
            animation->duration=Motion::INSERT_TIME;
            animation->animators.push_back(derivedAnimator<Node>(NodeAnimation::SetSubscriptPreNode()));
            mAnimationQueue.push(std::move(animation));
        }
        // add subscript "vtx"
        {
            std::unique_ptr<Animation> addSubscript(new Animation);
            addSubscript->exactly=true;
            addSubscript->category=Category::Node|Category::Chosen2;
            addSubscript->elapsedTime=Motion::INSERT_TIME;
            addSubscript->duration=Motion::INSERT_TIME;
            addSubscript->animators.push_back(derivedAnimator<Node>(NodeAnimation::AddSubscript("tail")));
            mAnimationQueue.push(std::move(addSubscript));
        }
        // color to blue
        {
            std::unique_ptr<Animation> changeColor(new Animation);
            changeColor->exactly=true;
            changeColor->category=Category::Node|Category::Chosen2;
            changeColor->elapsedTime=Motion::INSERT_TIME;
            changeColor->duration=Motion::INSERT_TIME;
            changeColor->animators.push_back(derivedAnimator<Node>(NodeAnimation::ChangeColor(Colors::BLUE)));
            mAnimationQueue.push(std::move(changeColor));
        }
        // move chosen
        {
            std::unique_ptr<Animation> moveChosen(new Animation);
            moveChosen->exactly=true;
            moveChosen->once=true;
            moveChosen->category=Category::Node|Category::Chosen2;
            moveChosen->elapsedTime=sf::Time::Zero;
            moveChosen->duration=Motion::INSERT_TIME;
            moveChosen->animators.push_back(derivedAnimator<Node>(NodeAnimation::MoveChosenToNext()));
            mAnimationQueue.push(std::move(moveChosen));
        }
    }

    removeAllChosen();

    mSceneLayers[Layer::Front]->attachChild(std::move(newNode));
}
