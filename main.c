#include <stdio.h>
#include "tries.h"

int main() {
    TrieNode* pohon_kata = buat_trie();

    // Input data
    masukkan_kata(&pohon_kata, "ikan");
    masukkan_kata(&pohon_kata, "ikanhias");

    // Test Pencarian
    printf("Cari 'ikan': %s\n", cari_kata(pohon_kata, "ikan") ? "Ada" : "Tidak Ada");
    printf("Cari 'ika': %s\n", cari_kata(pohon_kata, "ika") ? "Ada" : "Tidak Ada");

    // Hapus data
    pohon_kata = hapus_kata(pohon_kata, "ikan", 0);
    printf("Cari 'ikan' setelah dihapus: %s\n", cari_kata(pohon_kata, "ikan") ? "Ada" : "Tidak Ada");
    printf("Cari 'ikanhias': %s\n", cari_kata(pohon_kata, "ikanhias") ? "Ada" : "Tidak Ada");

    // Bersihkan memori total
    hancurkan_trie(pohon_kata);
    pohon_kata = NULL;

    return 0;
}