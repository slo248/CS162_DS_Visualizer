#ifndef LINEAR_LIST_HPP
#define LINEAR_LIST_HPP

#include "DS.hpp"
#include "memory"

namespace Core {
template <class T>
class LinearList : public DS {
   public:
    LinearList();
    ~LinearList();

    void pushFront(const T& data);
    void pushBack(const T& data);
    void insert(int pos, const T& data);

    T popFront();
    T popBack();
    T erase(int pos);
    void erase(const T& target);

   private:
    struct Node;
    typedef std::shared_ptr<Node> NodePtr;

    struct Node {
        T data;
        NodePtr next, prev;
        Node(T data = T()) : data(data) { next = prev = nullptr; };
    };

   private:
    NodePtr head, tail;
};

#include "LinearList.inl"
}  // namespace Core

#endif  // LINEAR_LIST_HPP
