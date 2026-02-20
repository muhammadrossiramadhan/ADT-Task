#include <stdio.h>
#include "graph.h"

int main() {
    // 1. Inisialisasi: Membuat struktur Graph [cite: 13, 14]
    Graph* myGraph = CreateGraph(5);

    // 2. Manipulasi: Menambahkan tali/relasi (Arc) antar data [cite: 5, 6]
    AddEdge(myGraph, 0, 1);
    AddEdge(myGraph, 0, 4);
    AddEdge(myGraph, 1, 2);
    AddEdge(myGraph, 1, 3);
    AddEdge(myGraph, 3, 4);

    // 3. Informasi: Menampilkan ringkasan status Graph
    printf("\nTotal Simpul (Vertex): %d\n", VertexCount(myGraph));
    printf("Total Tali (Edge/Arc): %d\n", EdgeCount(myGraph));

    // 4. Cek Relasi: Membuktikan ketetanggaan (Adjacency) [cite: 11]
    PrintIsAdjacent(myGraph, 0, 1);

    // 5. Visualisasi: Menampilkan Matrix & List secara detail [cite: 11]
    DisplayGraph(myGraph);
    
    // 6. Penelusuran: Menjalankan algoritma BFS & DFS [cite: 12]
    BFS(myGraph, 0);
    DFS(myGraph, 0);

    // 7. Cleanup: Menghapus Vertex 4 dan menghancurkan Graph [cite: 16]
    DeleteVertex(myGraph, 4);
    DestroyGraph(myGraph);

    return 0;
}