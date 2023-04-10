#include "Arrow.h"
#include "Config.h"
#include <cmath>

void Arrow::update(ArrowFigure *arrowFig)
{
    // set position at the center of the source node
    arrowFig->setPosition(src->position);

    float dist=sqrt(pow(dest->position.x-src->position.x,2)+pow(dest->position.y-src->position.y,2))
        -2*(CircleConfig::RADIUS+CircleConfig::THICKNESS);
    // scale length
    arrowFig->setScale(dist/(ArrowConfig::BAR_WIDTH+ArrowConfig::TRIANGLE_WIDTH),1);

    // rotate
    float angle=atan2(dest->position.y-src->position.y,dest->position.x-src->position.x);
    arrowFig->setRotation(angle*180/acos(-1));

    // move arrow to just outside the node
    arrowFig->move(
        (CircleConfig::RADIUS+CircleConfig::THICKNESS)*cos(angle),
        (CircleConfig::RADIUS+CircleConfig::THICKNESS)*sin(angle)
    );
}

void Arrow::draw(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float nothing)
{
    update(arrowFig);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}
