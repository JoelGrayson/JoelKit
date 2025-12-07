#include "test_a_sorting_alg.h"

// In place
void test_a_sorting_alg(std::function<void(std::vector<int>&)> sorting_fn) {
    std::vector<std::pair<
        std::vector<int>,
        std::vector<int>
    >> lists = {
        { { 2, 4, 1, 3, -1, 0 }, { -1, 0, 1, 2, 3, 4 } },
        { { -1, 1 }, { -1, 1 } },
        { { 10, 100, 2 }, { 2, 10, 100 } },
    };
    
    for (auto l : lists) {
        auto first = l.first; //starts unsorted
        auto sorted = l.second;
        sorting_fn(first);
        if (!lists_equal(first, sorted)) {
            std::cout << "Not sorted properly" << std::endl;
        }
    }
}

// Return sorted copy
void test_a_sorting_alg(std::function<std::vector<int>(std::vector<int>)> sorting_fn) {

}
