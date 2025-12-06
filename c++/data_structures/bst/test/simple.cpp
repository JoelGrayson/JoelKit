#include "../bst.h"
#include <iostream>

int main() {
    BST<int> b;
    b.insert(5);
    b.insert(3);
    b.insert(2);
    b.insert(1);
    b.insert(4);
    b.insert(7);
    b.insert(6);
    b.insert(9);

    // std::cout << 1 << b.contains(6) << b.contains_rec(6) << std::endl;
    // std::cout << 0 << b.contains(8) << b.contains_rec(8) << std::endl;
    // std::cout << 1 << b.contains(2) << b.contains_rec(2) << std::endl;
    // std::cout << 1 << b.contains(4) << b.contains_rec(4) << std::endl;
    // std::cout << 0 << b.contains(0) << b.contains_rec(0) << std::endl;

    std::cout << b << std::endl;
    std::cout << (b.remove(2) ? "Removed\n" : "Something went wrong while removing\n");
    // b.remove(1);
    std::cout << b << std::endl;



    return 0;
}

