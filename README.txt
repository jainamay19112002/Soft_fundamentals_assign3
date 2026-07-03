IMPLEMENTED PRIMS AND KRUSKALS ALGORITHM
SOFTASSIGN3/

 here we have created separate modules for each
--- 1graph.h                                   → Graph Abstract Data Type implementation  
--- 2graph.cpp 
--- 3priorityqueue.h                           → Min-heap priority queue (with decrease-key) 
--- 3priorityqueue.cpp 
--- 4unionfind.h                               → Union–Find (Disjoint Set Union)  
--- 4unionfind.cpp 
--- 5prims.cpp                                 → Prim’s MST algorithm (uses Graph + Priority Queue)  
--- 6kruskals.cpp                              → Kruskal’s MST algorithm (uses Graph + Union-Find)  

here we have created 2 main files.....one for the input given in the assignment and one for the general test cases
--- 7main_giventestcase.cpp      → Runs on fixed 6×6 example (given in the assignment)  
--- 7maingeneral.cpp             → Reads any n×n matrix from text file  
--- graph.txt                    → Sample input matrix (10×10)

//------------------------------------------------------------------------------------------------------------------------------------

2. Compilation Commands

Open a terminal in the project folder and run:

A. for the given test case in the assignment
g++ 7main_giventestcase.cpp 2graph.cpp 3priorityqueue.cpp 4unionfind.cpp 5prims.cpp 6kruskals.cpp -o mst
./mst

B. for general test cases
g++ 7maingeneral.cpp 2graph.cpp 3priorityqueue.cpp 4unionfind.cpp 5prims.cpp 6kruskals.cpp -o mst
./mst

 //----------------------------------------------------------------------------------------------------------------------------------

 3. Runtime Measurement Details

Because Windows timers have ~15 ms resolution and MSTs on small graphs finish in microseconds,
each algorithm is executed 200 000 times inside a loop.
Total elapsed time is divided by the repeat count to get a visible, average per-execution runtime.

Average runtime (ms) = (GetTickCount_end − GetTickCount_start) / REPEAT
This method ensures accurate results without using restricted libraries like <chrono>.

//---------------------------------------------------------------------------------------------------------------------------------

4.Outputs  

this is the output for the given test case provided in the assignment(6x6 matrix)

Prim's algorithm MST (total cost: 15; avg runtime: 0.00031 ms)
(1,3)
(2,3)
(2,5)
(3,6)
(4,6)

Kruskal's algorithm MST (total cost: 15; avg runtime: 0.00039 ms)
(1,3)
(2,3)
(2,5)
(3,6)
(4,6)

//////////////////////////////////////////////////////////////////////////////

this is the output of the general test case....here we used a 10x10 matrix (we can use any other also)

Enter input file name: graph.txt
Prim's algorithm MST (total cost: 28; avg runtime: 0.000785 ms)
(1,2)
(2,3)
(3,4)
(4,5)
(5,7)
(6,7)
(7,8)
(8,10)
(9,10)

Kruskal's algorithm MST (total cost: 28; avg runtime: 0.00117 ms)
(1,2)
(2,3)
(3,4)
(4,5)
(5,7)
(6,7)
(7,8)
(8,10)
(9,10)


//------------------------------------------------------------------------------------------------------------------------------------
5.Notes

No STL containers (vector, sort, priority_queue) are used.
All data structures (Graph, Heap, Union-Find) are implemented from scratch.
Both programs produce the same MST cost for any connected graph.

