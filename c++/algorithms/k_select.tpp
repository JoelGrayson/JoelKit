#include "k_select.h"
#include <iostream>

template <typename T>
using IndexAndValue = std::pair<int, T>;

/** Finds median of medians. @returns its index in the passed-in list as well as its value */
template <typename T>
IndexAndValue<T> find_pivot(std::vector<T> list) {
    std::vector<IndexAndValue<T>> medians;
    for (int i = 0; i < list.size(); i += 5) {
        std::vector<IndexAndValue<T>> five;
        for (int j = i; j < list.size() && j < i + 5; j++) {
            five.push_back(
                std::make_pair(j, list[j])
            );
        }
        insertion_sort(five, [](IndexAndValue<T> item) { return item.second; }); //insertion sort is nice on small lists
        IndexAndValue<T> median = five[five.size() / 2];
        medians.push_back(median);
    }
    insertion_sort(medians, [](IndexAndValue<T> item) { return item.second; });
    IndexAndValue<T> median_of_medians = medians[medians.size() / 2];
    return median_of_medians;
}

template <typename T>
T k_select(std::vector<T> list, int k) {
    if (list.size() < 10) { //base case
        merge_sort(list);
        return list[k];
    }
    
    IndexAndValue<T> pivot = find_pivot(list);

    if (k == pivot.first)
        return pivot.second;
    
    // Partition
    std::vector<T> left;
    std::vector<T> right;
    for (int i = 0; i < list.size(); i++) {
        T item = list[i];
        if (i == pivot.first) //skip the pivot. It is neither in left nor right
            continue;
        if (item <= pivot.second)
            left.push_back(item);
        else
            right.push_back(item);
    }
    
    if (k < left.size()) {
        return k_select(left, k);
    } else {
        return k_select(right, k - left.size() - 1); //takes out the left and the pivot
    }
}

