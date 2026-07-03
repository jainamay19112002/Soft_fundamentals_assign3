// This is the header file of the priority queue describing the features of it

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define MAX_NODES 50  //max nodes that a priority queue can store
#define INF 999999    //a large value for representing infinity

struct PQNode {
    int vertex;
    int key;
};

class PriorityQueue {
public:
    PQNode heap[MAX_NODES];
    int size;

    PriorityQueue(); 
    void insert(int vertex, int key);          //inserts a new node
    PQNode extractMin();                       //removes and returns node with min value
    void decreaseKey(int vertex, int newKey);  //decrease the key value of a given vertex
    bool isEmpty();                            //checks if priority queue is empty or not
    int findPosition(int vertex);              //finds the index of a vertex
    void heapifyUp(int i);                     //rearranges the heap
    void heapifyDown(int i);                   //rearranges the heap
};

#endif
