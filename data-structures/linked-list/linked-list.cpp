#include <iostream>
// #include <cstddef>

class Node {
public:
    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }

    int value;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    size_t size() {
        Node* n = this->head;
        size_t out = 0;
        while (n != nullptr) {
            out++;
            n = n->next;
        }
        return out;
    }

    void add_value_to_front(int value) {
        Node* new_node = new Node(value); //heap allocation
        add_node_to_front(new_node);
    }

    void add_node_to_front(Node* n) {
        n->next = head;
        head = n;
    }
    
    Node* get_tail() {
        Node* n = head;
        Node* pN = n; //previous n
        while (n != nullptr) {
            pN = n;
            n = n->next;
        }
        return pN;
    }
    
    void add_value_to_back(int value) {
        Node* new_node = new Node(value);
        add_node_to_back(new_node);
    }
    
    void add_node_to_back(Node* n) {
        Node* tail = get_tail();
        if (tail == nullptr) {
            add_node_to_front(n);
        } else {
            tail->next = n;
        }
    }

    void print() {
        Node* n = head;
        while (n != nullptr) {
            std::cout << n->value << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList l;
    l.add_value_to_front(1);
    l.add_value_to_front(2);
    l.add_value_to_front(3);
    l.add_value_to_back(9);
    l.print();
    std::cout << l.size() << std::endl;
    std::cout << "Head: " << l.head->value << std::endl;
    std::cout << "Tail: " << l.get_tail()->value << std::endl;
    return 0;
}

