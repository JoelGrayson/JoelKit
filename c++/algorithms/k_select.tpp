#include "k_select.h"
#include <iostream>

template <typename T>
T find_pivot(std::vector<T> list) {
    // Finds median of medians
    std::vector<T> medians;
    for (int i = 0; i < list.size(); i += 5) {
        std::vector<T> five;
        for (int j = i; j < list.size() && j < i + 5; j++) {
            // std::cout << list[j] << " ";
            five.push_back(list[j]);
        }
        insertion_sort(five); //insertion sort is nice on small lists
        T median = five[2]; //median because third element is the middle element of the list of five
        medians.push_back(median);
    }
    insertion_sort(medians);
    merge_sort(medians);
    T median_of_medians = medians[medians.size() / 2];
    return median_of_medians;
}

template <typename T>
T k_select(std::vector<T> list, int k) {
    if (list.size() < 10) { //base case
        merge_sort(list);
        return list[k];
    }
    
    T pivot = find_pivot(list);
    // TODO: use partition
    // std::vector<T> left;
    // std::vector<T> right;
    // for (T item : list) {
    //     if (item <= pivot)
    //         left.push_back(item);
    //     else
    //         right.push_back(item);
    // }
    
    if (pivot < left.size()) {
        return k_select(left, k);
    } else {
        return k_select(right, k - left.size());
    }
}

