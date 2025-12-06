#include <vector>
#include <iostream>
#include "../insertion_sort.h"
#include "../../utils/print_vector.h"

int main() {
    std::vector<int> v { 4, 1, 8, 2 }; //sorted: 1, 2, 4, 8
    print_vector(v);
    insertion_sort(v);
    std::cout << std::endl;
    print_vector(v);
}

