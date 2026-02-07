#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int value;
    struct node* next;
};

bool is_empty(struct node* head);
void allocate(struct node** head, int size);
void deallocate(struct node** head, int size);
void modify(struct node** head, int new_value, int position);
void delete_node(struct node** head, int position);
void destroy(struct node** head);
void iterate(struct node* head);
int length(struct node* head);
int search(struct node* head, int searched_value);

#endif
