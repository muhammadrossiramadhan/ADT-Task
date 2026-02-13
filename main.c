#include "stack.h"
#include "queue.h"

int main() {
    // ==========================================
    // KELOMPOK IMPLEMENTASI STACK (LIFO)
    // ==========================================
    struct Stack S;
    printf("\n=== PENGUJIAN ADT STACK ===\n");
    allocateStack(&S);
    isEmptyStack(S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);
    push(&S, 50);

    isFullStack(S);
    print_nodes(S); 

    top(S);

    pop(&S);
    pop(&S);

    isFullStack(S);
    print_nodes(S); 

    top(S);

    deallocateStack(&S);
    isEmptyStack(S);

    // ==========================================
    // KELOMPOK IMPLEMENTASI QUEUE (FIFO)
    // ==========================================
    struct Queue Q;
    printf("\n\n=== PENGUJIAN ADT QUEUE ===\n");
    allocateQueue(&Q);
    isEmpty(Q);

    enqueue(&Q, 100);
    enqueue(&Q, 200);
    enqueue(&Q, 300);
    enqueue(&Q, 400);
    enqueue(&Q, 500);

    isFull(Q);
    print_queue(Q); 
    head(Q);
    tail(Q);

    dequeue(&Q);
    isFull(Q);
    print_queue(Q); 


    deallocateQueue(&Q);
    isEmpty(Q);

    return 0;
}