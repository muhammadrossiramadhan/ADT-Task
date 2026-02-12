#ifndef BASICSL_H
#define BASICSL_H

#include <stdlib.h>
#include <stdio.h>

// Definisi Struktur
// ini adalah struct node yang merupakan deklarasi tipe data dari dua tipe data yang berbeda yaitu int value dan pointer.
struct node{
    
    int value;
    struct node *next;
};

// Daftar Fungsi (Prototipe), detail penjelasan lanjutanya di BasicSL.c
void dealocate(struct node *head);
void allocate(struct node **head, int value);
void count_of_nodes(struct node *head);
void print_nodes(struct node *head);
void add_at_the_end(struct node *head, int newvalue);
void add_at_the_Beginning(struct node **head, int newvalue);
void add_at_pos(struct node *head, int newvalue, int position);
void delete_at_first(struct node **head);
void delete_at_end(struct node **head);
void delete_at_pos(struct node **head, int position);
void search_node(struct node *head, int target);
void destroy(struct node **head);

#endif