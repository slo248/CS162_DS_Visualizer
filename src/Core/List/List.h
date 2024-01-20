#ifndef LIST_H
#define LIST_H

#include "Container.h"

template <class T>
class List : public Container {
   public:
    virtual ~List() = 0;

    List& pushFront(T value) = 0;
    List& pushBack(T value) = 0;
    List& insert(int index, T value) = 0;

    T popFront() = 0;
    T popBack() = 0;
    T erase(int index) = 0;
    List& erase(T value) = 0;

    List& update(int index, T value) = 0;
    List& update(T src, T dst) = 0;

    T& search(int index) = 0;
};

#endif  // LIST_H
