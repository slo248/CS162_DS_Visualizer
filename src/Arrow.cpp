#include "Arrow.h"
#include "Config.h"
#include "Motion.h"
#include <cmath>

void Arrow::update(ArrowFigure *arrowFig)
{
    // set position at the center of the source node
    arrowFig->setPosition(src->position);

    float dist=sqrt(pow(dest->position.x-src->position.x,2)+pow(dest->position.y-src->position.y,2))
        -2*CircleConfig::HALF_WIDTH;
    // scale length
    arrowFig->setScale(dist/ArrowConfig::WIDTH,1);

    // rotate
    float angle=atan2(dest->position.y-src->position.y,dest->position.x-src->position.x);
    arrowFig->setRotation(angle*180/acos(-1));

    // move arrow to just outside the node
    arrowFig->move(
        CircleConfig::HALF_WIDTH*cos(angle),
        CircleConfig::HALF_WIDTH*sin(angle)
    );
}

void Arrow::draw(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float nothing)
{
    update(arrowFig);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}

void Arrow::drawGrow(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float percent)
{
    arrowFig->setScale(arrowFig->getScale().x*Motion::Bezier(percent),1);
    draw(window, arrowFig, color, 0);
}
