#pragma once

#include <random>

class Random {
    std::random_device rd;
    std::mt19937 gen;

    Random();
    
    /** @returns an integer in [a, b) */
    int int_in_range(int a, int b);
}

