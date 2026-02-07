#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

bool is_empty(struct node* head) {
    return (head == NULL);
}

void allocate(struct node** head, int size) {
    if(size <= 0) {
        return;
    }

    if(*head == NULL) {
        *head = malloc(sizeof(**head));
        (*head)->value = 0;
        (*head)->next = NULL;
    }

    for(int i = 0; i != size-1; i++) {
        struct node* new_node = malloc(sizeof(*new_node));
        new_node->value = 0;
        new_node->next = NULL;

        struct node* cursor = *head;
        while(cursor->next != NULL) {
            cursor=cursor->next;
        }
        cursor->next = new_node;
    }
}

void deallocate(struct node** head, int size) {
    for(int i=0; i != size; i++) {
        if((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }
    
        struct node* cursor = *head;
        while(cursor->next->next != NULL) {
            cursor=cursor->next;
        }
        free(cursor->next);
        cursor->next = NULL;
    }
}

void modify(struct node** head, int new_value, int position) {
    struct node* cursor = *head;
    for(int i = 0; i != position; i++) {
        if(cursor->next == NULL) {
            return;
        }
        cursor=cursor->next;
    }
    cursor->value = new_value;
}

void delete_node(struct node** head, int position) {
    struct node* next_address;
    struct node* cursor = *head;
    if(position == 0) {
        if(cursor->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }
        next_address = cursor->next;
        free(*head);
        *head = next_address;
        return;
    }

    for(int i = 0; i != position-1; i++) {
        if(cursor->next == NULL) {
            return;
        }
        cursor=cursor->next;
    }

    if(cursor->next->next == NULL) {
        free(cursor->next);
        cursor->next = NULL;
        return;
    }
    next_address = cursor->next->next;
    free(cursor->next);
    cursor->next = next_address;
}

void destroy(struct node** head) {
    while(*head != NULL) {
        if((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }

        struct node* cursor = *head;
        while(cursor->next->next != NULL) {
            cursor=cursor->next;
        }
        free(cursor->next);
        cursor->next = NULL;
    }
}

void iterate(struct node* head) {
    int i = 0;
    for(struct node* cursor = head; cursor != NULL; cursor=cursor->next) {
        printf("#%d: %d\n", i, cursor->value);
        i++;
    }
}

int length(struct node* head) {
    int length = 0;
    for(struct node* cursor = head; cursor != NULL; cursor=cursor->next) {
        length++;
    }
    return length;
}

int search(struct node* head, int searched_value) {
    int amount = 0;
    for(struct node* cursor = head; cursor != NULL; cursor=cursor->next) {
        if(cursor->value == searched_value) {
            amount++;
        }
    }
    return amount;
}
