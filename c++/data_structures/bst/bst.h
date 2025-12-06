#pragma once

#include <iostream>
#include <utility> //std::tuple
#include <optional>

template <typename T>
struct BSTNode {
    T value;
    BSTNode<T>* left = nullptr;
    BSTNode<T>* right = nullptr;

    BSTNode(T value): value(value) {}
};

/** templates are helpful so you can make it a BST of any comparable object (int, float, double, Decimal, string) */
template <typename T>
class BST {
public:
    BSTNode<T>* root = nullptr;

    /** returns if an element was inserted */
    bool insert(T el);
    bool contains(T el) const;
    bool contains_rec(T el) const;
    /** @returns if an element was removed */
    bool remove(T el);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const BST<U>& bst);
private:
    void print_node(BSTNode<T>* n, int level = 0) const;
    bool contains_rec_helper(T el, BSTNode<T>* current_node) const;
    
    /**
     * This method is useful for remove
     * @returns optional<(parent, child, is_left)>; pointer to parent node, pointer to child node, boolean for if it is the left child (true is left, false is right). if the item is not found, returns None
     * */
    std::optional<std::tuple<BSTNode<T>*, BSTNode<T>*, bool>> find_node_and_its_parent(T el);
};

#include "bst.tpp"

