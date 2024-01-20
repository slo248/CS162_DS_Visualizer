#ifndef LIST_H
#define LIST_H

#include "Container.h"

namespace Core {
template <class T>
class List : public Container {
   public:
    virtual void pushFront(T value) = 0;
    virtual void pushBack(T value) = 0;
    virtual void insert(int index, T value) = 0;

    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual T eraseByIndex(int index) = 0;
    virtual void eraseByValue(T value) = 0;

    virtual void updateByIndex(int index, T value) = 0;
    virtual void updateByValue(T oldValue, T newValue) = 0;

    virtual bool contains(T value) = 0;
};
}  // namespace Core

#endif  // LIST_H
