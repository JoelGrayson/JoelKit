#include "linked-list.h"
#include <iostream>

Node::Node(int value, Node* next) {
    this->value = value;
    this->next = next;
}

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

size_t LinkedList::size() {
    Node* n = this->head;
    size_t out = 0;
    while (n != nullptr) {
        out++;
        n = n->next;
    }
    return out;
}

void LinkedList::add_value_to_front(int value) {
    Node* new_node = new Node(value); //heap allocation
    add_node_to_front(new_node);
}

void LinkedList::add_node_to_front(Node* n) {
    n->next = head;
    head = n;
}

Node* LinkedList::get_tail() {
    Node* n = head;
    Node* pN = n; //previous n
    while (n != nullptr) {
        pN = n;
        n = n->next;
    }
    return pN;
}

void LinkedList::add_value_to_back(int value) {
    Node* new_node = new Node(value);
    add_node_to_back(new_node);
}

void LinkedList::add_node_to_back(Node* n) {
    Node* tail = get_tail();
    if (tail == nullptr) {
        add_node_to_front(n);
    } else {
        tail->next = n;
    }
}

void LinkedList::print() {
    Node* n = head;
    while (n != nullptr) {
        std::cout << n->value << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

