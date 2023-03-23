#include "Node.hpp"
#include <string>

void Node::defaultInit()
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    sf::FloatRect bounds=mCircle.getLocalBounds();
    mCircle.setOrigin(bounds.width/2,bounds.height/2);
}

Node::Node():
    val(0),pNext(nullptr),pPrev(nullptr)
{
    defaultInit();
}

Node::Node(int _val):
    val(_val),pNext(nullptr),pPrev(nullptr)
{
    defaultInit();
}

Node::Node(int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev)
{
    defaultInit();
}

Node::~Node()
{
}

void Node::loadFont(const sf::Font &font)
{
    mNum.setFont(font);
    mNum.setString(std::to_string(val));
    mNum.setCharacterSize(FONTSIZE);
    mNum.setFillColor(CHAR_COLOR);

    sf::FloatRect bounds=mNum.getLocalBounds();
    mNum.setPosition(
        sf::Vector2f(mCircle.getGlobalBounds().top,mCircle.getGlobalBounds().left)
        +sf::Vector2f(2*mCircle.getRadius(),2*mCircle.getRadius()-5.f)
        +mCircle.getPosition()
    );
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

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
    target.draw(mNum,states);
}
