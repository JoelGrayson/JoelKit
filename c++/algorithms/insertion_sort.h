#pragma once

#include <vector>
#include <functional>

template <typename T>
void insertion_sort(std::vector<T>& v);

/** T is the type of the item in a list, U is the type of the key that is gotten from an item in the list (of type T). U is comparable, T is an object. */
template <typename T, typename U>
void insertion_sort(std::vector<T>& v, std::function<U(T)> key);

template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v);


#include "insertion_sort.tpp"
