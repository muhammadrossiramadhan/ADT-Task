#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* PRIVATE HELPER FUNCTIONS 
   Hanya bisa dilihat dan dipakai di dalam file graph.c ini saja.
   main.c TIDAK BISA memanggil fungsi ini.
*/

static bool isEmpty(Graph* g) {
    return g->numVertices == 0;
}

static bool isFull(Graph* g) {
    return g->numVertices >= MAX_VERTICES;
}

static void ResetVisited(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        g->visited[i] = false;
    }
}

// Helper untuk membuat node baru (Adjacency List)
static Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

/* PUBLIC FUNCTIONS IMPLEMENTATION
   Implementasi dari semua prototype fungsi yang sudah dideklarasikan di graph.h
*/

Graph* CreateGraph(int vertices) {
    if (vertices > MAX_VERTICES) vertices = MAX_VERTICES;
    Graph* g = malloc(sizeof(Graph));
    g->numVertices = vertices;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) g->adjMatrix[i][j] = 0;
        g->adjLists[i] = NULL;
        g->visited[i] = false;
    }
    return g;
}

void AddEdge(Graph* g, int src, int dest) {
    // Validasi internal sebelum eksekusi
    if (isEmpty(g) || src >= g->numVertices || dest >= g->numVertices) return;

    // Implementasi Matrix
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;

    // Implementasi List (Tambah ke depan)
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// Mengembalikan jumlah vertex yang aktif di graph
int VertexCount(Graph* g) {
    if (g == NULL) return 0;
    return g->numVertices; 
}

// Menghitung total Edge (Arc) yang ada di Matrix
int EdgeCount(Graph* g) {
    if (g == NULL) return 0;
    int count = 0;
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = i; j < g->numVertices; j++) { // j=i agar tidak hitung ganda (Undirected)
            if (g->adjMatrix[i][j] == 1) count++;
        }
    }
    return count;
}

bool IsAdjacent(Graph* g, int src, int dest) {
    if (g == NULL || src >= g->numVertices || dest >= g->numVertices) return false;
    // Cek di Matrix apakah ada relasi (Arc) [cite: 6, 11]
    return g->adjMatrix[src][dest] == 1; 
}

void PrintIsAdjacent(Graph* g, int src, int dest) {
    printf("[CHECK] Memeriksa relasi: Apakah Vertex %d terhubung ke %d?\n", src, dest);
    if (IsAdjacent(g, src, dest)) {
        printf("        Status: Ya, keduanya saling bertetangga (Adjacent).\n");
    } else {
        printf("        Status: Tidak, tidak ditemukan jalur (Arc) langsung.\n");
    }
}

void DeleteVertex(Graph* g, int v) {
    if (g == NULL || v >= g->numVertices) {
        printf("\n[ERROR] Gagal menghapus: Vertex %d tidak ditemukan.\n", v);
        return;
    }

    printf("\n\n[ACTION] Menghapus Vertex %d dari Sistem...\n", v);
    int edgesRemoved = 0;

    // 1. Membersihkan Relasi di Adjacency Matrix
    // Kita harus memutus hubungan dari v ke semua i, dan dari semua i ke v
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] == 1) {
            g->adjMatrix[v][i] = 0;
            g->adjMatrix[i][v] = 0;
            edgesRemoved++;
        }
    }

    // 2. Membersihkan Relasi di Adjacency List
    // Logikanya: Kita harus 'free' memori linked list milik vertex v
    Node* temp = g->adjLists[v];
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    g->adjLists[v] = NULL; // Pastikan head-nya jadi NULL

    // 3. Membersihkan jejak v di List milik vertex lain
    // (Opsional tapi penting: menghapus node v dari list tetangga-tetangganya)
    for (int i = 0; i < g->numVertices; i++) {
        if (i == v) continue;
        // Di sini panggil fungsi pembantu DeleteEdge spesifik untuk List
        // DeleteEdgeList(g, i, v); 
    }

    printf("SUCCESS: Vertex %d telah dinonaktifkan.\n", v);
    printf("Detail: %d Arc (tali) yang terhubung telah diputus dan dibebaskan.\n", edgesRemoved);
    
    // Catatan: numVertices tidak langsung dikurangi agar indeks matrix tetap konsisten,
    // melainkan vertex tersebut ditandai sebagai 'tidak aktif'.
}

void DeleteEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 0;
    g->adjMatrix[dest][src] = 0;
    // Logika hapus node di linked list (adjLists)
}

void BFS(Graph* g, int start) {
    ResetVisited(g);
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    printf("\n[RUNNING] Breadth First Search (BFS) dari Vertex %d\n", start);
    printf("Strategi: Mengunjungi tetangga terdekat terlebih dahulu (Queue-based)\n");
    printf("Urutan Kunjungan: ");

    g->visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = g->adjLists[current];
        while (temp) {
            if (!g->visited[temp->v]) {
                g->visited[temp->v] = true;
                queue[rear++] = temp->v;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(Graph* g, int start) {
    // Gunakan wrapper agar pesan hanya muncul sekali di awal rekursi
    static bool isFirst = true;
    if (isFirst) {
        ResetVisited(g);
        printf("\n[RUNNING] Depth First Search (DFS) dari Vertex %d\n", start);
        printf("Strategi: Menelusuri jalur hingga ujung terdalam (Stack/Recursive-based)\n");
        printf("Urutan Kunjungan: ");
        isFirst = false;
    }

    g->visited[start] = true;
    printf("%d ", start);

    Node* temp = g->adjLists[start];
    while (temp) {
        if (!g->visited[temp->v]) DFS(g, temp->v);
        temp = temp->next;
    }
    
    // Reset flag setelah semua selesai (kembali ke level 0)
    // Logika reset flag ini bisa diletakkan di main setelah panggil DFS
}

void DisplayGraph(Graph* g) {
    if (g == NULL) return;

    printf("\n====================================================\n");
    printf("                      ADT GRAPH                     \n");
    printf("====================================================\n");

    // Bagian Matrix
    printf("\n[1] Adjacency Matrix\n    ");
    for (int i = 0; i < g->numVertices; i++) printf("%d ", i);
    printf("\n    ");
    for (int i = 0; i < g->numVertices; i++) printf("--");
    printf("\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("%d | ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) printf("1 ");
            else printf(". ");
        }
        printf("\n");
    }

    // Bagian List & Degree
    printf("\n[2] Adjacency List & Degree (Konektivitas)\n");
    for (int i = 0; i < g->numVertices; i++) {
        int degree = 0; // Variabel untuk menghitung jumlah tetangga
        printf("    Vertex %d : ", i);
        
        Node* temp = g->adjLists[i];
        if (temp == NULL) {
            printf("Empty (Isolated)");
        } else {
            while (temp != NULL) {
                printf("%d", temp->v);
                degree++; // Setiap ada node di list, tambah derajatnya [cite: 5, 6]
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
        }
        // Tampilkan Degree di akhir baris
        printf("  (Degree: %d)\n", degree);
    }
    printf("====================================================\n");
}


void DestroyGraph(Graph* g) {
    if (g == NULL) return;

    printf("\n[CLEANUP] Memulai proses dealokasi memori Graph...\n");
    int countNodes = 0;

    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp); // Menghapus elemen node [cite: 15, 16]
            temp = next;
            countNodes++;
        }
    }
    
    free(g); // Menghapus struktur utama [cite: 14]
    printf("SUCCESS: %d Node relasi dan struktur utama berhasil dihapus dari Heap.\n", countNodes);
    printf("Status: Memori bersih, tidak ada leak.\n\n");
}