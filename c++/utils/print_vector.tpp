#include <vector>

template <typename T>
void print_vector(std::vector<T> v, const char* end) {
    std::cout << "[";
    for (int i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1]; //last element has no comma after it
    std::cout << "]" << end;
}

