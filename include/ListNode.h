#ifndef LIST_NODE_H
#define LIST_NODE_H

template<class T>
struct ListNode
{
    T data;
    ListNode<T>* next=nullptr;
    ListNode<T>* prev=nullptr;
    ListNode(T data=T()):data(data){}
    ListNode<T>* getNext(int cnt=1);
};

template <class T>
inline ListNode<T> *ListNode<T>::getNext(int cnt)
{
    ListNode<T>* cur=this;
    while(cnt--) cur=cur->next;
    return cur;
}

#endif // LIST_NODE_H
