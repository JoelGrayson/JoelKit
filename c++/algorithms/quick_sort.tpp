#include "quick_sort.h"
#include <random>

int find_pivot_index(int start_i, int end_i);

template <typename T>
std::vector<T> quick_sorted(const std::vector<T>& lst) {
    // Base case
    if (lst.size() <= 1)
        return lst;

    // Recursive case
    int pivot_i = find_pivot_index(0, lst.size());
    T pivot = lst[pivot_i];

    std::vector<T> left;
    std::vector<T> right;
    for (int curr_i = 0; curr_i < lst.size(); curr_i++) {
        if (curr_i == pivot_i) {
            continue;
        }
        T curr_val = lst[curr_i];
        if (curr_val <= pivot) {
            left.push_back(curr_val);
        } else {
            right.push_back(curr_val);
        }
    }

    std::vector<T> sorted_left = quick_sorted(left);
    std::vector<T> sorted_right = quick_sorted(right);
    
    std::vector<T> out = sorted_left;
    out.push_back(pivot);
    out.insert(out.end(), sorted_right.begin(), sorted_right.end());
    return out;
}


int find_pivot_index(int start_i, int end_i) {
    return start_i;
}


template <typename T>
void quick_sort(std::vector<T>& lst) {

}

