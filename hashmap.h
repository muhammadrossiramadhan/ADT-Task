#ifndef HASHMAP_H
#define HASHMAP_H

#define SIZE 10

// Definisi struktur node untuk linked list dalam bucket
struct hash_node {
    int key;                  // Kunci unik
    char value[100];          // Data yang disimpan
    struct hash_node* next;   // Pointer ke node selanjutnya (Chaining)
};

// Prototype fungsi agar bisa dikenali di file lain
int hash_function(int key);
struct hash_node* create_node(int key, char value[100]);
void insert(struct hash_node* hash_table[], int key, char value[100]);
void delete_node(struct hash_node* hash_table[], int key);
void search(struct hash_node* hash_table[], int key);
void display(struct hash_node* hash_table[]);
void destroy_table(struct hash_node* hash_table[]); // Fungsi baru

#endif