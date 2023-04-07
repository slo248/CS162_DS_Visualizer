#pragma once

#include <Entity.hpp>
#include <Arrow.hpp>

namespace NodeConfig
{
    const float         RADIUS=20.f;
    const float         OUTLINE_THICKNESS=6.f;
    const float         FONTSIZE=24.f;
    const float         DELTA_LEN_REAL_TIME=10.f;
    const sf::Vector2f  DEFAULT_POSITION=sf::Vector2f(500.f,300.f);
    const sf::Color     OUTLINE_COLOR=sf::Color::Black;
    const sf::Color     INSIDE_COLOR=sf::Color::White;
    const sf::Color     CHAR_COLOR=sf::Color::Black;
    const sf::Color     SUBSCRIPT_COLOR=sf::Color::Red;
    const float         DEFAULT_SIZE=23;

    const sf::Color     VTX_BG_COLOR=sf::Color(255, 138, 39, 255);
    const sf::Color     VTX_NUM_COLOR=sf::Color::White;

    const sf::Color     HEAD_BG_COLOR=sf::Color(82, 188, 105, 255);
    const sf::Color     HEAD_NUM_COLOR=sf::Color::White;
}

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

        void            setNext(Node* node);
        void            setPrev(Node* node);
        void            setScaleTime(float time);
        void            setIsScaling(int type);
        void            setArrowNext(Arrow* arrow);
        void            setArrowPrev(Arrow* arrow);
        void            setHead(bool isHead);
        void            setSubscript(const std::string& str);
        void            setBGColor(const sf::Color& color);
        void            setNumColor(const sf::Color& color);
        void            setPos(sf::Vector2f pos);
        void            setPrePos(sf::Vector2f pos);

        Node*           getNext();
        Node*           getPrev();
        unsigned int    getCategory() const;
        int             getScaleTime() const;
        Arrow*          getArrowNext();
        Arrow*          getArrowPrev();
        sf::Vector2f    getPrePos();

        std::unique_ptr<Arrow> makeArrow(Node* dest);

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
        sf::Vector2f        prePos;

    private:
        void            drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
};