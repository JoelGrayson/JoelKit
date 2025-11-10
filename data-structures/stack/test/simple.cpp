#include <iostream>
#include "../stack.h"

int main() {
    Stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);

    std::cout << s << std::endl;
    
    return 0;
}

