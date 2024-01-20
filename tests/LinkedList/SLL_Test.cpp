#include "SLL.h"

#include <iostream>

void createAndDestroy() {
    std::cerr << "SLL Test: Create and destroy" << std::endl;
    Core::SLL<int> sll;
    Core::SLL<float> sll2;
    Core::SLL<char> sll3;
    Core::SLL<std::string> sll4;
}

int main() {
    createAndDestroy();
    return 0;
}
