#include "adt.h"

int main() {
    // ============================================================
    // PENGUJIAN ADT ARRAY DINAMIS
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
    // PENGUJIAN ADT LINKED LIST
    // ============================================================
    printf("\n--- ADT LINKED LIST ---\n");
    Node *list;
    
    initList(&list);
    printf("Apakah list kosong? %s\n", isEmptyList(list) ? "Ya" : "Tidak");

    addList(&list, 100); // Di dalam add ada AllocateNode
    addList(&list, 200);
    addList(&list, 300);
    
    printf("Panjang List: %d\n", lengthList(list));
    
    Node* found = searchList(list, 200);
    if(found != NULL) printf("Cari angka 200: Ditemukan!\n");
    
    removeList(&list, 200); // Di dalam remove ada DeallocateNode
    printf("Panjang List setelah remove: %d\n", lengthList(list));
    
    destroyList(&list); // Membersihkan semua node sisa
    printf("Linked List berhasil dihancurkan.\n");

    return 0;
}