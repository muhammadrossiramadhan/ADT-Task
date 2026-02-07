#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definisi Struktur
typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Daftar Fungsi (Prototipe)
void initArray(DynamicArray *a, int cap);
bool isEmptyArray(DynamicArray *a);
void addArray(DynamicArray *a, int val);
int searchArray(DynamicArray *a, int target);
void removeArray(DynamicArray *a, int index);
void destroyArray(DynamicArray *a);
int lengthArray(DynamicArray *a);

void initList(Node **head);
bool isEmptyList(Node *head);
Node* allocateNode(int val);
void deallocateNode(Node *node);
void addList(Node **head, int val);
Node* searchList(Node *head, int target);
void removeList(Node **head, int target);
void destroyList(Node **head);
int lengthList(Node *head);

#endif