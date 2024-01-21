#include "SLL.h"

#include <gtest/gtest.h>

TEST(SLL, CreateAndDestroy) {
    Core::SLL<int> sll;
    Core::SLL<float> sll2;
    Core::SLL<char> sll3;
    Core::SLL<std::string> sll4;
}

TEST(SLL, PushFront_PopFront) {
    Core::SLL<int> sll;
    sll.pushFront(1);
    sll.pushFront(2);
    sll.pushFront(3);
    sll.pushFront(4);
    sll.pushFront(5);
    ASSERT_EQ(sll.size(), 5);
    ASSERT_EQ(sll.popFront(), 5);
    ASSERT_EQ(sll.popFront(), 4);
    ASSERT_EQ(sll.popFront(), 3);
    ASSERT_EQ(sll.popFront(), 2);
    ASSERT_EQ(sll.popFront(), 1);
    ASSERT_EQ(sll.size(), 0);
}

TEST(SLL, PushBack_PopBack) {
    Core::SLL<int> sll;
    sll.pushBack(1);
    sll.pushBack(2);
    sll.pushBack(3);
    sll.pushBack(4);
    sll.pushBack(5);
    ASSERT_EQ(sll.size(), 5);
    ASSERT_EQ(sll.popBack(), 5);
    ASSERT_EQ(sll.popBack(), 4);
    ASSERT_EQ(sll.popBack(), 3);
    ASSERT_EQ(sll.popBack(), 2);
    ASSERT_EQ(sll.popBack(), 1);
    ASSERT_EQ(sll.size(), 0);
}

TEST(SLL, Insert) {
    Core::SLL<int> sll;
    sll.pushBack(1);
    sll.pushBack(2);
    sll.pushBack(3);
    sll.insert(0, 4);
    sll.insert(2, 5);
    sll.insert(4, 6);
    // 4 1 5 2 3 6
    ASSERT_EQ(sll.size(), 6);
    ASSERT_EQ(sll.popFront(), 4);
    ASSERT_EQ(sll.popFront(), 1);
    ASSERT_EQ(sll.popFront(), 5);
    ASSERT_EQ(sll.popFront(), 2);
    ASSERT_EQ(sll.popFront(), 6);
    ASSERT_EQ(sll.popFront(), 3);
    ASSERT_EQ(sll.size(), 0);
}
