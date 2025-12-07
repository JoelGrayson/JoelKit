#pragma once

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& v);

template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v);


#include "insertion_sort.tpp"
