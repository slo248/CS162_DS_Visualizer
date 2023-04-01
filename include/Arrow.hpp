#pragma once

#include <Entity.hpp>

class Arrow: public Entity
{
    public:
        const float             HEIGHT_EACH=5.f;
        const float             SECOND_WIDTH=10.f;
        const sf::Color         DEFAULT_COLOR=sf::Color::Blue;

    public:
        Arrow(sf::Vector2f dist);
        int             getCategory() const;

    private:
        sf::RectangleShape      mLine;
        sf::ConvexShape         mTriangle;
    
    private:
        void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            updateCurrent(sf::Time dt);
};

struct ArrowMover
{
    ArrowMover(float vx, float vy): 
        mVelocityX(vx), mVelocityY(vy){};
    void operator() (Arrow& arrow, sf::Time dt) const{
        arrow.accelerate(mVelocityX, mVelocityY);
    }

    private:
        float mVelocityX;
        float mVelocityY;
};