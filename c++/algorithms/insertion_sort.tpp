#include "insertion_sort.h"

template <typename T>
void insertion_sort(std::vector<T>& v) {
    for (int i = 1; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && v[curr_i - 1] > el) {
            v[curr_i] = v[curr_i - 1];
            curr_i--;
        }
        v[curr_i] = el;
    }
}

template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v) {
    std::vector<T> sorted_list(v.size());
    for (int i = 0; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && sorted_list[curr_i - 1] > el) {
            sorted_list[curr_i] = sorted_list[curr_i - 1];
            curr_i--;
        }
        sorted_list[curr_i] = el;
    }
    return sorted_list;
}

