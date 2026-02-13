#include "stack.h"

void allocateStack(struct Stack *S) {
    S->top = NULL;
    S->curSize = 0;
    printf("[Sistem] Memori Stack berhasil dialokasikan (Inisialisasi).\n");
    printf("\n");
}


void print_nodes(struct Stack S) {
    if (S.top == NULL) {
        printf("Stack kosong, tidak ada yang bisa dicetak.\n");
        printf("\n");
        return;
    }

    struct NodeStack *ptr = S.top;
    
    printf("Isi Stack (Puncak ke Bawah): [");
    while(ptr != NULL) {
        printf("%d", ptr->value);
        
        if(ptr->next != NULL) {
            printf(", "); 
        }
        ptr = ptr->next;
    }
    printf("]\n");
    printf("\n");
}

bool isEmptyStack(struct Stack S) {
    if (S.top == NULL) {
        printf("[Info] Cek Stack: Status Kosong.\n");
        return true;
    }
    return false;
}

bool isFullStack(struct Stack S) {
    if(S.curSize == MAX_STACK) {
        printf("PERINGATAN : STACK SEKARANG PENUH\n");
        printf("\n");
        return true;
    }else{
        printf("MASIH AMAN \n");
        printf("\n");
        return false;
    }
}

void push(struct Stack *S, int element) {

    if (S->curSize == MAX_STACK) {
        printf("Stack Full! Gak bisa push %d\n", element);
        return;
    }

    struct NodeStack *newElement = malloc(sizeof(struct NodeStack));

    newElement->value = element;
    
    newElement->next = S->top;

    S->top = newElement;
    
    S->curSize++;
  
    printf("Push: %d berhasil\n", element);
}

int pop(struct Stack *S) {
    
    if (isEmptyStack(*S)) return -1;
    
    struct NodeStack *current_top = S->top;
    
    int element = current_top->value; 
    
    printf("Pop: %d berhasil\n", element);
    
    S->top = current_top->next;
    
    free(current_top);
    
    S->curSize--;
    

    return element;
}

int top(struct Stack S) {
    if (isEmptyStack(S)) return -1;
    printf("nilai top saat inI : %d\n\n",S.top->value);
    return S.top->value;
}

void deallocateStack(struct Stack *S) {
    printf("Proses pembebasan memori : \n");
    printf("\n");
    while (S->top != NULL) {
        pop(S);
    }
    printf("Memory Stack didealoakasi.\n");
}