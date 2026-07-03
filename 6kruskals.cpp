//including the header files
#include "1graph.h"
#include "4unionfind.h"
#include <iostream>

// here we are using bubble sort to sort an array of edge objects by their weight in ascending order.
void sortEdges(Edge arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                Edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Graph kruskalMST(Graph &g, int &totalCost) {
    //building the edge list from adjacency matrix of input graph
    g.buildEdgeList();

    sortEdges(g.edges, g.edgeCount);

    //initializing union-find for all vertices
    UnionFind uf(g.V);
    Graph mst(g.V);
    totalCost = 0;

    // Iterating through all edges in ascending order
    for (int i = 0; i < g.edgeCount; i++) {
        Edge e = g.edges[i];
        int setU = uf.find(e.u);
        int setV = uf.find(e.v);
        if (setU != setV) {
            mst.addEdge(e.u, e.v, e.weight);
            uf.unite(setU, setV);
            totalCost += e.weight;
        }
    }
    return mst;
}
