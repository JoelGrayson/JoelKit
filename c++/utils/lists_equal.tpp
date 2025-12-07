#include "lists_equal.h"

template <typename T>
bool lists_equal(std::vector<T> l1, std::vector<T> l2) {
    if (l1.size() != l2.size()) //different size is not the same
        return false;

    for (int i = 0; i < l1.size(); i++)
        if (l1[i] != l2[i])
            return false;
    
    return true;
}

