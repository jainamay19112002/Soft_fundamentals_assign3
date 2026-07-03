//the main file where all will get executed...here we are running the test cases provided in the assignment
#include "1graph.h"
#include <iostream>
#include <windows.h> // for getting the TickCount()....timing of the system

using namespace std;

// declaring the functions
Graph primMST(Graph &g, int &totalCost);
Graph kruskalMST(Graph &g, int &totalCost);

//printing the edges of the MST along with total cost and average runtime per iteration.
void printMST(const char *name, Graph &mst, int totalCost, double runtime) {
    cout << name << " MST (total cost: " << totalCost
         << "; avg runtime: " << runtime << " ms)\n";
    for (int i = 0; i < mst.V; i++)
        for (int j = i + 1; j < mst.V; j++)
            if (mst.adj[i][j] > 0)
                cout << "(" << i + 1 << "," << j + 1 << ")\n";
    cout << endl;
}

//main file
int main() {
    Graph g(6);  //graph with 6 vertex

    //adjacency matrix representation
    int mat[6][6]={    
        {0,6,1,5,-1,-1},
        {6,0,5,-1,3,-1},
        {1,5,0,5,6,4},
        {5,-1,5,0,-1,2},
        {-1,3,6,-1,0,6},
        {-1,-1,4,2,6,0}
    };

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (mat[i][j] > 0)
                g.addEdge(i, j, mat[i][j]);

    int primCost = 0, kruskalCost = 0;   //total cost of mst
    Graph mstPrim(6), mstKruskal(6);     //calling function call

    const int REPEAT = 200000;   // no. of times the algorithm is running for the timing

    //Prim’s Algorithm
    DWORD start = GetTickCount();
    for (int i = 0; i < REPEAT; i++) {
        int tempCost;
        primMST(g, tempCost);
    }
    DWORD end = GetTickCount();
    double primTime = (double)(end - start) / REPEAT;

    mstPrim = primMST(g, primCost);
//-----------------------------------------------------------------------------------------------------------------------

    // Kruskal’s Algorithm
    start = GetTickCount();
    for (int i = 0; i < REPEAT; i++) {
        int tempCost;
        kruskalMST(g, tempCost);
    }
    end = GetTickCount();
    double kruskalTime = (double)(end - start) / REPEAT;

    mstKruskal = kruskalMST(g, kruskalCost);

    //displaying the final results for both prims and kruskals
    printMST("Prim's algorithm", mstPrim, primCost, primTime);
    printMST("Kruskal's algorithm", mstKruskal, kruskalCost, kruskalTime);

    return 0;
}
