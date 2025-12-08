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
    // Naive implementation
    return start_i;

    if (start_i == end_i)
        return start_i;

    return start_i + rand() % (end_i - start_i);
}


template <typename T>
void quick_sort_helper(std::vector<T>& lst, int start_i, int end_i) {
    int the_range = end_i - start_i;
    if (the_range == 0 || the_range == 1)
        return;
    
    int og_pivot_i = find_pivot_index(start_i, end_i);
    int new_pivot_i = partition(lst, start_i, end_i, og_pivot_i);

    quick_sort_helper(lst, start_i, new_pivot_i);
    quick_sort_helper(lst, new_pivot_i + 1, end_i);
}

template <typename T>
void quick_sort(std::vector<T>& lst) {
    quick_sort_helper(lst, 0, lst.size());
}

