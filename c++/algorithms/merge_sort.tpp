#include "merge_sort.h"

template <typename T>
std::vector<T> merge_sorted(const std::vector<T>& l) {
    if (l.size() == 0 || l.size() == 1)
        return l;
    
    int middle = l.size() / 2;
    std::vector<T> left(l.begin(), l.begin() + middle);
    std::vector<T> right(l.begin() + middle, l.end());
    std::vector<T> left_sorted = merge_sorted(left);
    std::vector<T> right_sorted = merge_sorted(right);
    return merge(left_sorted, right_sorted);
}

template <typename T>
std::vector<T> merge(const std::vector<T>& l1, const std::vector<T>& l2) {
    std::vector<T> merged(l1.size() + l2.size());
    auto merged_it = merged.begin();

    auto i1 = l1.begin();
    auto i2 = l2.begin();
    while (i1 != l1.end() || i2 != l2.end()) { //while there is still something to process
        if (i1 == l1.end()) { //must do l2
            *merged_it = *i2;
            merged_it++;
            i2++;
        } else if (i2 == l2.end()) { //must do l1
            *merged_it = *i1;
            merged_it++;
            i1++;
        } else {
            if (*i1 < *i2) {
                *merged_it = *i1;
                i1++;
                merged_it++;
            } else {
                *merged_it = *i2;
                i2++;
                merged_it++;
            }
        }
    }
    return merged;
}

template <typename T>
void merge_sort(std::vector<T>& l) {
    l = merge_sorted(l);
}

