#include "../k_select.h"
#include <iostream>

int main() {
    // std::vector<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    // find_pivot(l);

    std::vector<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    std::cout << k_select(l, 4);
}

