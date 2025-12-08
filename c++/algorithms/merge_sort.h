#pragma once

#include <vector>

template <typename T>
std::vector<T> merge_sorted(const std::vector<T>& l);


template <typename T>
void merge_sort(std::vector<T>& l);


template <typename T>
std::vector<T> merge(const std::vector<T>& l1, const std::vector<T>& l2);


#include "merge_sort.tpp"

