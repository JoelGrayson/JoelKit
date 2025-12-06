#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class Stack {
private:
    T* elems_;
    size_t size_ = 0;
    size_t capacity_ = 100;

    /**
     * when capacity is exceeded, double capacity
     */
    void grow();

public:
    Stack();
    Stack(size_t capacity);
    ~Stack();

    void push(T el);
    T pop();
    T peek() const;
    
    size_t size() const;
    bool is_empty() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& s);
};

#include "stack.tpp"

