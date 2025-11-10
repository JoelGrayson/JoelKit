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

    void add_value_to_front(T value);
    void add_node_to_front(Node<T>* n);
    
    Node<T>* get_tail();
    void add_value_to_back(T value);
    void add_node_to_back(Node<T>* n);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll);
};

#include "linked-list.tpp"

