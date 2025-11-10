#include <cstddef>

template <typename T>
class Queue {
private:
    T* elems;

public:
    int MAX_SIZE = 100;

    std::size_t size();
    bool is_empty();

    T peek();
    void enqueue(T new_element);
    T dequeue();
};

