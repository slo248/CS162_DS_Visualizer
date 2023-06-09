#ifndef ARROW_H
#define ARROW_H

#include "Node.h"
#include "ArrowFigure.h"

struct Arrow
{
    Node* src;
    Node* dest;
    bool flag;
    Arrow(Node* src=nullptr, Node* dest=nullptr, bool flag=false) : 
        src(src), dest(dest), flag(flag) {}

    void update(ArrowFigure* arrowFig);

    // draw
    void draw(sf::RenderWindow* window, ArrowFigure* arrowFig, sf::Color color);
    void drawGrow(sf::RenderWindow* window, ArrowFigure* arrowFig, sf::Color color, float percent);
    void drawShrink(sf::RenderWindow* window, ArrowFigure* arrowFig, sf::Color color, float percent);
    void drawFadeIn(sf::RenderWindow* window, ArrowFigure* arrowFig, sf::Color color, float percent);
    void drawFadeOut(sf::RenderWindow* window, ArrowFigure* arrowFig, sf::Color color, float percent);
};

#endif // ARROW_H