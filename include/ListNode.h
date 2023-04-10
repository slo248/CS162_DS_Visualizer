#ifndef LIST_NODE_H
#define LIST_NODE_H

template<class T>
struct ListNode
{
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;
    ListNode();
    ListNode(T data);
    ~ListNode();
};

#endif // LIST_NODE_H