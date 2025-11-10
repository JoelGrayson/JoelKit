#include "../queue.h"

int main() {
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << q << std::endl;
    
    return 0;
}

