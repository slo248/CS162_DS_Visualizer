#pragma once

#include <SceneNode.hpp>

class Node: public SceneNode{
    public:
        Node();
        Node(int _val, Node *_pNext, Node *_pPrev);
        ~Node();

        void loadFont(const sf::Font& font);

    private:
        const float         RADIUS=20.f;
        const float         OUTLINE_THICKNESS=5.f;
        const float         FONTSIZE=20.f;
        const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(500.f,300.f);
        const sf::Color     OUTLINE_COLOR=sf::Color::Green;
        const sf::Color     INSIDE_COLOR=sf::Color::White;

    private:
        int val;
        Node *pNext, *pPrev;

        sf::CircleShape     mCircle;
        sf::Text            mNum;

    private:
        virtual void    drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
        void            defaultInit();
};