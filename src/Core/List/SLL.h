#ifndef SLL_H
#define SLL_H

#include "List.h"

namespace Core {
template <class T>
class SLL : public List<T> {
   public:
    SLL();
    ~SLL();

    void pushFront(T value);
    void pushBack(T value);
    void insert(int index, T value);

    T popFront();
    T popBack();
    T eraseByIndex(int index);
    void eraseByValue(T value);

    void updateByIndex(int index, T value);
    void updateByValue(T oldValue, T newValue);

    bool contains(T value);

   private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* mHead;
    Node* mTail;
};

}  // namespace Core

#include "SLL.inl"

#endif  // SLL_H
