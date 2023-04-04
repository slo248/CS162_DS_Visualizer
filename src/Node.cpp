#include "Node.hpp"
#include "Motion.hpp"
#include <string>

Node::Node(sf::Font& font, bool isHead, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev), mScaleTime(0), mIsScaling(false)
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    {
        sf::FloatRect bounds=mCircle.getLocalBounds();
        mCircle.setOrigin(bounds.left+bounds.width/2.f,
                            bounds.top+bounds.height/2.f);
    }

    mNum=std::make_unique<sf::Text>(std::to_string(val),font,DEFAULT_SIZE);
    mNum->setFillColor(CHAR_COLOR);
    {
        sf::FloatRect bounds=mNum->getLocalBounds();
        mNum->setOrigin(bounds.left+bounds.width/2.f,
                        bounds.top+bounds.height/2.f);
    }
    mNum->setPosition(RADIUS,RADIUS);

    mSubscript=std::make_unique<sf::Text>("",font,DEFAULT_SIZE);
    if(isHead) mSubscript->setString("pHead");
    mSubscript->setFillColor(SUBSCRIPT_COLOR);
    {
        sf::FloatRect bounds=mSubscript->getLocalBounds();
        mSubscript->setOrigin(bounds.left+bounds.width/2.f,0);
    }
    mSubscript->setPosition(RADIUS,2*RADIUS);    

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

void Node::setIsScaling(int type)
{
    mIsScaling=type;
}

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
    states.transform*=mCircle.getTransform();
    target.draw(*mNum.get(),states);
    target.draw(*mSubscript.get(),states);
}

void Node::updateCurrent(sf::Time dt)
{
    applyScaling(dt);
    if(mVelocity.x*mVelocity.y) mVelocity/=std::sqrt(2.f);
    move(mVelocity*dt.asSeconds());
}

void Node::applyScaling(sf::Time dt)
{
    if(mIsScaling){
        if(mScaleTime>=SCALE_TIME){
            mIsScaling=0;
            mScaleTime=0;
        }
        else{
            float factor;
            if(mIsScaling==1) // scaling up
                factor=Motion::Bezier(mScaleTime/SCALE_TIME);
            else // scaling down
                factor=Motion::Bezier(1-mScaleTime/SCALE_TIME);
            this->setScale(factor,factor);
            mScaleTime+=dt.asSeconds();
        }
    }
}
