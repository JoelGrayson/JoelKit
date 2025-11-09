#include <iostream>
#include "../linked-list/linked-list.h"
#include "graph.h"
#include "visualizeGraph.h"

using T = const char*; //type of "a"

int main() {
    Vertex<T> a("a");
    Vertex<T> b("b");
    Vertex<T> c("c");
    Vertex<T> d("d");
    Vertex<T> e("e");
    Vertex<T> f("f");

    Graph<T> G;
    
    Node<Vertex<T>> vHead(a);
    G.V = &vHead;
    Node<Vertex<T>> llB(b);
    vHead.next = &llB;

    Edge<T> ab(&a, &b);
    Node<Edge<T>> eHead(ab);
    G.E = &eHead;
    
    visualizeGraph(G);
    
    return 0;
}

