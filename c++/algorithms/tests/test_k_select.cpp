#include "../k_select.h"
#include <iostream>

int main() {
    // std::vector<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    // find_pivot(l);

    std::vector<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    std::cout << k_select(l, 2) << " should be 3\n";
    
    std::vector<int> l2 { 1, 9, 5, 2, 2, 4, 6, 7 }; //[1, 2, 2, 4, 5, 6, 7, 9]
    std::cout << k_select(l2, 3) << " should be 4\n";
    std::cout << k_select(l2, 2) << std::endl;
    std::cout << k_select(l2, 1) << std::endl;
    std::cout << k_select(l2, l2.size() - 2) << std::endl;
    std::cout << k_select(l2, l2.size() - 1) << std::endl;
}

