#include "SLL.h"

#include <gtest/gtest.h>

TEST(SLL, CreateAndDestroy) {
    Core::SLL<int> sll;
    Core::SLL<float> sll2;
    Core::SLL<char> sll3;
    Core::SLL<std::string> sll4;
}
