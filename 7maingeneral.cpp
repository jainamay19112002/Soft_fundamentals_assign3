// this is the main file for general test cases...here we can use the user input
//there is a graph.txt file where we can enter the values for the matrix

#include "1graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>  // For getting the TickCount() timing
using namespace std;

// function declarations
Graph primMST(Graph &g, int &totalCost);
Graph kruskalMST(Graph &g, int &totalCost);

// printing the MST edges, cost, and average runtime
void printMST(const char *name, Graph &mst, int totalCost, double avgRuntime) {
    cout << name << " MST (total cost: " << totalCost << "; avg runtime: " << avgRuntime << " ms)\n";
    for (int i = 0; i < mst.V; i++) {
        for (int j = i + 1; j < mst.V; j++) {
            if (mst.adj[i][j] > 0)
                cout << "(" << i + 1 << "," << j + 1 << ")\n";
        }
    }
    cout << endl;
}

// reads graph from a text file (n x n matrix).............here we are giving an example of 10x10 matrix
Graph readGraphFromFile(const char *filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    int matrix[MAX_VERTICES][MAX_VERTICES];
    int n = 0;
    string line;

    while (getline(fin, line)) {
        if (line.empty() || line[0] == '/' || line[0] == '#')
            continue; // skipping the comment lines
        stringstream ss(line);
        int val, j = 0;
        while (ss >> val) {
            matrix[n][j++] = val;
        }
        n++;
    }

    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // only reading the upper triangle as it is undirected graph
            if (matrix[i][j] > 0)
                g.addEdge(i, j, matrix[i][j]);
        }
    }

    return g;
}


int main() {
    char filename[100];
    cout << "Enter input file name: ";    //reading from the input file provided for general test cases
    cin >> filename;

    Graph g = readGraphFromFile(filename);

    int primCost = 0, kruskalCost = 0;
    Graph mstPrim(g.V), mstKruskal(g.V);

    const int REPEAT = 200000;  // large repeat count for stable timing

    // Prims Algorithm Timing
    DWORD start = GetTickCount();
    for (int i = 0; i < REPEAT; i++) {
        int tmpCost;
        primMST(g, tmpCost);
    }
    DWORD end = GetTickCount();
    double primTime = (double)(end - start) / REPEAT;

    // Running once to get the MST output
    mstPrim = primMST(g, primCost);

    //------------------------------------------------------------------------------------------------------------------------------

    // Kruskals Algorithm Timing
    start = GetTickCount();
    for (int i = 0; i < REPEAT; i++) {
        int tmpCost;
        kruskalMST(g, tmpCost);
    }
    end = GetTickCount();
    double kruskalTime = (double)(end - start) / REPEAT;

    mstKruskal = kruskalMST(g, kruskalCost);

    // displaying the results for both prims and kruskals
    printMST("Prim's algorithm", mstPrim, primCost, primTime);
    printMST("Kruskal's algorithm", mstKruskal, kruskalCost, kruskalTime);

    return 0;
}
