#ifndef ARROW_H
#define ARROW_H

#include "Node.h"

struct Arrow
{
    Node* src;
    Node* dest;
    Arrow(Node* src, Node* dest) : src(src), dest(dest) {}
};

#endif // ARROW_H