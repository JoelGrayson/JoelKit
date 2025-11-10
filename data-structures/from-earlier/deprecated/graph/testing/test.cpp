#include <iostream>
#include "../../linked-list/linked-list.h"
#include "../graph.h"
#include "../visualizeGraph.h"

using T = const char*; //type of "a"

int main() {
    Vertex<T> a("a");
    Vertex<T> b("b");
    Vertex<T> c("c");
    Vertex<T> d("d");
    Vertex<T> e("e");
    Vertex<T> f("f");

    // V = a, b, c, d, e, f
    // E = ab, ac, bd, cd, de, df
    Graph<T> G;
    
    Node<Vertex<T>> vHead(a);
    G.V = &vHead;
    Node<Vertex<T>> llB(b);
    vHead.next = &llB;
    Node<Vertex<T>> llC(c);
    Node<Vertex<T>> llD(d);
    Node<Vertex<T>> llE(e);
    Node<Vertex<T>> llF(f);
    llB.next = &llC;
    llC.next = &llD;
    llD.next = &llE;
    llE.next = &llF;
    

    Edge<T> ab(&a, &b);
    Node<Edge<T>> eHead(ab);
    G.E = &eHead;

    Edge<T> ac(&a, &c);
    Node<Edge<T>> llAc(ac);
    eHead.next = &llAc;

    Edge<T> cd(&c, &d);
    Edge<T> bd(&b, &d);
    Edge<T> de(&d, &e);
    Edge<T> df(&d, &f);
    Node<Edge<T>> llCd(cd);
    Node<Edge<T>> llBd(bd);
    Node<Edge<T>> llDe(de);
    Node<Edge<T>> llDf(df);
    llAc.next = &llBd;
    llBd.next = &llCd;
    llCd.next = &llDe;
    llDe.next = &llDf;
    
    visualizeGraph(G);
    
    return 0;
}

