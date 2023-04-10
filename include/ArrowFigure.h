#ifndef ARROW_FIGURE_H
#define ARROW_FIGURE_H

#include <SFML/Graphics.hpp>

class ArrowFigure:
    public sf::Drawable,
    public sf::Transformable,
    private sf::NonCopyable
{
public:
    sf::RectangleShape* bar;
    sf::ConvexShape* triangle;

    ArrowFigure(float barWidth, float triangleWidth, float heightEach);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;    
};

#endif // ARROW_FIGURE_H