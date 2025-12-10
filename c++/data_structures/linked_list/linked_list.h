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
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    
    LinkedList();
    
    /** insert at front of list */
    void insert(T value);
    void insert_back(T value);
    void insert_at(size_t index, T value);
    
    Node<T>* operator[](size_t index);
    
    size_t size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll);
};

#include "linked_list.tpp"

