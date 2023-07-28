# CppProgram
The provided C++ code implements an algorithm to find the number of strongly connected components (SCCs) in a directed graph using Depth-First Search (DFS). It first finds the topological order of the graph by performing DFS, then reverses the edges to create a new graph. The code then performs DFS on the reversed graph to count the SCCs. The main function creates a sample graph and outputs the count of SCCs.
The time complexity of the program is O(V + E) since the steps involved are performed linearly in the number of vertices and edges in the graph. 
