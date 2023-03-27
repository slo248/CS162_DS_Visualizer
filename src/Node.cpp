#include "Node.hpp"
#include <string>

Node::Node(sf::Font& font, int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev)
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    sf::FloatRect bounds=mCircle.getLocalBounds();
    mCircle.setOrigin(bounds.width/2,bounds.height/2);

    std::unique_ptr<TextBox> mNum(new TextBox(font,std::to_string(val)));
    mNum->move(-OUTLINE_THICKNESS,-2*OUTLINE_THICKNESS);
    this->attachChild(std::move(mNum));
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
    this->move(sf::Vector2f(-DELTA_LEN,0)*dt.asSeconds());
}

void Node::moveRight(sf::Time dt)
{
    this->move(sf::Vector2f(DELTA_LEN,0)*dt.asSeconds());    
}

void Node::moveUp(sf::Time dt)
{
    this->move(sf::Vector2f(0,-DELTA_LEN)*dt.asSeconds());    
}

void Node::moveDown(sf::Time dt)
{
    this->move(sf::Vector2f(0,DELTA_LEN)*dt.asSeconds());    
}

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
}
