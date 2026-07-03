#include "1graph.h"
#include <iostream>

// initialising the graph with the given number of vertices
Graph::Graph(int vertices) {
    V = vertices;                //storing the total no. of vertices
    edgeCount = 0;               //current edge count
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = -1; // -1 means no edge
}

// adding an undirected edge between two vertices
void Graph::addEdge(int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w;
}

//build the list of edges from adjacency matrix representation
void Graph::buildEdgeList() {
    edgeCount = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j] > 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = adj[i][j];
                edgeCount++;
            }
        }
    }
}

//displays the matrix representation of the graph 
void Graph::display() {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            std::cout << adj[i][j] << " ";
        std::cout << "\n";
    }
}
