import Yt from "@/components/Yt";
import videos from "../../videos";
import Toggle from "../Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';

export default function LinkedList() {
    return <>
        <Toggle title="Linked List">
            {/* <Yt>{videos.kSelect}</Yt> */}

            <p>This linked list implementation allows for O(1) insertion to the front and back.</p>

            <h4>C++</h4>
            <h5>Header File</h5>
            <SyntaxHighlighter language="cpp" style={oneDark}>
                {bstCppH}
            </SyntaxHighlighter>
            <h5>Implementation File</h5>
            <SyntaxHighlighter language="cpp" style={oneDark}>
                {bstCpp}
            </SyntaxHighlighter>
        </Toggle>
    </>;
}

const bstCppH = `#pragma once

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
};`;

const bstCpp = `template <typename T>
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
LinkedList<T>::LinkedList() {}

template <typename T>
void LinkedList<T>::insert(T value) {
    Node<T>* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
    if (tail == nullptr)
        tail = new_head;
}

template <typename T>
void LinkedList<T>::insert_back(T value) {
    Node<T>* new_tail = new Node(value);
    tail->next = new_tail; //old tail now points to new tail
    tail = new_tail;
}

template <typename T>
void LinkedList<T>::insert_at(size_t index, T value) {
    Node<T>* n = new Node(value);
    
    Node<T>* before = head; //node right before where the new node will be
    for (int i = 0; i < index - 1; i++) {
        before = before->next;
    }
    n->next = before->next;
    before->next = n;
}

template <typename T>
Node<T>* LinkedList<T>::operator[](size_t index) {
    Node<T>* n = head;
    for (int i = 0; i < index; i++) {
        n = n->next;
    }
    return n;
}

template <typename T>
size_t LinkedList<T>::size() const {
    Node<T>* n = this->head;
    size_t out = 0;
    while (n != nullptr) {
        out++;
        n = n->next;
    }
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l) {
    Node<T>* n = l.head;
    while (n != nullptr) {
        os << n->value << " ";
        n = n->next;
    }
    return os;
}`;

