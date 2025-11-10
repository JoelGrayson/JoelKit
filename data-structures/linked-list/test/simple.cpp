#include "../linked-list.h"
#include <iostream>

int main() {
    LinkedList<int> l;
    l.add_value_to_front(1);
    l.add_value_to_front(2);
    l.add_value_to_front(3);
    l.add_value_to_back(9);

    std::cout << l << std::endl;
    std::cout << l.size() << std::endl;
    std::cout << "Head: " << l.head->value << std::endl;
    std::cout << "Tail: " << l.get_tail()->value << std::endl;
    return 0;
}

