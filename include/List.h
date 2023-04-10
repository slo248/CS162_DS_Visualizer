#ifndef LIST_H
#define LIST_H

#include "List.h"

template<class T>
class List
{
public:
    List();
    ~List();

private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
};

#endif // LIST_H