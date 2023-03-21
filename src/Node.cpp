#include "Node.hpp"
#include <string>

void Node::defaultInit()
{
    mCircle.setPosition(DEFAULT_POSITION);
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
    mNum.setOrigin(mCircle.getOrigin());
    mNum.setString(std::to_string(val));
    mNum.setCharacterSize(FONTSIZE);
}

void Node::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mCircle,states);
    target.draw(mNum,states);
}
