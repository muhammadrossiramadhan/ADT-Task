#ifndef TRIES_H
#define TRIES_H

#include <stdbool.h>

#define JUMLAH_ALFABET 26

typedef struct TrieNode {
    struct TrieNode* huruf_anak[JUMLAH_ALFABET];
    bool akhir_kata;
} TrieNode;

// Fungsi Public yang bisa dipanggil di main.c
TrieNode* buat_trie();
void masukkan_kata(TrieNode** akar, char* kata_baru);
bool cari_kata(TrieNode* akar, char* kata);
TrieNode* hapus_kata(TrieNode* akar, char* kata, int kedalaman);
void hancurkan_trie(TrieNode* akar);

#endif