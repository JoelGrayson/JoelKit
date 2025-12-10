#pragma once

#include <vector>
#include <functional>

template <typename T>
void insertion_sort(std::vector<T>& v);

/** T is the type of the item in a list, KeyFunc is a callback that extracts the key from an item. */
template <typename T, typename KeyFunc>
void insertion_sort(std::vector<T>& v, KeyFunc key);

template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v);


#include "insertion_sort.tpp"
