#include "array.h"

// ============================================================
// [ ARRAY ] - INIT / CREATE & ALLOCATE
// ============================================================
void initArray(DynamicArray *a, int cap) {
    // Di Array, ALLOCATE dilakukan sekali untuk satu blok besar
    a->data = (int *)malloc(cap * sizeof(int)); 
    a->size = 0;
    a->capacity = cap;
}

// ============================================================
// [ ARRAY ] - ITERATE
// ============================================================
void iterateArray(DynamicArray *a) {
    for(int i =0;i<a->size;i++){
        printf("elemen array : %d\n",a->data[i]);
    }
}

// ============================================================
// [ ARRAY ] - ISEMPTY
// ============================================================
bool isEmptyArray(DynamicArray *a) {
    return (a->size == 0);
}

// ============================================================
// [ ARRAY ] - ADD / INSERT
// ============================================================
void addArray(DynamicArray *a, int val) {
    if (a->size < a->capacity) {
        a->data[a->size] = val;
        a->size++;
    }
}

// ============================================================
// [ ARRAY ] - SEARCH
// ============================================================
int searchArray(DynamicArray *a, int target) {
    for (int i = 0; i < a->size; i++) {
        if (a->data[i] == target) return i;
    }
    return -1;
}

// ============================================================
// [ ARRAY ] - DEL / REMOVE
// ============================================================
void removeArray(DynamicArray *a, int index) {
    if (index >= 0 && index < a->size) {
        for (int i = index; i < a->size - 1; i++) {
            a->data[i] = a->data[i + 1];
        }
        a->size--;
    }
}

// ============================================================
// [ ARRAY ] - DESTROY & DEALLOCATE
// ============================================================
void destroyArray(DynamicArray *a) {
    // DEALLOCATE seluruh blok memori array
    if (a->data != NULL) {
        free(a->data); 
        a->data = NULL;
    }
    a->size = 0;
    a->capacity = 0;
}

// ============================================================
// [ ARRAY ] - LENGTH
// ============================================================
int lengthArray(DynamicArray *a) {
    return a->size;
}
