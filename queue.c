#include "queue.h"

void allocateQueue(struct Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
    Q->curSize = 0;
    printf("[Sistem] Memori Queue berhasil dialokasikan (Inisialisasi).\n\n");
}

bool isEmpty(struct Queue Q) {
    if (Q.head == NULL) {
        printf("[Info] Cek Queue: Status Kosong.\n\n");
        return true;
    }
    return false;
}

bool isFull(struct Queue Q) {
    if (Q.curSize == MAX_QUEUE) {
        printf("\nPERINGATAN : QUEUE SEKARANG PENUH\n\n");
        return true;
    } else {
        printf("\nMASIH AMAN \n\n");
        return false;
    }
}

void enqueue(struct Queue *Q, int element) {
    if (Q->curSize == MAX_QUEUE) {
        printf("Queue Full!\n");
        return;
    }
    struct NodeQueue *newElement = malloc(sizeof(struct NodeQueue));
    newElement->value = element;
    newElement->next = NULL;

    if (Q->head == NULL) {
        Q->head = newElement;
    } else {
        Q->tail->next = newElement; 
    }
    Q->tail = newElement; 
    Q->curSize++;
    printf("Enqueue: %d berhasil\n", element);
}

int dequeue(struct Queue *Q) {
    if (Q->head == NULL) return -1;
    struct NodeQueue *curhead = Q->head;
    int element = curhead->value;

    Q->head = curhead->next;
    if (Q->head == NULL) Q->tail = NULL;

    curhead->next = NULL; 
    free(curhead);
    Q->curSize--;
    printf("Dequeue: %d berhasil\n", element);
    return element;
}

int head(struct Queue Q) {
    if (Q.head == NULL) return -1;
    printf("nilai head saat inI : %d\n", Q.head->value);
    return Q.head->value;
}

int tail(struct Queue Q) {
    if (Q.tail == NULL) return -1;
    printf("nilai tail saat inI : %d\n\n", Q.tail->value);
    return Q.tail->value;
}

void print_queue(struct Queue Q) {
    struct NodeQueue *ptr = Q.head;
    printf("Isi Queue (Head ke Tail): [");
    while(ptr != NULL) {
        printf("%d%s", ptr->value, ptr->next ? ", " : "");
        ptr = ptr->next;
    }
    printf("]\n\n");
}

void deallocateQueue(struct Queue *Q) {
    printf("Proses pembebasan memori : \n");
    while (Q->head != NULL) {
        dequeue(Q);
    }
    printf("Memory Queue didealokasi secara total.\n");
}