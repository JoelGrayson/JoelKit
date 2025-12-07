#include "bubble_sort.h"

template <typename T>
void bubble_sort(std::vector<T>& l) {
    for (int i = 0; i < l.size() - 1; i++) {
        for (int j = 0; j < l.size() - 1 - i; j++) {
            if (l[j] > l[j + 1]) {
                T temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }
}

