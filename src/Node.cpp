#include "Node.hpp"
#include <string>

Node::Node(int _val, Node *_pNext, Node *_pPrev) : 
    val(_val), pNext(_pNext), pPrev(_pPrev)
{
    mCircle.setRadius(RADIUS);
    mCircle.setFillColor(INSIDE_COLOR);
    mCircle.setOutlineThickness(OUTLINE_THICKNESS);
    mCircle.setOutlineColor(OUTLINE_COLOR);

    sf::FloatRect bounds=mCircle.getLocalBounds();
    mCircle.setOrigin(bounds.width/2,bounds.height/2);
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

    auto textRect = mNum.getLocalBounds();
    mNum.setOrigin(textRect.left + textRect.width/2.f,
                    textRect.top  + textRect.height/2.f);

    const float r=mCircle.getRadius();
    mNum.setPosition(r,r);
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
    states.transform*=mCircle.getTransform();
    target.draw(mNum,states);
}
