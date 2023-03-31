#include "Node.hpp"
#include <TextBoxFixed.hpp>
#include <string>

Node::Node(sf::Font& font, bool isHead, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev)
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    mCircle.setOrigin(RADIUS,RADIUS);

    std::unique_ptr<TextBoxFixed> mNum(new TextBoxFixed(font,std::to_string(val)));
    mNum->move(-OUTLINE_THICKNESS,-2*OUTLINE_THICKNESS);
    this->attachChild(std::move(mNum));

    if(isHead){
        std::unique_ptr<TextBoxFixed> text(new TextBoxFixed(font,"pHead"));
        text->move(-OUTLINE_THICKNESS,RADIUS+OUTLINE_THICKNESS);
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

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
}
