#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 5 

struct NodeQueue {
    int value;
    struct NodeQueue *next;
};

struct Queue {
    struct NodeQueue *head;
    struct NodeQueue *tail;
    int curSize;
};

void allocateQueue(struct Queue *Q);
void enqueue(struct Queue *Q, int element);
int dequeue(struct Queue *Q);
int head(struct Queue Q);
int tail(struct Queue Q);
bool isEmpty(struct Queue Q);
bool isFull(struct Queue Q); 
void deallocateQueue(struct Queue *Q);
void print_queue(struct Queue Q); // Nama unik untuk Queue

#endif