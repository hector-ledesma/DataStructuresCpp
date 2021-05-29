#pragma once
#define I 32767

#define V 7 // # of vertices in Kruskal Graph
#define E 9 // # of edges in Kruskal Graph
class Graph {
private:
    // Undirected Graph
	int g[7][7] = { {0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0} };
    const int sz = 7;
    void BFS(int start);
    void DFS(int start);
    // Weighted Graph for Prim's algorithm
    int wg[8][8]{
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
    void PrimMST();
    void printST(int st[][8-2]);

    int edg[3][9] = { { 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18} };
    void Union(int u, int v, int s[]);
    int Find(int u, int s[]);
    void KruskalsMCST();
    void printKruskal(int A[][9]);
public:
    void runGraphs();
};

