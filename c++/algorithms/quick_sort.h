#pragma once

#include <vector>
#include "partition.h"

template <typename T>
std::vector<T> quick_sorted(const std::vector<T>& lst);


template <typename T>
void quick_sort(std::vector<T>& lst);


#include "quick_sort.tpp"

