#pragma once
#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
};

template <typename T>
class BST {
public:
    Node<T>* root = nullptr;

    /** returns if an element was inserted */
    bool insert(T el);
    bool contains(T el) const;
    bool contains_rec(T el) const;
    /** returns if an element was removed */
    bool remove(T el);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const BST<U>& bst);
private:
    void print_node(Node<T>* n) const;
    bool contains_rec_helper(T el, Node<T>* current_node) const;
};

#include "bst.tpp"

