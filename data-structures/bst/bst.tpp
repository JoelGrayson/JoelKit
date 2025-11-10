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
bool BST<T>::remove(T el) {
    
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

