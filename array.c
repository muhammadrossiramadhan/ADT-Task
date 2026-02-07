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

// ------------------------------------------------------------
// SEPARATOR: LINKED LIST IMPLEMENTATION
// ------------------------------------------------------------

// ============================================================
// [ LIST ] - INIT / CREATE
// ============================================================
void initList(Node **head) {
    *head = NULL;
}

// ============================================================
// [ LIST ] - ISEMPTY
// ============================================================
bool isEmptyList(Node *head) {
    return (head == NULL);
}

// ============================================================
// [ LIST ] - ALLOCATE
// ============================================================
Node* allocateNode(int val) {
    // ALLOCATE satu per satu per node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = val;
        newNode->next = NULL;
    }
    return newNode;
}

// ============================================================
// [ LIST ] - DEALLOCATE
// ============================================================
void deallocateNode(Node *node) {
    free(node);
}

// ============================================================
// [ LIST ] - ADD / INSERT
// ============================================================
void addList(Node **head, int val) {
    Node *newNode = allocateNode(val); // Memanggil Allocate
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

// ============================================================
// [ LIST ] - SEARCH
// ============================================================
Node* searchList(Node *head, int target) {
    Node *curr = head;
    while (curr != NULL) {
        if (curr->value == target) return curr;
        curr = curr->next;
    }
    return NULL;
}

// ============================================================
// [ LIST ] - DEL / REMOVE
// ============================================================
void removeList(Node **head, int target) {
    Node *curr = *head;
    Node *prev = NULL;
    while (curr != NULL && curr->value != target) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) *head = curr->next;
        else prev->next = curr->next;
        deallocateNode(curr); // Memanggil Deallocate
    }
}

// ============================================================
// [ LIST ] - DESTROY
// ============================================================
void destroyList(Node **head) {
    Node *curr = *head;
    Node *nextN;
    while (curr != NULL) {
        nextN = curr->next;
        deallocateNode(curr); // Memanggil Deallocate berulang kali
        curr = nextN;
    }
    *head = NULL;
}

// ============================================================
// [ LIST ] - LENGTH
// ============================================================
int lengthList(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}