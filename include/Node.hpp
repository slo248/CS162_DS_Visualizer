#pragma once

#include <SceneNode.hpp>

class Node: public SceneNode{

    public:
        Node(
            sf::Font& font,
            bool isHead,
            int _val=0, 
            Node *_pNext=nullptr, 
            Node *_pPrev=nullptr
        );
        ~Node();

        void        setNext(Node* node);
        void        setPrev(Node* node);
        Node*       getNext();
        Node*       getPrev();

        void        moveLeft(sf::Time dt);
        void        moveRight(sf::Time dt);
        void        moveUp(sf::Time dt);
        void        moveDown(sf::Time dt);

    public:
        const float         RADIUS=20.f;
        const float         OUTLINE_THICKNESS=6.f;
        const float         FONTSIZE=24.f;
        const float         DELTA_LEN_REAL_TIME=10.f;
        const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(500.f,300.f);
        const sf::Color     OUTLINE_COLOR=sf::Color::Black;
        const sf::Color     INSIDE_COLOR=sf::Color::White;

    private:
        int val;
        Node *pNext, *pPrev;

        sf::CircleShape     mCircle;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
};