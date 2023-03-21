#pragma once

#include <SceneNode.hpp>

class Node: public SceneNode{
    public:
        Node();
        Node(int _val, Node *_pNext, Node *_pPrev);
        ~Node();

    private:
        const float         RADIUS=10.f;
        const float         OUTLINE_THICKNESS=6.f;
        const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(100.f,100.f);
        const sf::Color     OUTLINE_COLOR=sf::Color::Blue;
        const sf::Color     INSIDE_COLOR=sf::Color::White;

    private:
        int val;
        Node *pNext, *pPrev;

        sf::CircleShape     mCircle;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
};