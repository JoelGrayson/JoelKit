#pragma once

#include <iostream>
#include <utility> //std::tuple
#include <optional>

template <typename T>
struct Node {
    T value;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    Node(T value): value(value) {}
};

template <typename T>
class BST {
public:
    Node<T>* root = nullptr;

    /** returns if an element was inserted */
    bool insert(T el);
    bool contains(T el) const;
    bool contains_rec(T el) const;
    /** @returns if an element was removed */
    bool remove(T el);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const BST<U>& bst);
private:
    void print_node(Node<T>* n, int level = 0) const;
    bool contains_rec_helper(T el, Node<T>* current_node) const;
    
    /**
     * This method is useful for remove
     * @returns optional<(parent, child, is_left)>; pointer to parent node, pointer to child node, boolean for if it is the left child (true is left, false is right). if the item is not found, returns None
     * */
    std::optional<std::tuple<Node<T>*, Node<T>*, bool>> find_node_and_its_parent(T el);
};

#include "bst.tpp"

