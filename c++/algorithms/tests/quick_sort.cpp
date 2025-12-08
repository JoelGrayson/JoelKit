#include <vector>
#include <iostream>
#include "../quick_sort.h"
#include "test_a_sorting_alg.h"
#include "../../utils/print_vector.h"

int main() {
    std::vector<int> v { 3, 6, 5, 4, 1, 8, 7, 2 };
    print_vector(v);
    quick_sorted(v);
    print_vector(v);

    test_a_sorting_alg([](std::vector<int>& v) { //because it is a template function, this wrapper converts the parameter to an int-based function
        v = quick_sorted(v);
    });
}

