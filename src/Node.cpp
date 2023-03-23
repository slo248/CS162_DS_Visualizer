#include "Node.hpp"
#include <string>
#include <iostream>

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
            mCircle.getPosition()
            -mCircle.getOrigin()
            +sf::Vector2f(mCircle.getRadius(),mCircle.getRadius())
            -sf::Vector2f(bounds.width/2,bounds.width*3/2)
    );
}

void Node::setNext(Node *node)
{
    pNext=node;
}

void Node::setPrev(Node *node)
{
    pNext=node;
}

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
    target.draw(mNum,states);
}
