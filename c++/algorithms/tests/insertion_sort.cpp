#include <vector>
#include <iostream>
#include "../insertion_sort.h"
#include "../../utils/print_vector.h"

int main() {
    std::vector<int> v { 8, 2, 4, 1, 3 };
    print_vector(v);
    insertion_sort(v);
    print_vector(v);
    
    std::vector<int> v2 { 8, 2, 4, 1, 3 };
    std::vector<int> sorted_v2 = insertion_sorted(v2);
    print_vector(sorted_v2);
}

