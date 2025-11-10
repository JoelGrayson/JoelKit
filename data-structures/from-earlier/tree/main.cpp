#include <iostream>
#include <vector>

struct Node {
    std::string value;
    std::vector<Node*> children;
    // int numChildren;
};

Node* makeTree() {
    Node* b = new Node{ "B", {} };
    Node* i = new Node{ "I", {} };
    Node* j = new Node{ "J", {} };
    Node* e = new Node{ "E", {i, j} };
    Node* f = new Node{ "F", {} };
    Node* k = new Node{ "K", {} };
    Node* m = new Node{ "M", {} };
    Node* l = new Node{ "L", {m} };
    Node* g = new Node{ "G", {k, l}};
    Node* h = new Node{ "H", {} };
    Node* c = new Node{ "C", {e, f, g, h}};
    Node* d = new Node{ "D", {} };
    Node* a = new Node{ "A", {b, c, d}};
    return a;
}

void printTree(Node* root, const std::string& prefix) {
    if (root->children.empty()) { //Just print leaf
        std::cout << prefix << root->value << std::endl;
        return;
    }
    std::cout << prefix << root->value << ":" << std::endl;
    for (Node* newRoot : root->children) {
        printTree(newRoot, prefix+"----");
    }
}
// void printTreeRec(Node* root, const std::string& prefix) {
//     if (root->children.empty()) { //Just print leaf
//         std::cout << prefix << root->value << std::endl;
//         return;
//     }
//     std::cout << prefix << root->value << " {" << std::endl;
//     for (Node* newRoot : root->children) {
//         printTreeRec(newRoot, prefix+"    ");
//     }
//     std::cout << prefix << "}" << std::endl;
// }
void printTree(Node* root) {
    if (root==nullptr) return;
    printTree(root, "");
}

int main() {
    Node* tree=makeTree();
    printTree(tree);
}

