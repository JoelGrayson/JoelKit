#include "../bst.h"
#include <iostream>

int main() {
    BSTNode<int>* n = new BSTNode(3);
    BSTNode<int>* n2 = n;

    std::cout << n->value << std::endl;
    return 0;
}

