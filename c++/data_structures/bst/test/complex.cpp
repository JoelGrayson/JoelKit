#include "../bst.h"
#include <iostream>

int main() {
    BST<int> b;
    int to_insert[] = { 100, 50, 25, 75, 60, 80, 79, 77, 76, 78, 150, 125, 110, 175, 160, 155, 170, 165, 172, 200 };
    for (int el : to_insert) {
        b.insert(el);
        // std::cout << el << std::endl;
    }
    
    std::cout << b << std::endl;
}

