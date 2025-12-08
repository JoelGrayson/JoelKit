#include "random.h"

// Initialization
Random::Random() {
    this->gen = std::mt19937(rd());
}

int Random::int_in_range(int a, int b) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(this->gen);
}

