#pragma once

#include <vector>
#include "insertion_sort.h" //used for median of medians
#include "merge_sort.h"
#include "partition.h"

template <typename T, typename KeyFunc>
T k_select(std::vector<T> list, int k, KeyFunc key);

template <typename T>
T k_select(std::vector<T> list, int k);

#include "k_select.tpp"

