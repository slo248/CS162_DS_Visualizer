#ifndef ARROW_H
#define ARROW_H

#include "Node.h"
#include "ArrowFigure.h"

struct Arrow
{
    Node* src;
    Node* dest;
    Arrow(Node* src, Node* dest) : src(src), dest(dest) {}

    void update(ArrowFigure* arrowFig);
};

#endif // ARROW_H