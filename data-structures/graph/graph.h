#include "linked-list/linked-list.h"

// ABOUT: Adjacency list implementation of a graph

struct Vertex;
struct Edge;

struct Graph {
    Node<Edge>* edges;
    Node<Vertex>* V;
};

struct Vertex {
    int value;
    Node<Edge>* edges;
};

struct Edge {
    Vertex* a;
    Vertex* b;
};

