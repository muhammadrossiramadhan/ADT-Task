#include <stdio.h>
#include "array.h"
#include "linked_list.h"

int main() {
    struct node* head = NULL;
    DynamicArray arr;
    initArray(&arr,5);
    addArray(&arr,1);
    addArray(&arr,2);
    addArray(&arr,3);
    addArray(&arr,4);
    addArray(&arr,5);
    iterateArray(&arr);

    return 0;
}
