#pragma once

#include <Entity.hpp>
#include <Arrow.hpp>

class Node: public Entity
{
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
        void        setScaleTime(float time);
        void        setIsScaling(int type);
        void        setArrowNext(Arrow* arrow);
        void        setArrowPrev(Arrow* arrow);
        void        setHead(bool isHead);

        Node*       getNext();
        Node*       getPrev();
        int         getCategory() const;
        int         getScaleTime() const;
        Arrow*      getArrowNext();
        Arrow*      getArrowPrev();

    public:
        const float         RADIUS=20.f;
        const float         OUTLINE_THICKNESS=6.f;
        const float         FONTSIZE=24.f;
        const float         DELTA_LEN_REAL_TIME=10.f;
        const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(500.f,300.f);
        const sf::Color     OUTLINE_COLOR=sf::Color::Black;
        const sf::Color     INSIDE_COLOR=sf::Color::White;
        const float         SCALE_TIME=0.7f;
        const sf::Color     CHAR_COLOR=sf::Color::Black;
        const sf::Color     SUBSCRIPT_COLOR=sf::Color::Red;
        const float         DEFAULT_SIZE=23;

    private:
        int val;
        Node *pNext, *pPrev;

        sf::CircleShape             mCircle;
        std::unique_ptr<sf::Text>   mNum;
        std::unique_ptr<sf::Text>   mSubscript;

        float               mScaleTime;
        // 0: not scaling
        // 1: scaling up
        // 2: scaling down
        int                 mIsScaling;
        Arrow*              mArrowNext;
        Arrow*              mArrowPrev;
        bool                mIsHead;

    private:
        void            drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
        void            applyScaling(sf::Time dt);
};