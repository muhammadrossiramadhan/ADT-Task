#include "tree.h"
#include <stdbool.h>

int main() {
    struct Node* rootBST = NULL;
    struct Node* rootAVL = NULL;
    int data[] = {10, 20, 30, 40, 50}; // Data urut untuk pengujian kemiringan
    int n = sizeof(data) / sizeof(data[0]);

    for(int i = 0; i < n; i++) {
        rootBST = insertBST(rootBST, data[i]);
        rootAVL = insertAVL(rootAVL, data[i]);
    }

    printf("=== BEFORE: BST STANDAR (DATA URUT) ===\n");
    displayAVL(rootBST, "", false);
    printf("Keterangan: Terlihat miring ke kanan (seperti Linked List).\n\n");

    printf("=== AFTER: AVL TREE (DATA URUT) ===\n");
    displayAVL(rootAVL, "", false);
    printf("Keterangan: Terrotasi otomatis sehingga seimbang.\n\n");

    // Demo Search
    int key = 30;
    if(search(rootAVL, key)) printf("Search: Data %d Ditemukan!\n", key);
    displayAVL(rootAVL, "", false);

    // Demo Delete
    printf("\n=== SETELAH DELETE 30 (AVL) ===\n");
    rootAVL = deleteAVL(rootAVL, 30);
    displayAVL(rootAVL, "", false);

    return 0;
}