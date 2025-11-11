#include "../bst.h"
#include <iostream>

int main() {
    Node<int>* n = new Node(3);
    Node<int>* n2 = n;

    std::cout << n->value << std::endl;
    return 0;
}

