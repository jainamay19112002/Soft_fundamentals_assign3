// here we are including all the header modules
#include "1graph.h"
#include "3priorityqueue.h"
#include <iostream>

Graph primMST(Graph &g, int &totalCost) {
    int V = g.V;                        //total number of vertices
    bool inMST[MAX_VERTICES] = {false}; //tracks whether a vertex is included in MST
    int parent[MAX_VERTICES];           //Stores parent vertex for each node in MST
    
    //initializing all vertices as having no parent
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    PriorityQueue pq;
    pq.insert(0, 0);  // starting from vertex 0 with cost 0

    //initializing all other vertices with infinite key
    for (int i = 1; i < V; i++)
        pq.insert(i, INF);

    totalCost = 0;
    Graph mst(V);

    while (!pq.isEmpty()) {
        PQNode uNode = pq.extractMin();
        int u = uNode.vertex;
        inMST[u] = true;

        // if the vertex has a parent, add that edge to the MST
        if (parent[u] != -1) {
            mst.addEdge(parent[u], u, uNode.key);
            totalCost += uNode.key;
        }

        // for all vertices v adjacent to u, if v is not in MST
        // and the weight of edge (u, v) is smaller than its current key in PQ,
        // updating v's key and parent.
        for (int v = 0; v < V; v++) {
            int weight = g.adj[u][v];
            if (weight > 0 && !inMST[v]) {
                int pos = pq.findPosition(v);
                if (pos != -1 && weight < pq.heap[pos].key) {
                    parent[v] = u;
                    pq.decreaseKey(v, weight);
                }
            }
        }
    }
    return mst;
}
