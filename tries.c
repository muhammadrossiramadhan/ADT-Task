#include <stdlib.h>
#include <string.h>
#include "tries.h"

// Fungsi Internal (Private) untuk alokasi memori
static TrieNode* _alokasi_node_baru() {
    TrieNode* node_baru = (TrieNode*)malloc(sizeof(TrieNode));
    if (node_baru) {
        node_baru->akhir_kata = false;
        for (int i = 0; i < JUMLAH_ALFABET; i++) {
            node_baru->huruf_anak[i] = NULL;
        }
    }
    return node_baru;
}

TrieNode* buat_trie() {
    return _alokasi_node_baru();
}

void masukkan_kata(TrieNode** akar, char* kata_baru) {
    if (*akar == NULL) {
        *akar = _alokasi_node_baru();
    }

    TrieNode* penelusur = *akar;
    for (int i = 0; kata_baru[i] != '\0'; i++) {
        int indeks = kata_baru[i] - 'a';
        if (penelusur->huruf_anak[indeks] == NULL) {
            penelusur->huruf_anak[indeks] = _alokasi_node_baru();
        }
        // Pindah ke laci huruf selanjutnya
        penelusur = penelusur->huruf_anak[indeks];
    }
    penelusur->akhir_kata = true;
}

bool cari_kata(TrieNode* akar, char* kata) {
    if (akar == NULL) return false;

    TrieNode* penelusur = akar;
    for (int i = 0; kata[i] != '\0'; i++) {
        int indeks = kata[i] - 'a';
        if (penelusur->huruf_anak[indeks] == NULL) {
            return false; // Jalur buntu
        }
        penelusur = penelusur->huruf_anak[indeks];
    }
    return penelusur->akhir_kata;
}

static bool _punya_anak(TrieNode* node) {
    for (int i = 0; i < JUMLAH_ALFABET; i++) {
        if (node->huruf_anak[i] != NULL) return true;
    }
    return false;
}

TrieNode* hapus_kata(TrieNode* akar, char* kata, int kedalaman) {
    if (akar == NULL) return NULL;

    if (kedalaman == strlen(kata)) {
        if (akar->akhir_kata) akar->akhir_kata = false;
        if (!_punya_anak(akar)) {
            free(akar);
            akar = NULL;
        }
        return akar;
    }

    int indeks = kata[kedalaman] - 'a';
    akar->huruf_anak[indeks] = hapus_kata(akar->huruf_anak[indeks], kata, kedalaman + 1);

    if (!_punya_anak(akar) && akar->akhir_kata == false) {
        free(akar);
        akar = NULL;
    }
    return akar;
}

void hancurkan_trie(TrieNode* akar) {
    if (akar == NULL) return;
    for (int i = 0; i < JUMLAH_ALFABET; i++) {
        hancurkan_trie(akar->huruf_anak[i]);
    }
    free(akar);
}