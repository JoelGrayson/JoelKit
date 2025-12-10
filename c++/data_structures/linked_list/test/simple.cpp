#include "../linked_list.h"
#include <iostream>

int main() {
    LinkedList<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert_back(9);
    
    std::cout << l << std::endl;
    std::cout << l.size() << std::endl;
    std::cout << "Head: " << l.head->value << std::endl;
    std::cout << "Tail: " << l.tail->value << std::endl;
    l.insert_at(2, -4);
    l[1]->value = 88;
    std::cout << l << std::endl;
    return 0;
}

