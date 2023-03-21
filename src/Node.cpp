#include "Node.hpp"

Node::Node(int _val=0, Node *_pNext=nullptr, Node *_pPrev=nullptr):
    val(_val),pNext(_pNext),pPrev(_pPrev)
{
    mCircle.setPosition(100.f,100.f);
    mCircle.setRadius(10.f);
    mCircle.setFillColor(sf::Color::White);
    mCircle.setOutlineThickness(8.f);
    mCircle.setOutlineColor(sf::Color::Blue);

    sf::FloatRect bounds=mCircle.getLocalBounds();
    mCircle.setOrigin(bounds.width/2,bounds.height/2);
}

Node::~Node()
{
}
