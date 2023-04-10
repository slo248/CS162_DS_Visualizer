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
    ListNode<T>* getPrev(int cnt=1);
};

template <class T>
inline ListNode<T> *ListNode<T>::getNext(int cnt)
{
    ListNode<T>* cur=this;
    while(cnt--){ 
        if(cur->next==nullptr) break;
        cur=cur->next;
    }
    return cur;
}

template <class T>
inline ListNode<T> *ListNode<T>::getPrev(int cnt)
{
    ListNode<T>* cur=this;
    while(cnt--){ 
        if(cur->prev==nullptr) break;
        cur=cur->prev;
    }
    return cur;
}

#endif // LIST_NODE_H
