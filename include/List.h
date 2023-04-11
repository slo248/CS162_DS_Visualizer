#ifndef LIST_H
#define LIST_H

#include "ListElement.h"

template<class T>
class List
{
public:
    List();
    ~List();

    ListElement<T>* begin();
    ListElement<T>* end();
    ListElement<T>* rbegin();
    ListElement<T>* rend();

    void clear();
    bool empty() const;

    int size() const;

    void pushFront(ListElement<T>* node);
    void pushFront(const T& data);
    void pushBack(ListElement<T>* node);
    void pushBack(const T& data);

    void insert(ListElement<T>* node, int after);

private:
    ListElement<T>* head;
    ListElement<T>* tail;
    int num;
};

template <class T>
inline List<T>::List()
{
    head=tail=nullptr;
    num=0;
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
inline ListElement<T> *List<T>::begin()
{
    return head;
}

template <class T>
inline ListElement<T> *List<T>::end()
{
    return nullptr;
}

template <class T>
inline ListElement<T> *List<T>::rbegin()
{
    return tail;
}

template <class T>
inline ListElement<T> *List<T>::rend()
{
    return nullptr;
}

template <class T>
inline void List<T>::clear()
{
    while(head!=nullptr){
        ListElement<T>* tmp=head;
        head=head->next;
        delete tmp;
    }
    head=tail=nullptr;
    num=0;
}

template <class T>
inline bool List<T>::empty() const
{
    return head==nullptr;
}

template <class T>
inline int List<T>::size() const
{
    return num;
}

template <class T>
inline void List<T>::pushFront(ListElement<T> *node)
{
    if(head==nullptr){
        head=tail=node;
    }else{
        head->prev=node;
        node->next=head;
        head=node;
    }
    num++;
}

template <class T>
inline void List<T>::pushFront(const T &data)
{
    pushFront(new ListElement<T>(data));
}

template <class T>
inline void List<T>::pushBack(ListElement<T>* node)
{
    if(head==nullptr){
        head=tail=node;
    }else{
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
    num++;
}

template <class T>
inline void List<T>::pushBack(const T &data)
{
    pushBack(new ListElement<T>(data));
}

template <class T>
inline void List<T>::insert(ListElement<T> *node, int after)
{
    if(after==0) pushFront(node);
    else if(after==num) pushBack(node);
    else{
        ListElement<T>* cur=head;
        while(after--)
            cur=cur->next;

        node->next=cur;
        node->prev=cur->prev;
        cur->prev->next=node;
        cur->prev=node;
        num++;
    }
}

#endif // LIST_H
