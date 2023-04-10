#include "Arrow.h"
#include "Config.h"

void Arrow::update(ArrowFigure *arrowFig)
{
    arrowFig->setPosition(src->position+sf::Vector2f(CircleConfig::RADIUS,0));
}

void Arrow::draw(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color, float nothing)
{
    update(arrowFig);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}
