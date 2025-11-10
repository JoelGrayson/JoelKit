template <typename T>
bool BST<T>::insert(T el) {
    Node<T>* new_node = new Node(el);

    if (root == nullptr) {
        root = new_node;
        return true;
    }

    Node<T>* parent = root; //parent of the new node
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
    Node<T>* current_node = root;
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
bool BST<T>::contains_rec_helper(T el, Node<T>* current_node) const {
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
using ParentChildRel = std::tuple<Node<T>*, Node<T>*, bool>;

template <typename T>
std::optional<ParentChildRel<T>> BST<T>::find_node_and_its_parent(T el) {
    Node<T>* parent = nullptr;
    Node<T>* child = root;
    bool is_left = false;

    while (child != nullptr) {
        if (el == child->value) {
            return std::make_tuple<ParentChildRel<T>>(parent, child, is_left);
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
    Node<T>* parent = std::get<0>(unwrapped_res); //parent of node to delete
    Node<T>* child = std::get<1>(unwrapped_res); //node to delete
    bool is_left = std::get<2>(unwrapped_res);
    
    // Case 2: deleting a leaf
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
    if (parent == nullptr) { //root
        if (child->right != nullptr) {
            Node<T>* replacement = child->right;
            Node<T>* parent_of_replacement = child;
            while (replacement->left != nullptr) {
                parent_of_replacement = replacement;
                replacement = replacement->left;
            }

            child->value = replacement->value; //delete the old node and replace it with the new node's value
            parent_of_replacement->left = replacement->right;

            return true;
        }

        // In this case, since child cannot be a leaf, it only has a ->left
        Node<T>* replacement = child->left;
        Node<T>* parent_of_replacement = child;
        while (replacement->right != nullptr) {
            parent_of_replacement = replacement;
            replacement = replacement->right;
        }

        child->value = replacement->value;
        parent_of_replacement->right = replacement->left;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    bst.print_node(bst.root);
    return os;
}

template <typename T>
void BST<T>::print_node(Node<T>* n) const {
    if (n == nullptr) return;

    if (n->left != nullptr) {
        std::cout << "(";
        print_node(n->left);
        std::cout << ") ← ";
    }
    std::cout << n->value;
    if (n->right != nullptr) {
        std::cout << " → (";
        print_node(n->right);
        std::cout << ")";
    }
}

