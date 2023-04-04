#include "Node.hpp"
#include <TextBoxFixed.hpp>
#include "Motion.hpp"
#include <string>

Node::Node(sf::Font& font, bool isHead, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev), mScaleTime(0), mIsScaling(false)
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    sf::FloatRect bounds=mCircle.getLocalBounds();
    mCircle.setOrigin(bounds.left+bounds.width/2.f,
                        bounds.top+bounds.height/2.f);

    std::unique_ptr<TextBoxFixed> mNum(new TextBoxFixed(font,std::to_string(val)));
    this->attachChild(std::move(mNum));

    if(isHead){
        std::unique_ptr<TextBoxFixed> text(new TextBoxFixed(font,"pHead"));
        text->setPosition(0.f,2*RADIUS);
        this->attachChild(std::move(text));
    }

    this->setScale(0,0);
}

Node::~Node()
{
}

void Node::setNext(Node *node)
{
    pNext=node;
}

void Node::setPrev(Node *node)
{
    pPrev=node;
}

Node *Node::getNext()
{
    return pNext;
}

Node *Node::getPrev()
{
    return pPrev;
}

int Node::getCategory() const
{
    return Category::Node;
}

int Node::getScaleTime() const
{
    return mScaleTime;
}

void Node::setScaleTime(float time)
{
    mScaleTime+=time;
}

void Node::setIsScaling(bool flag)
{
    mIsScaling=flag;
}

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
}

void Node::updateCurrent(sf::Time dt)
{
    if(mIsScaling){
        if(mScaleTime>=SCALE_TIME){
            mIsScaling=false;
            mScaleTime=0;
        }
        else{
            float factor=Motion::Bezier(mScaleTime/SCALE_TIME);
            this->setScale(factor,factor);
            mScaleTime+=dt.asSeconds();
        }
    }

    if(mVelocity.x*mVelocity.y) mVelocity/=std::sqrt(2.f);
    move(mVelocity*dt.asSeconds());
}
