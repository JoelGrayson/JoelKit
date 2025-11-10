#include "../linked-list.h"
#include <iostream>

int main() {
    LinkedList<int> l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add_to_end(9);

    std::cout << l << std::endl;
    std::cout << l.size() << std::endl;
    std::cout << "Head: " << l.head->value << std::endl;
    std::cout << "Tail: " << l.get_tail()->value << std::endl;
    return 0;
}

