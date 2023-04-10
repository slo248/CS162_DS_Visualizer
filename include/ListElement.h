#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

template<class T>
struct ListElement
{
    T data;
    ListElement<T>* next=nullptr;
    ListElement<T>* prev=nullptr;
    ListElement(T data=T()):data(data){}

    ListElement<T>* getNext(int cnt=1);
    ListElement<T>* getPrev(int cnt=1);
};

template <class T>
inline ListElement<T> *ListElement<T>::getNext(int cnt)
{
    ListElement<T>* cur=this;
    while(cnt--){ 
        if(cur->next==nullptr) break;
        cur=cur->next;
    }
    return cur;
}

template <class T>
inline ListElement<T> *ListElement<T>::getPrev(int cnt)
{
    ListElement<T>* cur=this;
    while(cnt--){ 
        if(cur->prev==nullptr) break;
        cur=cur->prev;
    }
    return cur;
}

#endif // LIST_ELEMENT_H
