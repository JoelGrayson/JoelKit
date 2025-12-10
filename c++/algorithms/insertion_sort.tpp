#include "insertion_sort.h"

// Uses key. This way, it can be objects being sorted by their key.
template <typename T, typename KeyFunc>
void insertion_sort(std::vector<T>& v, KeyFunc key) {
    for (int i = 1; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && key(v[curr_i - 1]) > key(el)) {
            v[curr_i] = v[curr_i - 1];
            curr_i--;
        }
        v[curr_i] = el;
    }
}

template <typename T>
void insertion_sort(std::vector<T>& v) {
    insertion_sort(v, [](T el) { return el; });
}


template <typename T, typename KeyFunc>
std::vector<T> insertion_sorted(const std::vector<T>& v, KeyFunc key) {
    std::vector<T> sorted_list(v.size());
    for (int i = 0; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && key(sorted_list[curr_i - 1]) > key(el)) {
            sorted_list[curr_i] = sorted_list[curr_i - 1];
            curr_i--;
        }
        sorted_list[curr_i] = el;
    }
    return sorted_list;
}

template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v) {
    insertion_sorted(v, [](T el) { return el; });
}

