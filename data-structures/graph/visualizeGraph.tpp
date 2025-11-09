#include "visualizeGraph.h"
#include <iostream>

template <typename T>
void visualizeGraph(Graph<T> G) {
    std::cout << "---Graph Visualization---" << std::endl;
    std::cout << "Vertices:" << std::endl;
    auto vHead = G.V;
    while (vHead != nullptr) {
        std::cout << vHead->value.value << std::endl;
        vHead = vHead->next;
    }

    std::cout << "Edges:" << std::endl;
    auto eHead = G.E;
    while (eHead != nullptr) {
        auto edge = eHead->value;
        std::cout << edge.a->value << " → " << edge.b->value << std::endl;
        
        eHead = eHead->next;
    }
}

