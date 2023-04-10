#include "ArrowFigure.h"

ArrowFigure::ArrowFigure(float barWidth, float triangleWidth, float heightEach)
{
    bar = new sf::RectangleShape;
    bar->setSize(sf::Vector2f(barWidth, heightEach));
    {
        sf::FloatRect bounds = bar->getLocalBounds();
        bar->setOrigin(
            0,
            bounds.top + bounds.height / 2.f
        );
    }

    triangle = new sf::ConvexShape;
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0, 0));
    triangle->setPoint(1, sf::Vector2f(triangleWidth, (3.f/2.f)*heightEach));
    triangle->setPoint(2, sf::Vector2f(0, 3*heightEach));
    {
        sf::FloatRect bounds = triangle->getLocalBounds();
        triangle->setOrigin(
            0,
            bounds.top + bounds.height / 2.f
        );
    }
    triangle->move(barWidth, 0);
}

void ArrowFigure::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform*=getTransform();
    target.draw(*bar, states);
    target.draw(*triangle, states);
}

void ArrowFigure::setFillColor(sf::Color color)
{
    bar->setFillColor(color);
    triangle->setFillColor(color);
}
