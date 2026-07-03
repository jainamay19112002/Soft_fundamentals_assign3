#include "4unionfind.h"   //includes header file

//initializes the Union-Find structure
//each element is initially its own parent
//the rank array is used to keep tree height minimal during union operations
UnionFind::UnionFind(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

//finds the root of the set containing element x
int UnionFind::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

//merges the sets containing elements x and y
void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    // if this is already in the same set, then we do not need to merge
    if (rootX == rootY) return;

    // attaches the smaller rank tree under the root of the higher rank tree
    if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
