#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

void printTree(Node* n) {
    if (n==nullptr) {
        return;
    }
    printTree(n->left);
    std::cout << " " << n->value << " ";
    printTree(n->right);
}

void deleteTree(Node* root) {
    if (root==nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root=new Node{ 3, nullptr, nullptr };
    root->left=new Node{ 4, nullptr, nullptr };
    printTree(root);
}

