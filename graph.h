#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_VERTICES 10

// Struktur Node untuk Adjacency List
typedef struct Node {
    int v;
    struct Node* next;
} Node;

// Struktur Utama ADT Graph
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;

/* PROTOTIPE FUNGSI UNTUK main.c 
   (fungsi utama yang menggerakkan logika Graph)
*/

// Lifecycle
Graph* CreateGraph(int vertices);
void DestroyGraph(Graph* g);

// Operations
void AddVertex(Graph* g);
void DeleteVertex(Graph* g, int v);
void AddEdge(Graph* g, int src, int dest);
void DeleteEdge(Graph* g, int src, int dest);

// Information & Display
int VertexCount(Graph* g);
int EdgeCount(Graph* g);
bool IsAdjacent(Graph* g, int src, int dest);
void DisplayGraph(Graph* g);
void PrintIsAdjacent(Graph* g, int src, int dest);

// Traversal
void BFS(Graph* g, int startVertex);
void DFS(Graph* g, int startVertex);

#endif