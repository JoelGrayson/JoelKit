#pragma once

#include <iostream>

template <typename T>
class Node {
public:
    Node(T value);
    Node(T value, Node* next);

    T value;
    Node* next;
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList();

    size_t size();

    void add(T value);
    void add_node(Node<T>* n);
    
    Node<T>* get_tail();
    void add_to_end(T value);
    void add_node_to_end(Node<T>* n);

    T operator[](int index) {
        n = head;
        for (int i)
        return 0;
    }
    void insert_at(int index, T value) {
        
    }

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll);
};

#include "linked-list.tpp"

