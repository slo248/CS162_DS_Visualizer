// #include "SLL.h"

// #include <gtest/gtest.h>

// TEST(SLL, CreateAndDestroy) {
//     Core::SLL<int> sll;
//     Core::SLL<float> sll2;
//     Core::SLL<char> sll3;
//     Core::SLL<std::string> sll4;
//     ASSERT_EQ(sll.size(), 0);
//     ASSERT_EQ(sll2.size(), 0);
//     ASSERT_EQ(sll3.size(), 0);
//     ASSERT_EQ(sll4.size(), 0);
// }

// TEST(SLL, PushFront) {
//     Core::SLL<int> sll;
//     sll.pushFront(1);
//     sll.pushFront(2);
//     sll.pushFront(3);
//     sll.pushFront(4);
//     sll.pushFront(5);
//     // 5 4 3 2 1
//     ASSERT_EQ(sll.size(), 5);
//     ASSERT_EQ(sll.popFront(), 5);
//     ASSERT_EQ(sll.popFront(), 4);
//     ASSERT_EQ(sll.popFront(), 3);
//     ASSERT_EQ(sll.popFront(), 2);
//     ASSERT_EQ(sll.popFront(), 1);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, PushBack) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     ASSERT_EQ(sll.popBack(), 5);
//     ASSERT_EQ(sll.popBack(), 4);
//     ASSERT_EQ(sll.popBack(), 3);
//     ASSERT_EQ(sll.popBack(), 2);
//     ASSERT_EQ(sll.popBack(), 1);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, Insert) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.insert(0, 4);
//     sll.insert(2, 5);
//     sll.insert(4, 6);
//     // 4 1 5 2 3 6
//     ASSERT_EQ(sll.size(), 6);
//     ASSERT_EQ(sll.popFront(), 4);
//     ASSERT_EQ(sll.popFront(), 1);
//     ASSERT_EQ(sll.popFront(), 5);
//     ASSERT_EQ(sll.popFront(), 2);
//     ASSERT_EQ(sll.popFront(), 6);
//     ASSERT_EQ(sll.popFront(), 3);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, PopFront) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushFront(2);
//     sll.insert(1, 3);
//     // 2 3 1
//     ASSERT_EQ(sll.size(), 3);
//     ASSERT_EQ(sll.popFront(), 2);
//     ASSERT_EQ(sll.popFront(), 3);
//     ASSERT_EQ(sll.popFront(), 1);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, PopBack) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushFront(2);
//     sll.insert(1, 3);
//     // 2 3 1
//     ASSERT_EQ(sll.size(), 3);
//     ASSERT_EQ(sll.popBack(), 1);
//     ASSERT_EQ(sll.popBack(), 3);
//     ASSERT_EQ(sll.popBack(), 2);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, EraseByIndex) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     ASSERT_EQ(sll.eraseByIndex(0), 1);
//     ASSERT_EQ(sll.eraseByIndex(2), 4);
//     ASSERT_EQ(sll.eraseByIndex(1), 3);
//     ASSERT_EQ(sll.eraseByIndex(0), 2);
//     ASSERT_EQ(sll.eraseByIndex(0), 5);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, EraseByValue) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     sll.eraseByValue(1);
//     sll.eraseByValue(4);
//     sll.eraseByValue(3);
//     sll.eraseByValue(2);
//     sll.eraseByValue(5);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, UpdateByIndex) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     sll.updateByIndex(0, 10);
//     sll.updateByIndex(2, 20);
//     sll.updateByIndex(4, 30);
//     ASSERT_EQ(sll.popFront(), 10);
//     ASSERT_EQ(sll.popFront(), 2);
//     ASSERT_EQ(sll.popFront(), 20);
//     ASSERT_EQ(sll.popFront(), 4);
//     ASSERT_EQ(sll.popFront(), 30);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, UpdateByValue) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     sll.updateByValue(1, 10);
//     sll.updateByValue(3, 20);
//     sll.updateByValue(5, 30);
//     ASSERT_EQ(sll.popFront(), 10);
//     ASSERT_EQ(sll.popFront(), 2);
//     ASSERT_EQ(sll.popFront(), 20);
//     ASSERT_EQ(sll.popFront(), 4);
//     ASSERT_EQ(sll.popFront(), 30);
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, Contains) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     ASSERT_TRUE(sll.contains(1));
//     ASSERT_TRUE(sll.contains(2));
//     ASSERT_TRUE(sll.contains(3));
//     ASSERT_TRUE(sll.contains(4));
//     ASSERT_TRUE(sll.contains(5));
//     ASSERT_FALSE(sll.contains(10));
//     ASSERT_FALSE(sll.contains(20));
//     ASSERT_FALSE(sll.contains(30));
//     ASSERT_FALSE(sll.contains(40));
//     ASSERT_FALSE(sll.contains(50));
//     ASSERT_EQ(sll.size(), 5);
// }

// TEST(SLL, Clear) {
//     Core::SLL<int> sll;
//     sll.pushBack(1);
//     sll.pushBack(2);
//     sll.pushBack(3);
//     sll.pushBack(4);
//     sll.pushBack(5);
//     // 1 2 3 4 5
//     ASSERT_EQ(sll.size(), 5);
//     sll.clear();
//     ASSERT_EQ(sll.size(), 0);
// }

// TEST(SLL, Empty) {
//     Core::SLL<int> sll;
//     ASSERT_TRUE(sll.empty());
//     sll.pushBack(1);
//     ASSERT_FALSE(sll.empty());
//     sll.pushBack(2);
//     ASSERT_FALSE(sll.empty());
//     sll.pushBack(3);
//     ASSERT_FALSE(sll.empty());
//     sll.pushBack(4);
//     ASSERT_FALSE(sll.empty());
//     sll.pushBack(5);
//     ASSERT_FALSE(sll.empty());
//     sll.popFront();
//     ASSERT_FALSE(sll.empty());
//     sll.popFront();
//     ASSERT_FALSE(sll.empty());
//     sll.popFront();
//     ASSERT_FALSE(sll.empty());
//     sll.popFront();
//     ASSERT_FALSE(sll.empty());
//     sll.popFront();
//     ASSERT_TRUE(sll.empty());
// }

// TEST(SLL, Size) {
//     Core::SLL<int> sll;
//     ASSERT_EQ(sll.size(), 0);
//     sll.pushBack(1);
//     ASSERT_EQ(sll.size(), 1);
//     sll.pushBack(2);
//     ASSERT_EQ(sll.size(), 2);
//     sll.pushBack(3);
//     ASSERT_EQ(sll.size(), 3);
//     sll.pushBack(4);
//     ASSERT_EQ(sll.size(), 4);
//     sll.pushBack(5);
//     ASSERT_EQ(sll.size(), 5);
//     sll.popFront();
//     ASSERT_EQ(sll.size(), 4);
//     sll.popFront();
//     ASSERT_EQ(sll.size(), 3);
//     sll.popFront();
//     ASSERT_EQ(sll.size(), 2);
//     sll.popFront();
//     ASSERT_EQ(sll.size(), 1);
//     sll.popFront();
//     ASSERT_EQ(sll.size(), 0);
// }
