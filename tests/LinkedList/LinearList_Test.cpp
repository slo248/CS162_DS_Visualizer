#include "LinearList.hpp"

#include <gtest/gtest.h>

TEST(LinearList, CreateAndDestroy) {
    Core::LinearList<int> linlist;
    Core::LinearList<float> linlist2;
    Core::LinearList<char> linlist3;
    Core::LinearList<std::string> linlist4;
    ASSERT_EQ(linlist.size(), 0);
    ASSERT_EQ(linlist2.size(), 0);
    ASSERT_EQ(linlist3.size(), 0);
    ASSERT_EQ(linlist4.size(), 0);
}

TEST(LinearList, PushFront) {
    Core::LinearList<int> linlist;
    linlist.pushFront(1);
    linlist.pushFront(2);
    linlist.pushFront(3);
    linlist.pushFront(4);
    linlist.pushFront(5);
    // 5 4 3 2 1
    ASSERT_EQ(linlist.size(), 5);
    ASSERT_EQ(linlist.popFront(), 5);
    ASSERT_EQ(linlist.popFront(), 4);
    ASSERT_EQ(linlist.popFront(), 3);
    ASSERT_EQ(linlist.popFront(), 2);
    ASSERT_EQ(linlist.popFront(), 1);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, PushBack) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    ASSERT_EQ(linlist.popBack(), 5);
    ASSERT_EQ(linlist.popBack(), 4);
    ASSERT_EQ(linlist.popBack(), 3);
    ASSERT_EQ(linlist.popBack(), 2);
    ASSERT_EQ(linlist.popBack(), 1);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, Insert) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.insert(0, 4);
    linlist.insert(2, 5);
    linlist.insert(4, 6);
    // 4 1 5 2 3 6
    ASSERT_EQ(linlist.size(), 6);
    ASSERT_EQ(linlist.popFront(), 4);
    ASSERT_EQ(linlist.popFront(), 1);
    ASSERT_EQ(linlist.popFront(), 5);
    ASSERT_EQ(linlist.popFront(), 2);
    ASSERT_EQ(linlist.popFront(), 6);
    ASSERT_EQ(linlist.popFront(), 3);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, PopFront) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushFront(2);
    linlist.insert(1, 3);
    // 2 3 1
    ASSERT_EQ(linlist.size(), 3);
    ASSERT_EQ(linlist.popFront(), 2);
    ASSERT_EQ(linlist.popFront(), 3);
    ASSERT_EQ(linlist.popFront(), 1);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, PopBack) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushFront(2);
    linlist.insert(1, 3);
    // 2 3 1
    ASSERT_EQ(linlist.size(), 3);
    ASSERT_EQ(linlist.popBack(), 1);
    ASSERT_EQ(linlist.popBack(), 3);
    ASSERT_EQ(linlist.popBack(), 2);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, EraseByIndex) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    ASSERT_EQ(linlist.eraseByIndex(0), 1);
    ASSERT_EQ(linlist.eraseByIndex(2), 4);
    ASSERT_EQ(linlist.eraseByIndex(1), 3);
    ASSERT_EQ(linlist.eraseByIndex(0), 2);
    ASSERT_EQ(linlist.eraseByIndex(0), 5);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, EraseByValue) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    linlist.eraseByValue(1);
    linlist.eraseByValue(4);
    linlist.eraseByValue(3);
    linlist.eraseByValue(2);
    linlist.eraseByValue(5);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, UpdateByIndex) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    linlist.updateByIndex(0, 10);
    linlist.updateByIndex(2, 20);
    linlist.updateByIndex(4, 30);
    ASSERT_EQ(linlist.popFront(), 10);
    ASSERT_EQ(linlist.popFront(), 2);
    ASSERT_EQ(linlist.popFront(), 20);
    ASSERT_EQ(linlist.popFront(), 4);
    ASSERT_EQ(linlist.popFront(), 30);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, UpdateByValue) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    linlist.updateByValue(1, 10);
    linlist.updateByValue(3, 20);
    linlist.updateByValue(5, 30);
    ASSERT_EQ(linlist.popFront(), 10);
    ASSERT_EQ(linlist.popFront(), 2);
    ASSERT_EQ(linlist.popFront(), 20);
    ASSERT_EQ(linlist.popFront(), 4);
    ASSERT_EQ(linlist.popFront(), 30);
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, Search) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    ASSERT_EQ(linlist.search(1), 0);
    ASSERT_EQ(linlist.search(2), 1);
    ASSERT_EQ(linlist.search(3), 2);
    ASSERT_EQ(linlist.search(4), 3);
    ASSERT_EQ(linlist.search(5), 4);
    ASSERT_EQ(linlist.search(10), -1);
    ASSERT_EQ(linlist.search(20), -1);
    ASSERT_EQ(linlist.search(30), -1);
    ASSERT_EQ(linlist.search(40), -1);
    ASSERT_EQ(linlist.search(50), -1);
    ASSERT_EQ(linlist.size(), 5);
}

TEST(LinearList, Clear) {
    Core::LinearList<int> linlist;
    linlist.pushBack(1);
    linlist.pushBack(2);
    linlist.pushBack(3);
    linlist.pushBack(4);
    linlist.pushBack(5);
    // 1 2 3 4 5
    ASSERT_EQ(linlist.size(), 5);
    linlist.clear();
    ASSERT_EQ(linlist.size(), 0);
}

TEST(LinearList, Empty) {
    Core::LinearList<int> linlist;
    ASSERT_TRUE(linlist.empty());
    linlist.pushBack(1);
    ASSERT_FALSE(linlist.empty());
    linlist.pushBack(2);
    ASSERT_FALSE(linlist.empty());
    linlist.pushBack(3);
    ASSERT_FALSE(linlist.empty());
    linlist.pushBack(4);
    ASSERT_FALSE(linlist.empty());
    linlist.pushBack(5);
    ASSERT_FALSE(linlist.empty());
    linlist.popFront();
    ASSERT_FALSE(linlist.empty());
    linlist.popFront();
    ASSERT_FALSE(linlist.empty());
    linlist.popFront();
    ASSERT_FALSE(linlist.empty());
    linlist.popFront();
    ASSERT_FALSE(linlist.empty());
    linlist.popFront();
    ASSERT_TRUE(linlist.empty());
}

TEST(LinearList, Size) {
    Core::LinearList<int> linlist;
    ASSERT_EQ(linlist.size(), 0);
    linlist.pushBack(1);
    ASSERT_EQ(linlist.size(), 1);
    linlist.pushBack(2);
    ASSERT_EQ(linlist.size(), 2);
    linlist.pushBack(3);
    ASSERT_EQ(linlist.size(), 3);
    linlist.pushBack(4);
    ASSERT_EQ(linlist.size(), 4);
    linlist.pushBack(5);
    ASSERT_EQ(linlist.size(), 5);
    linlist.popFront();
    ASSERT_EQ(linlist.size(), 4);
    linlist.popFront();
    ASSERT_EQ(linlist.size(), 3);
    linlist.popFront();
    ASSERT_EQ(linlist.size(), 2);
    linlist.popFront();
    ASSERT_EQ(linlist.size(), 1);
    linlist.popFront();
    ASSERT_EQ(linlist.size(), 0);
}
