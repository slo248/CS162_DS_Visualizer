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

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
}
