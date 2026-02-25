#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Struktur utama pohon. Tanpa typedef, panggil dengan 'struct Node'
struct Node {
    int value;           // Data yang disimpan
    struct Node* left;   // Pointer ke anak kiri
    struct Node* right;  // Pointer ke anak kanan
    int height;          // Level ketinggian node (penting untuk AVL)
};


struct Node* createNode(int value);
struct Node* search(struct Node* root, int key);

// Logika BST / NO AVL
struct Node* insertBST(struct Node* node, int value);
struct Node* deleteBST(struct Node* root, int key);

// Logika AVL 
struct Node* insertAVL(struct Node* node, int value);
struct Node* deleteAVL(struct Node* root, int key);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
void inOrder(struct Node* root);
void displayAVL(struct Node* root, char* prefix, bool isLeft);

int getHeight(struct Node* n);
int max(int a, int b);
int getBalance(struct Node* n);

#endif