#include "partition.h"

template <typename T>
int partition(std::vector<T> lst, int start_i, int end_i, int pivot_i) {
    T p = lst[pivot_i];

    // 1. Put pivot at beginning
    lst[pivot_i] = lst[start_i];
    lst[start_i] = p;

    // 2.
    int l_i = start_i + 1;
    for (int r_i = start_i + 1; r_i < end_i; r_i++) {
        T v = lst[r_i];
        if (v > p) {
            continue;
        }
        if (v <= p) {
            T rhat = lst[l_i];
            lst[l_i] = lst[r_i];
            lst[r_i] = rhat;
            l_i++;
        }
    }
    // 3. Move pivot to end of the left
    lst[start_i] = lst[l_i - 1];
    lst[l_i - 1] = p;
    return l_i - 1;
}

