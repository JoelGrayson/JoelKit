#pragma once

#include <vector>

/** @returns the new index of the pivot */
template <typename T>
int partition(std::vector<T>& lst, int start_i, int end_i, int pivot_i);

#include "partition.tpp"

