#include <string>
#include "../queue.h"

int main() {
    Queue<std::string> q;
    q.enqueue("First");
    q.enqueue("Second");
    q.enqueue("Third");

    std::cout << q << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q << std::endl;
    std::cout << q.peek() << std::endl;
    
    return 0;
}

