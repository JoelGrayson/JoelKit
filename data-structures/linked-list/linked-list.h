#pragma once
#include <iostream>

class Node {
public:
    Node(int value, Node* next);

    Node(int value);

    int value;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList();

    size_t size();

    void add_value_to_front(int value);
    void add_node_to_front(Node* n);
    
    Node* get_tail();
    void add_value_to_back(int value);
    void add_node_to_back(Node* n);

    void print();
};

#include "linked-list.tpp"

