#include <stdio.h>
#include "hashmap.h"

int main() {
    struct hash_node* hash_table[SIZE];

    // Mengosongkan semua tempat agar tidak berisi alamat memori "sampah"
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = NULL;
    }

    // Input data sampel
    insert(hash_table, 1, "Budi");
    insert(hash_table, 11, "Andi");
    insert(hash_table, 2, "Cici");
    
    display(hash_table);
    search(hash_table,3);

    // --- PROSES PEMBERSIHAN ---
    // Panggil fungsi destroy sebelum program berakhir
    destroy_table(hash_table);

    return 0;
}