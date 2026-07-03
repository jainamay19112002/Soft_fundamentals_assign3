// This is the header file of the graph describing the features of the graph

#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 50    //max vertices that this graph can have
#define MAX_EDGES 200      //max edges that this graph can have

struct Edge {
    int u, v;            // two vertices endpoint
    int weight;          // weight of an edge between two vertices
};

class Graph {
public:
    int V;                               // number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
    Edge edges[MAX_EDGES];               // an array to store all the edges
    int edgeCount;                       // current edge count

    Graph(int vertices);
    void addEdge(int u, int v, int w);    // adding an edge between two vertices u and v with weight w
    void buildEdgeList();                 //building the edge list
    void display();                       //displays the adjacency matrix
};

#endif
