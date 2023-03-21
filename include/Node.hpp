#pragma once

#include <SceneNode.hpp>

class Node: public SceneNode{
    public:
        Node(int _val, Node* _pNext, Node* _pPrev);
        ~Node();

    private:
        int val;
        Node *pNext, *pPrev;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
};