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

void Graph::PrimMST() {
	int u, v; // These will simply serve as our indices for our edges. u and v are the vertices.
	int min{ I };
	int track[8]; // This is where we keep trck of visited vertices, as well as nearest edge.
	int T[2][8 - 2]{ 0 }; // Technically I can just write 6, but I wanna keep clear that 8 simply represents size.
	// The reason for -2 is that spanning trees have 1 less edge than there are vertices.
	// But we're holding one extra space in the array so that we may index by value
	// so -1 to subtract the extra index and -1 again for the spanning tree condition.
	// 7 vertices, 6 edges.

	// First step: Find cheapest edge by visiting all points int he matric on the top half.
	for (int i{ 1 }; i < 8; i++) {
		track[i] = I;
		for (int j{ i }; j < 8; j++) {
			if (wg[i][j] < min) { // Whenever we find a lower cost edge.
				min = wg[i][j]; // Save how much it cost.
				// Save the edge by storing both vertices.
				u = i; 
				v = j;
			}
		}
	}
	// We're saving our edges vertically
	// So the second index T[][x] is an edge
	// and the first index simply lets is mark origin and destination T[x][]
	T[0][0] = u;
	T[1][0] = v;
	// Now we need to mark both these vertices as visited by marking them as 0
	track[u] = track[v] = 0;

	// Now we need to find the initial cost comparisons using our first 2 vertices
	for (int i{ 1 }; i < 8; i++) {
		if (track[i] != 0) { // If this index is 0 we skip it
			// So we're using our index as our vertex as well.
			// we compare the cost of the edge between our index and vertex u
			// as well as the cost from i to v
			if (wg[i][u] < wg[i][v]) track[i] = u; // if u is lower, we store u itself to indicate that the combination of
			// wg[i]wg[track[i]] where track[i] is the vertex stored at that value, is our lower cost edge
			else track[i] = v; // if v is larger or equals, we save v since it doesn't matter.
		}
	}

	// Now comes the repeating process
	// We start at 1 because we handled index 0 at the initial setup
	for (int i{ 1 }; i < 8 - 2; i++) { // Spanning trees have one less edge than there are vertices. So we want to go from 1 to 5 because we have 7 vertices.
		int k;
		min = I;
		// Now we need to find the min cost edge from all the edges we last found.
		// since we've stored them in track, we can just use the index as one of our vertices, and stored value as the other.
		for (int j{ 1 }; j < 8; j++) {
			if (track[j] != 0 && wg[j][track[j]] < min) { // If our stored value is 0, then we already this index stored
				// Once we find the smallest value edge
				k = j; // we store the index at which we found it for later use.
				min = wg[j][track[j]]; // and we store the cost of the edge
			}
		}

		// Each index i represents the edge for our spanning tree.
		T[0][i] = k; // At this index, the "u" vertex is the index at which we had just found the smallest cost edge.
		T[1][i] = track[k]; // "v" vertex is the value stored at that index making our pair.
		track[k] = 0; // mark this index as visited.

		// Now we need to find which are our smallest cost edges.
		//	Either the edges we had already found, or the ones that our newest vertex connects to
		for (int j{ 1 }; j < 8; j++) {
			if (track[j] != 0 ) { // If it's not an already added/visited vertex
				// This could be stored in the if statement, but I wanted to separate it for legibility.
				int ne = wg[j][k]; // This is the new edge. j as our index as well as vertex, and k as our newest added vertex
				int oe = wg[j][track[j]]; // This is the old edge, which we simply have stored at j itself and value at j
				// If our new edge is of less cost than our previously found edge, we're gonna want this new edge
				if (ne < oe) track[j] = k; // So we store the new vertex as value. So now our pair will be index j plus stored k value.
			}

		}
	}
		printST(T);
}
void Graph::printST(int st[][8 - 2]) {
	std::cout << "\nMinimum Spanning Tree Edges (w/ cost)" << std::endl;
	int sum{ 0 };
	for (int i{ 0 }; i < 8 - 2; i++) {
		int u = st[0][i];
		int v = st[1][i];
		int cost = wg[u][v];
		std::cout << "[" << u << "]--[" << v << "] cost: " << cost << std::endl;
		sum += cost;
	}
	std::cout << std::endl;
	std::cout << "Total cost of Minimum Cost Spanning Tree: " << sum << std::endl;
}

void Graph::Union(int u, int v, int s[]) {
	if (s[u] < s[v]) {
		s[u] += s[v];
		s[v] = u;
	}
	else {
		s[v] += s[u];
		s[u] = v;
	}
}

int Graph::Find(int u, int s[]) {
	int x = u;
	int v = 0;

	while (s[x] > 0) {
		x = s[x];
	}

	while (u != x) {
		v = s[u];
		s[u] = x;
		u = v;
	}

	return x;
}

void Graph::KruskalsMCST() {
	int T[2][V - 1]; // Solution array
	int track[E]{ 0 }; // Track edges that are included in solution
	int set[V + 1] = {-1,-1,-1,-1,-1,-1,-1}; // Array for finding cycle

	int i{ 0 };
	while (i < V - 1) {
		int min = I;
		int u{ 0 };
		int v{ 0 };
		int k{ 0 };

		// Find minimum cost edge
		for (int j{ 0 }; j < E; j++) {
			if (track[j] == 0 && edg[2][j] < min) {
				min = edg[2][j];
				u = edg[0][j];
				v = edg[1][j];
				k = j;
			}
		}

		// Check if the selected min cost edge (u, v) forms a cycle
		if (Find(u, set) != Find(v, set)) {
			T[0][i] = u;
			T[1][i] = v;

			// Perform union
			Union(Find(u, set), Find(v, set), set);
			i++;
		}
		track[k] = 1;
	}

	printKruskal(edg);
}

void Graph::printKruskal(int A[][E]) {
	std::cout << "\nMinimum Cost Spanning Tree Edges\n" << std::endl;
	for (int i{ 0 }; i < V - 1; i++) {
		std::cout << "[" << edg[0][i] << "]-----[" << edg[1][i] << "]" << std::endl;
	}
	std::cout << std::endl;
}

void Graph::runGraphs() {
	std::cout << "\nBFS starting at 4" << std::endl;
	BFS(4);

	std::cout << "\nDFS starting at 4" << std::endl;
	DFS(4);

	PrimMST();
	KruskalsMCST();
}

