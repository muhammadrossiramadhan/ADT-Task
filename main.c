#include <stdio.h>
#include "linked_list.h"
#include "array.h"

int main() {

    // ============================================================
    // PENGUJIAN ADT ARRAY DINAMIS || ROSSI
    // ============================================================
    printf("\n--- ADT ARRAY DINAMIS ---\n");
    DynamicArray arr;
    
    initArray(&arr, 5); // Init + Allocate blok besar
    printf("Apakah array kosong? %s\n", isEmptyArray(&arr) ? "Ya" : "Tidak");

    addArray(&arr, 10);
    addArray(&arr, 20);
    addArray(&arr, 30);
    
    printf("Isi Array (Indeks 0): %d\n", arr.data[0]);
    printf("Panjang Array: %d\n", lengthArray(&arr));
    
    int idx = searchArray(&arr, 20);
    printf("Cari angka 20, ditemukan di indeks: %d\n", idx);
    
    removeArray(&arr, 1); // Menghapus angka 20 (indeks 1)
    printf("Panjang Array setelah remove: %d\n", lengthArray(&arr));
    
    destroyArray(&arr); // Destroy + Deallocate
    printf("Array berhasil dihancurkan.\n");


    // ============================================================
    // PENGUJIAN ADT LINKED LIST || DAVAR
    // ============================================================

    printf("\n--- ADT LINKED LIST  ---\n");

    struct node* head = NULL;

    return 0;
}
