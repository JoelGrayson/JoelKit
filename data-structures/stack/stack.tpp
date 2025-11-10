#include "stack.h"

#include <iostream>

template <typename T>
Stack<T>::Stack() {
    elems_ = new T[capacity_];
}

template <typename T>
Stack<T>::Stack(size_t capacity) {
    capacity_ = capacity;
    elems_ = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elems_;
}

template <typename T>
void Stack<T>::push(T elem) {
    if (capacity_ == size_) {
        grow();
    }
    elems_[size_] = elem;
    size_++;
}

template <typename T>
T Stack<T>::pop() {
    T elem = elems_[size_ - 1];
    size_--;
    return elem;
}

template <typename T>
T Stack<T>::peek() const {
    return elems_[size_ - 1];
}

template <typename T>
size_t Stack<T>::size() const {
    return size_;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return size_ == 0;
}

template <typename T>
void Stack<T>::grow() {
    size_t new_capacity_ = capacity_ * 2;
    T* new_elems_ = new T[new_capacity_];

    // Insert the old elements
    for (int i = 0; i < capacity_; i++) {
        new_elems_[i] = elems_[i];
    }
    
    delete[] elems_;
    elems_ = new_elems_;
    capacity_ = new_capacity_;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    for (int i = 0; i < s.size_; i++) {
        std::cout << s.elems_[i] << " ";
    }
    return os;
}

