#include "Arrow.h"
#include "Config.h"
#include "Motion.h"
#include "Global.h"

void Arrow::update(ArrowFigure *arrowFig)
{
    const float Pi=acos(-1);

    // set position at the center of the source node
    arrowFig->setPosition(src->position);

    float dist=sqrt(pow(dest->position.x-src->position.x,2)+pow(dest->position.y-src->position.y,2))
        -2*Config::Circle::HALF_WIDTH;
    // scale length
    arrowFig->setScale(dist/Config::Arrow::WIDTH,1);

    // rotate
    float angle=atan2(dest->position.y-src->position.y,dest->position.x-src->position.x);
    arrowFig->setRotation(angle*180/Pi);

    float tmp=0;
    if(flag) tmp=Pi/6;

    // move arrow to just outside the node
    arrowFig->move(
        Config::Circle::HALF_WIDTH*cos(angle+tmp),
        Config::Circle::HALF_WIDTH*sin(angle+tmp)
    );
}

void Arrow::draw(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color)
{
    update(arrowFig);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}

void Arrow::drawGrow(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float percent)
{
    update(arrowFig);
    arrowFig->setScale(arrowFig->getScale().x*Motion::Bezier(percent),1);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}

void Arrow::drawShrink(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float percent)
{
    update(arrowFig);
    arrowFig->setScale(arrowFig->getScale().x*Motion::Bezier(1-percent),1);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}

void Arrow::drawFadeIn(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float percent)
{
    update(arrowFig);
    arrowFig->setFillColor(sf::Color(color.r,color.g,color.b,255*Motion::Bezier(percent)));
    window->draw(*arrowFig);
}

void Arrow::drawFadeOut(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float percent)
{
    update(arrowFig);
    arrowFig->setFillColor(sf::Color(color.r,color.g,color.b,255*Motion::Bezier(1-percent)));
    window->draw(*arrowFig);
}
