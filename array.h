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

// Daftar Fungsi (Prototipe)
void initArray(DynamicArray *a, int cap);
void iterateArray(DynamicArray *a);
bool isEmptyArray(DynamicArray *a);
void addArray(DynamicArray *a, int val);
int searchArray(DynamicArray *a, int target);
void removeArray(DynamicArray *a, int index);
void destroyArray(DynamicArray *a);
int lengthArray(DynamicArray *a);

#endif
