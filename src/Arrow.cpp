#include "Arrow.h"

void Arrow::update(ArrowFigure *arrowFig)
{
    arrowFig->setPosition(src->position);
}

void Arrow::draw(sf::RenderWindow *window, ArrowFigure *arrowFig, sf::Color color)
{
    update(arrowFig);
    arrowFig->setFillColor(color);
    window->draw(*arrowFig);
}
