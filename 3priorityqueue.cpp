//It is used for implementing minheap based priority queue

#include "3priorityqueue.h"  //includes the header file

// It initializes an empty priority queue by setting the initial heap size to 0
PriorityQueue::PriorityQueue() {
    size = 0;
}

// insertion of a new node
void PriorityQueue::insert(int vertex, int key) {
    heap[size].vertex = vertex; //adding the vertex to the next available position in the array
    heap[size].key = key;
    size++;
    heapifyUp(size - 1);  //adjusting the position of the heap to maintain heap property
}

// checks if heap is empty
bool PriorityQueue::isEmpty() {
    return size == 0;
}

// it searches for a given vertex in a heap
int PriorityQueue::findPosition(int vertex) {
    for (int i = 0; i < size; i++)
        if (heap[i].vertex == vertex)
            return i;
    return -1;
}

// it is a decrease key function
void PriorityQueue::decreaseKey(int vertex, int newKey) {
    int pos = findPosition(vertex);
    if (pos == -1) return;
    if (newKey >= heap[pos].key) return;
    heap[pos].key = newKey;
    heapifyUp(pos);
}

// it is an extract min function
PQNode PriorityQueue::extractMin() {
    PQNode minNode = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return minNode;
}

//restores the min heap property
void PriorityQueue::heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].key <= heap[i].key) break;
        PQNode temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}

//restores the min heap property
void PriorityQueue::heapifyDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].key < heap[smallest].key)
            smallest = left;
        if (right < size && heap[right].key < heap[smallest].key)
            smallest = right;

        if (smallest != i) {
            PQNode temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
}
