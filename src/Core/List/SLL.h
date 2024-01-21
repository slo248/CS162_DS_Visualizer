#ifndef SLL_H
#define SLL_H

#include <memory>

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

    void init();
    void clear();

   private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;
        Node(T value, std::unique_ptr<Node> next = nullptr) {
            this->value = value;
            this->next = std::move(next);
        }
    };
    typedef std::unique_ptr<Node> NodePtr;

    NodePtr mHead;
};

}  // namespace Core

#include "SLL.inl"

#endif  // SLL_H
