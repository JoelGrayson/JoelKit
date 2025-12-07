#include <vector>
#include <iostream>
#include "../bubble_sort.h"
#include "test_a_sorting_alg.h"
#include "../../utils/print_vector.h"

int main() {
    std::vector<int> v { 8, 2, 4, 1, 3 };
    print_vector(v);
    bubble_sort(v);
    print_vector(v);

    test_a_sorting_alg([](std::vector<int>& v) { //because it is a template function, this wrapper converts the parameter to an int-based function
        bubble_sort(v);
    });
}

