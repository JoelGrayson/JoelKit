#include "queue.h"

template <typename T>
Queue<T>::Queue() {
    elems_ = new T[capacity_];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] elems_;
}

template <typename T>
std::size_t Queue<T>::size() const {
    int out = t_ - h_;
    if (out < 0)
        out += capacity_;
    return out;
}

template <typename T>
bool Queue<T>::is_empty() const {
    return size() == 0;
}

template <typename T>
void Queue<T>::enqueue(T elem) {
    elems_[t_] = elem;
    t_++;
    if (t_ == capacity_)
        t_ = 0;
    
    if (t_ == h_)
        grow(); //grow size by 2-fold
}

template <typename T>
T Queue<T>::dequeue() {
    T out = elems_[h_];
    h_++;
    if (h_ == capacity_)
        h_ = 0;
    return out;
}

template <typename T>
T Queue<T>::peek() const {
    T out = elems_[h_];
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
    int p = q.h_;
    while (p != q.t_) {
        std::cout << q.elems_[p] << " ";

        p++;
        if (p == q.capacity_) //loop around
            p = 0;
    }
    return os;
}

template <typename T>
void Queue<T>::grow() { //called when h_ is the same as t_
    // std::cout << "Grow called" << std::endl;
    size_t new_capacity = capacity_ * 2;
    T* new_elems = new T[new_capacity];
    int new_elem_i = 0;

    int p = h_;
    bool first_round = true;
    while (!(p == t_ && first_round == false)) { //DeMorganed: p != t_ || first_round
        new_elems[new_elem_i] = elems_[p];
        new_elem_i++;
        
        p++;
        if (p == capacity_)
            p = 0;
        first_round = false;
    }
    
    delete[] elems_;
    elems_ = new_elems;
    capacity_ = new_capacity;

    h_ = 0;
    t_ = new_elem_i;
}

