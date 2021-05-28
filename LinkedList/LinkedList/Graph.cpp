#include "Graph.h"
#include <iostream>
#include <queue>
/*
	Much like with level search, we'll use a queue to visit all adjacent
	nodes before moving on to next level.
*/
void Graph::BFS(int start) {
	int i = start, j;
	int visited[7] = { 0 };
	std::queue<int> q;
	std::cout << i << " "; // Print our head
	visited[i] = 1;
	q.push(i);

	while (q.size() > 0) {
		i = q.front(); q.pop(); // For every element in the queue:
		for (j = 1; j < sz; j++) {
			if (g[i][j] == 1 && visited[j] == 0) {
				std::cout << j << " "; // print its children and
				visited[j] = 1;
				q.push(j); // enqueue them if there's an edge and they aren't already visited.
			}
		}
	}
	
}

/*
	DFS is like preorder. It uses a stack to explore one end to its extreme before
	backtracking back to the most immediate parent and exploring the its other edges.
	Once all extremities of a node are explored it backtracks to the previous parent and does the same.
*/
void Graph::DFS(int start) {
	static int visited[7] = { 0 }; // Since we're using recursion, we'll need a static array.
	int j;

	if (visited[start] == 0) {
		std::cout << start << " "; // Head printed first
		visited[start] = 1;

		for (j = 1; j < sz; j++) // For each child of our head
			if (g[start][j] == 1 && visited[j] == 0) // where an edge exists
				DFS(j); // we dive to the end of that extreme.
	}
}
void Graph::runGraphs() {
	std::cout << "\nBFS starting at 4" << std::endl;
	BFS(4);

	std::cout << "\nDFS starting at 4" << std::endl;
	DFS(4);
}

