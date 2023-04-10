#ifndef LIST_H
#define LIST_H

#include "ListElement.h"

template<class T>
class List
{
public:
    List();
    ~List();

    List<T>* begin();
    List<T>* end();
    List<T>* rbegin();
    List<T>* rend();

    void pushBack(const ListElement<T>* node);
    void pushBack(const T& data);

private:
    ListElement<T>* head;
    ListElement<T>* tail;
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
        ListElement<T>* tmp=head;
        head=head->next;
        delete tmp;
    }
}

template <class T>
inline List<T> *List<T>::begin()
{
    return head;
}

template <class T>
inline List<T> *List<T>::end()
{
    return nullptr;
}

template <class T>
inline List<T> *List<T>::rbegin()
{
    return tail;
}

template <class T>
inline List<T> *List<T>::rend()
{
    return nullptr;
}

template <class T>
inline void List<T>::pushBack(const ListElement<T>* node)
{
    if(head==nullptr){
        head=tail=node;
    }else{
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
    size++;
}

template <class T>
inline void List<T>::pushBack(const T &data)
{
    pushBack(new ListElement<T>(data));
}

#endif // LIST_H
