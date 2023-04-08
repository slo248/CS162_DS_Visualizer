#include "Node.hpp"
#include "Motion.hpp"
#include <string>

using namespace NodeConfig;

Node::Node(sf::Font& font, bool isHead, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev), mScaleTime(0), mIsScaling(false), mIsHead(isHead)
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

    mArrowNext=mArrowPrev=nullptr;

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

unsigned int Node::getCategory() const
{
    return Category::Node|mChosen;
}

int Node::getScaleTime() const
{
    return mScaleTime;
}

Arrow *Node::getArrowNext()
{
    return mArrowNext;
}

Arrow *Node::getArrowPrev()
{
    return mArrowPrev;
}

sf::Vector2f Node::getPrePos()
{
    return prePos;
}

bool Node::isHead()
{
    return mIsHead;
}

std::unique_ptr<Arrow> Node::makeArrow(Node *dest)
{
    sf::Vector2f dist=dest->getPosition()-this->getPosition();

    float len=sqrt(dist.x*dist.x+dist.y*dist.y);
    float angle=atan(dist.y/dist.x);
    if(dist.x<0 && dist.y<0) angle+=3.14;
    else if(dist.x<0) angle+=3.14;
    else if(dist.y<0) angle+=2*3.14;
    float ratio=1-2*(RADIUS+OUTLINE_THICKNESS)/len;
    dist.x*=ratio; dist.y*=ratio;

    std::unique_ptr<Arrow> arr(new Arrow(dist));
    arr->setPosition(RADIUS+OUTLINE_THICKNESS,0);
    sf::Vector2f cur=arr->getPosition();
    arr->setPosition(
        cos(angle)*cur.x-sin(angle)*cur.y,
        sin(angle)*cur.x+cos(angle)*cur.y
    );
    arr->move(this->getPosition());


    arr->rotate(angle*180.0/3.14);
    return arr;
}

void Node::setScaleTime(float time)
{
    mScaleTime+=time;
}

void Node::setIsScaling(int type)
{
    mIsScaling=type;
}

void Node::setArrowNext(Arrow *arrow)
{
    mArrowNext=arrow;
}

void Node::setArrowPrev(Arrow *arrow)
{
    mArrowPrev=arrow;
}

void Node::setHead(bool isHead)
{
    mIsHead=isHead;
}

void Node::setSubscript(const std::string &str)
{
    mSubscript->setString(str);
    {
        sf::FloatRect bounds=mSubscript->getLocalBounds();
        mSubscript->setOrigin(bounds.left+bounds.width/2.f,0);
    }
}

void Node::setBGColor(const sf::Color &color)
{
    mCircle.setFillColor(color);
}

void Node::setNumColor(const sf::Color &color)
{
    mNum->setFillColor(color);
}

void Node::setPos(sf::Vector2f pos)
{
    setPrePos(this->getPosition());
    this->setPosition(pos);
}

void Node::setPrePos(sf::Vector2f pos)
{
    prePos=pos;
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
    if(mVelocity.x*mVelocity.y) mVelocity/=std::sqrt(2.f);
    move(mVelocity*dt.asSeconds());
}
