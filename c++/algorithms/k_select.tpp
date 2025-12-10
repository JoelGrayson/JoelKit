#include "k_select.h"
#include <iostream>

template <typename T>
using IndexAndValue = std::pair<int, T>;

/** Finds median of medians. @returns its index in the passed-in list as well as its value */
template <typename T, typename KeyFunc>
IndexAndValue<T> find_pivot(std::vector<T> list, KeyFunc key) {
    std::vector<IndexAndValue<T>> medians;
    for (int i = 0; i < list.size(); i += 5) {
        std::vector<IndexAndValue<T>> five;
        for (int j = i; j < list.size() && j < i + 5; j++) {
            five.push_back(
                std::make_pair(j, list[j])
            );
        }
        insertion_sort(five, [&key](IndexAndValue<T> item) { return key(item.second); }); //insertion sort is nice on small lists
        IndexAndValue<T> median = five[five.size() / 2]; //do this instead of [2] in the case that |five|<5
        medians.push_back(median);
    }
    insertion_sort(medians, [](IndexAndValue<T> item) { return item.second; });
    IndexAndValue<T> median_of_medians = medians[medians.size() / 2];
    // IndexAndValue<T> median_of_medians = k_select(medians, medians.size() / 2, [&key](IndexAndValue<T> el) {
    //     return key(el.second);
    // });
    return median_of_medians;
}

template <typename T, typename KeyFunc>
T k_select(std::vector<T> list, int k, KeyFunc key) {
    if (list.size() < 50) //base case
        return insertion_sorted(list, key)[k];
    
    
    IndexAndValue<T> pivot = find_pivot(list, key);

    // Partition
    std::vector<T> left;
    std::vector<T> right;
    for (int i = 0; i < list.size(); i++) {
        T item = list[i];
        if (i == pivot.first) //skip the pivot. It is neither in left nor right
            continue;
        if (key(item) <= key(pivot.second))
            left.push_back(item);
        else
            right.push_back(item);
    }
    
    // Recursive step
    if (k == left.size()) //is pivot
        return pivot.second;
    else if (k < left.size())
        return k_select(left, k, key);
    else
        return k_select(right, k - left.size() - 1, key); //takes out the left and the pivot
}

template <typename T>
T k_select(std::vector<T> list, int k) {
    return k_select(list, k, [](T el) { return el; }); //use the self selector
}

