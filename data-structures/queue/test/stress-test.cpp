#include "../queue.h"

int main() {
    Queue<int> q;
    for (int i = 0; i < 800; i++) {
        q.enqueue(i);
    }
    std::cout << q << "\n\n\n";
    
    for (int i = 0; i < 600; i++) {
        q.dequeue();
    }
    std::cout << q << std::endl;

    return 0;
}

