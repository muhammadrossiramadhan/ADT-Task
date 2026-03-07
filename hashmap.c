#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Menghitung index menggunakan rumus modulo
int hash_function(int key) {
    return key % SIZE; // Sisa bagi key dengan ukuran table
}

// Alokasi memori untuk node baru di heap
struct hash_node* create_node(int key, char value[100]) {
    // Pesan memori sebesar struct hash_node
    struct hash_node* new_node = (struct hash_node*)malloc(sizeof(struct hash_node));
    new_node->key = key;              // Isi key
    strcpy(new_node->value, value);    // Copy string ke value
    new_node->next = NULL;             // Set pointer next ke NULL
    return new_node;                   // Kembalikan alamat node baru
}

// Memasukkan data ke table
void insert(struct hash_node* hash_table[], int key, char value[100]) {
    int index = hash_function(key);    // Cari index tujuan
    struct hash_node* new_node = create_node(key, value); // Buat nodenya

    // Head Insertion: Node baru menunjuk ke node yang sudah ada di index tersebut
    new_node->next = hash_table[index]; 
    // Index tersebut sekarang menunjuk ke node baru (jadi paling depan)
    hash_table[index] = new_node; 
}

// Fungsi Search: Mencari nilai berdasarkan key
void search(struct hash_node* hash_table[], int key) {
    // 1. Lompat ke index yang seharusnya
    int index = hash_function(key);
    
    // 2. Ambil kepala antrean di index tersebut
    struct hash_node* temp = hash_table[index];

    // 3. Mulai menelusuri antrean (Traversing)
    // Selama temp belum NULL (artinya belum sampai ujung)
    while (temp != NULL) {
        // Cek apakah key-nya cocok
        if (temp->key == key) {
            printf("Data Ketemu! Key: %d, Value: %s (Ada di Index %d)\n", temp->key, temp->value, index);
            return; // Langsung keluar fungsi karena sudah ketemu
        }
        // Jika belum cocok, geser ke node berikutnya
        temp = temp->next;
    }

    // 4. Jika loop selesai dan tidak ada yang cocok
    printf("Data dengan Key %d TIDAK ditemukan di Index %d.\n", key, index);
}

// Menghapus data berdasarkan key
void delete_node(struct hash_node* hash_table[], int key) {
    int index = hash_function(key);    // Cari di mana index-nya
    struct hash_node* temp = hash_table[index]; // Ambil node pertama di index itu
    struct hash_node* prev = NULL;     // Pointer bantuan untuk melacak node sebelumnya

    // Selama temp ada isinya DAN key-nya bukan yang kita cari, geser terus ke kanan
    while (temp != NULL && temp->key != key) {
        prev = temp;          // Simpan posisi sekarang sebagai 'sebelumnya'
        temp = temp->next;    // Loncat ke node berikutnya
    }

    // Jika sampai ujung linked list (NULL) tapi tidak ketemu
    if (temp == NULL) return; 

    // Jika yang mau dihapus adalah node paling depan (prev masih NULL)
    if (prev == NULL) {
        hash_table[index] = temp->next; // Geser head ke node setelahnya
    } else {
        // Jika di tengah/belakang, sambungkan node sebelumnya langsung ke cucunya
        prev->next = temp->next;
    }

    free(temp); // Bebaskan memori agar tidak bocor (memory leak)
}

// Menampilkan seluruh struktur hash table
void display(struct hash_node* hash_table[]) {
    for (int i = 0; i < SIZE; i++) {
        struct hash_node* temp = hash_table[i];
        printf("Index %d: ", i);
        while (temp) {
            printf("[%d: %s] -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Fungsi untuk menghapus seluruh isi table dan membebaskan memori
void destroy_table(struct hash_node* hash_table[]) {
    printf("\nCleaning up memory...\n");
    
    // 1. Loop melalui setiap bucket (index) di array
    for (int i = 0; i < SIZE; i++) {
        struct hash_node* temp = hash_table[i];
        
        // 2. Jika di index tersebut ada linked list, telusuri sampai habis
        while (temp != NULL) {
            // Simpan alamat node berikutnya sebelum node sekarang di-free
            struct hash_node* next_node = temp->next; 
            
            // Bebaskan memori node sekarang
            printf("Freeing key %d at index %d\n", temp->key, i);
            free(temp); 
            
            // Pindah ke node berikutnya yang sudah disimpan tadi
            temp = next_node;
        }
        
        // 3. Set index array kembali ke NULL setelah dibersihkan
        hash_table[i] = NULL;
    }
    printf("Memory cleanup finished.\n");
}