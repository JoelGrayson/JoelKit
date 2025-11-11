#include <optional>

template <typename T>
bool BST<T>::insert(T el) {
    BSTNode<T>* new_node = new BSTNode<T>(el);

    if (root == nullptr) {
        root = new_node;
        return true;
    }

    BSTNode<T>* parent = root; //parent of the new node
    while (true) {
        if (el > parent->value) {
            if (parent->right == nullptr) {
                parent->right = new_node;
                return true;
            }
            parent = parent->right;
        } else if (el == parent->value) {
            return false;
        } else { // el < parent->value
            if (parent->left == nullptr) {
                parent->left = new_node;
                return true;
            }
            parent = parent->left;
        }
    }
}

template <typename T>
bool BST<T>::contains(T el) const { //iterative approach
    BSTNode<T>* current_node = root;
    while (current_node != nullptr) {
        if (el == current_node->value)
            return true;
        else if (el > current_node->value)
            current_node = current_node->right;
        else
            current_node = current_node->left;
    }
    return false;
}

template <typename T>
bool BST<T>::contains_rec(T el) const { //recursive implementation
    return contains_rec_helper(el, root);
}

template <typename T>
bool BST<T>::contains_rec_helper(T el, BSTNode<T>* current_node) const {
    if (current_node == nullptr)
        return false;
    if (current_node->value == el)
        return true;
    if (el > current_node->value) //it must be on the right if it is there
        return contains_rec_helper(el, current_node->right);
    else //el < current_node->value
        return contains_rec_helper(el, current_node->left);
}

template <typename T>
using ParentChildRel = std::tuple<BSTNode<T>*, BSTNode<T>*, bool>;

template <typename T>
std::optional<ParentChildRel<T>> BST<T>::find_node_and_its_parent(T el) {
    BSTNode<T>* parent = nullptr;
    BSTNode<T>* child = root;
    bool is_left = false;

    while (child != nullptr) {
        if (el == child->value) {
            return std::make_tuple(parent, child, is_left);
        } else if (el > child->value) { //go right
            parent = child;
            child = child->right;
            is_left = false;
        } else { //el < child->value, go left
            parent = child;
            child = child->left;
            is_left = true;
        }
    }
    
    return {};
}


template <typename T>
bool BST<T>::remove(T el) {
    std::optional<ParentChildRel<T>> res = find_node_and_its_parent(el);
    if (!res) //cannot remove it because it is not in the tree
        return false;
    
    ParentChildRel<T> unwrapped_res = res.value();
    BSTNode<T>* parent = std::get<0>(unwrapped_res); //parent of node to delete
    BSTNode<T>* child = std::get<1>(unwrapped_res); //node to delete
    bool is_left = std::get<2>(unwrapped_res);
    
    // Case 1: deleting a leaf
    if (child->left == nullptr && child->right == nullptr) {
        if (parent == nullptr) { //child is root node
            // In this case, deleting root node with nothing else in tree (root is leaf)
            root = nullptr;
            return true;
        }

        if (is_left) {
            parent->left = nullptr;
            return true;
        } else {
            parent->right = nullptr;
            return true;
        }
    }

    // Case 2: deleting root (that has children by not being a leaf)
    // Since it is the root, we have to update the root pointer (parent is nullptr)
    if (parent == nullptr) { //child is root
        if (child->right != nullptr) {
            BSTNode<T>* replacement = child->right;
            BSTNode<T>* parent_of_replacement = child;
            while (replacement->left != nullptr) {
                parent_of_replacement = replacement;
                replacement = replacement->left;
            }

            BSTNode<T>* old_replacement_right = replacement->right;
            replacement->left = child->left;
            replacement->right = child->right;
            root = replacement;
            
            delete child;

            parent_of_replacement->left = old_replacement_right;
            
            return true;
        }

        // In this case, since child cannot be a leaf, it only has a ->left
        BSTNode<T>* replacement = child->left;
        BSTNode<T>* parent_of_replacement = child;
        while (replacement->right != nullptr) {
            parent_of_replacement = replacement;
            replacement = replacement->right;
        }
        
        BSTNode<T>* old_replacement_left = replacement->left;
        replacement->left = child->left;
        root = replacement;
        // we already know replacement->right is null so it is fine

        delete child;

        parent_of_replacement->right = old_replacement_left;

        return true;
    }

    // Case 3: deleting a non-root interior node
    // Since it is an interior node, it has to have a child
    // Case 3a: deleted node has a right child
    if (child->right != nullptr) {
        BSTNode<T>* replacement = child->right;
        BSTNode<T>* parent_of_replacement = child;
        while (replacement->left != nullptr) {
            parent_of_replacement = replacement;
            replacement = replacement->left;
        }

        BSTNode<T>* old_replacement_right = replacement->right;
        replacement->left = child->left;
        if (child->right != replacement) {
            replacement->right = child->right;
        }

        if (is_left)
            parent->left = replacement;
        else
            parent->right = replacement;

        delete child;
        return true;
    }

    // Case 3b: deleted node only has a left child
    // implicitly, we know that child->left != nullptr since it is not a leaf and does not have a right node
    BSTNode<T>* replacement = child->left;
    BSTNode<T>* parent_of_replacement = child;

    while (replacement->right != nullptr) {
        parent_of_replacement = replacement;
        replacement = replacement->right;
    }

    BSTNode<T>* old_replacement_left = replacement->left;
    if (child->left != replacement) {
        replacement->left = child->left;
    }
    if (is_left)
        parent->left = replacement;
    else
        parent->right = replacement;
    parent_of_replacement->right = old_replacement_left;

    delete child;
    return true;
}

/** this printing method is nice because leave nodes are surrounded like so (3) */
template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    bst.print_node(bst.root, 0);
    return os;
}

template <typename T>
void BST<T>::print_node(BSTNode<T>* n, int level) const {
    if (n == nullptr) return;

    int paren_type = level % 4;
    char open_paren = '(';
    char close_paren = ')';
    if (paren_type == 1) {
        open_paren = '<';
        close_paren = '>';
    } else if (paren_type == 2) {
        open_paren = '{';
        close_paren = '}';
    } else if (paren_type == 3) {
        open_paren = '[';
        close_paren = ']';
    }
    
    if (n->left != nullptr) {
        std::cout << open_paren;
        print_node(n->left, level + 1);
        std::cout << close_paren << " ← ";
    }
    std::cout << n->value;
    if (n->right != nullptr) {
        std::cout << " → " << open_paren;
        print_node(n->right, level + 1);
        std::cout << close_paren;
    }
}

