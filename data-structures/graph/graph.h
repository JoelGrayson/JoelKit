#pragma once

#include "../linked-list/linked-list.h"

// ABOUT: Adjacency list implementation of a graph

template <typename T>
struct Vertex;

template <typename T>
struct Edge;

template <typename T>
struct Graph {
    Node<Vertex<T>>* V; //vertices
    Node<Edge<T>>* E; //edges

    Graph(): V(nullptr), E(nullptr) {}
};

template <typename T>
struct Vertex {
    T value;
    Node<Edge<T>>* edges;

    Vertex(const T& val): value(val), edges(nullptr) {}
};

// Depends on interpretation
// If directed, a → b
template <typename T>
struct Edge {
    Vertex<T>* a;
    Vertex<T>* b;

    Edge(): a(nullptr), b(nullptr) {}
    Edge(Vertex<T>* a_, Vertex<T>* b_): a(a_), b(b_) {}
};

