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

