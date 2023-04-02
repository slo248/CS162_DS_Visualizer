#include "Node.hpp"
#include <TextBoxFixed.hpp>
#include <string>

Node::Node(sf::Font& font, bool isHead, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev), mScaleTime(0)
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

void Node::moveLeft(sf::Time dt)
{
    this->move(sf::Vector2f(-DELTA_LEN_REAL_TIME,0)*dt.asSeconds());
}

void Node::moveRight(sf::Time dt)
{
    this->move(sf::Vector2f(DELTA_LEN_REAL_TIME,0)*dt.asSeconds());    
}

void Node::moveUp(sf::Time dt)
{
    this->move(sf::Vector2f(0,-DELTA_LEN_REAL_TIME)*dt.asSeconds());    
}

void Node::moveDown(sf::Time dt)
{
    this->move(sf::Vector2f(0,DELTA_LEN_REAL_TIME)*dt.asSeconds());    
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
    if(mVelocity.x*mVelocity.y) mVelocity/=std::sqrt(2.f);
    move(mVelocity*dt.asSeconds());
}
