#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class Queue {
private:
    T* elems_;
    int h_ = 0; //index of head
    int t_ = 0; //index of tail
    size_t capacity_ = 100;

    void grow();
    
public:
    Queue();
    ~Queue();

    std::size_t size() const;
    bool is_empty() const;

    void enqueue(T new_element);
    T dequeue();
    T peek() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U>& q);
};

#include "queue.tpp"

