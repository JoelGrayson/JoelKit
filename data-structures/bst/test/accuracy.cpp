#include "../bst.h"
// #include "../../linked-list/linked-list.h"
#include <vector>

void add_balanced_items(std::vector<double>& items, int levels_left, double lower_bound, double upper_bound) {
    if (levels_left <= 0)
        return;
    
    double middle = (lower_bound + upper_bound) / 2;
    items.push_back(middle);
    add_balanced_items(items, levels_left - 1, lower_bound, middle);
    add_balanced_items(items, levels_left - 1, middle, upper_bound);
}

int main() {
    BST<double> b;

    std::vector<double> items;
    add_balanced_items(items, 4, 0, 100);
    
    for (double item : items) {
        // std::cout << item << " ";
        b.insert(item);
    }

    // std::cout << b << std::endl;

    
    for (double item : items) {
        BST<double> backup = b; //TODO: make copying work

        auto before_list = b.to_list(); //TODO: make list work with LinkedList
        
        b.remove(item);
        b.to_list();

        b = backup; //TODO: make moving work
    }

    
    return 0;
}

