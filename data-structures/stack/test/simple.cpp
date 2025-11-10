#include <iostream>
#include "../stack.h"

int main() {
    Stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    std::cout << s.pop() << std::endl;
    std::cout << s.peek() << std::endl;
    s.push(9);
    std::cout << s << std::endl;
    return 0;
}

