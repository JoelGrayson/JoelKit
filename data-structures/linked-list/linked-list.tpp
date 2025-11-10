#include "linked-list.h"
#include <iostream>

template <typename T>
Node<T>::Node(T value, Node<T>* next) {
    this->value = value;
    this->next = next;
}

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
size_t LinkedList<T>::size() {
    Node<T>* n = this->head;
    size_t out = 0;
    while (n != nullptr) {
        out++;
        n = n->next;
    }
    return out;
}

template <typename T>
void LinkedList<T>::add_value_to_front(T value) {
    Node<T>* new_node = new Node(value); //heap allocation
    add_node_to_front(new_node);
}

template <typename T>
void LinkedList<T>::add_node_to_front(Node<T>* n) {
    n->next = head;
    head = n;
}

template <typename T>
Node<T>* LinkedList<T>::get_tail() {
    Node<T>* n = head;
    Node<T>* pN = n; //previous n
    while (n != nullptr) {
        pN = n;
        n = n->next;
    }
    return pN;
}

template <typename T>
void LinkedList<T>::add_value_to_back(T value) {
    Node<T>* new_node = new Node(value);
    add_node_to_back(new_node);
}

template <typename T>
void LinkedList<T>::add_node_to_back(Node<T>* n) {
    Node<T>* tail = get_tail();
    if (tail == nullptr) {
        add_node_to_front(n);
    } else {
        tail->next = n;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll) {
    Node<T>* n = ll.head;
    while (n != nullptr) {
        os << n->value << " ";
        n = n->next;
    }
    os << std::endl;
    return os;
}

