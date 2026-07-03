// This is the header file of the unionfind module describing the features of it

#ifndef UNIONFIND_H
#define UNIONFIND_H

#define MAX_ELEMENTS 50   // max elements that can be managed by the union find structure

class UnionFind {
public:
    int parent[MAX_ELEMENTS];
    int rank[MAX_ELEMENTS];
    int n;

    UnionFind(int n);           //Initializes the Union-Find structure with `n` elements
    int find(int x);            // Finds the representative of the set containing element x
    void unite(int x, int y);   // merges (unites) the sets containing elements x and y
};

#endif
