#include <iostream>
#include "../stack.h"

int main() {
    Stack<int> s;
    
    for (int i = 0; i < 110; i++) {
        s.push(i);
    }

    std::cout << s << std::endl;
    std::cout << s.is_empty() << std::endl;
    std::cout << s.size() << std::endl;
    
    return 0;
}

