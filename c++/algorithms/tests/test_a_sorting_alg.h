#pragma once

#include "../../utils/lists_equal.h"
#include <assert.h>
#include <vector>
#include <functional>
#include <iostream>
#include <utility>

// In place
template <typename T>
void test_a_sorting_alg(std::function<void(std::vector<T>&)> sorting_fn);


// Return sorted copy
void test_a_sorting_alg(std::function<std::vector<int>(std::vector<int>)> sorting_fn);


#include "test_a_sorting_alg.tpp"

