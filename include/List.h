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

template <class T>
inline List<T>::List()
{
    head=tail=nullptr;
    size=0;
}

template <class T>
inline List<T>::~List()
{
    while(head!=nullptr){
        ListNode<T>* tmp=head;
        head=head->next;
        delete tmp;
    }
}

#endif // LIST_H
