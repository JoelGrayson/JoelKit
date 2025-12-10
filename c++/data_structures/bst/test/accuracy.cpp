#include "../bst.h"
#include "../../linked_list/linked_list.h"

void add_balanced_items(LinkedList<double>& items, int levels_left, double lower_bound, double upper_bound) {
    if (levels_left <= 0)
        return;
    
    double middle = (lower_bound + upper_bound) / 2;
    items.insert(middle);
    add_balanced_items(items, levels_left - 1, lower_bound, middle);
    add_balanced_items(items, levels_left - 1, middle, upper_bound);
}

int main() {
    BST<double> b;

    LinkedList<double> items;
    add_balanced_items(items, 4, 0, 100);
    
    for (double item : items) {
        // std::cout << item << " ";
        b.insert(item);
    }

    // std::cout << b << std::endl;

    
    for (double item : items) {
        BST<double> backup = b; //TODO: make copying work

        LinkedList<double> before_list = b.to_list(); //TODO: make list work with LinkedList
        before_list.remove(item);
        b.remove(item);
        LinkedList<double> after_list = b.to_list();

        b = backup; //TODO: make moving work
    }

    
    return 0;
}

