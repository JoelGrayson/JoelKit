#include "JStack.h"

int main() {
    JStack<int> s(1);
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << s << std::endl;
    return 0;
}

