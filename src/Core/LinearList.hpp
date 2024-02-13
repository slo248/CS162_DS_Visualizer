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

    virtual void pushFront(const T& data);
    virtual void pushBack(const T& data);
    virtual void insert(size_t pos, const T& data);

    virtual T popFront();
    virtual T popBack();
    virtual T eraseByIndex(size_t pos);
    virtual void eraseByValue(const T& target);
    virtual void clear();

    virtual void updateByIndex(size_t pos, const T& newData);
    virtual void updateByValue(const T& oldData, const T& newData);

    virtual size_t search(const T& target);

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
