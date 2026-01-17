#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
//     int element;
//     node* next;
//     node* prev;
// } node;

// typedef struct
// {
//     // declare head, tail, cur and other variables you need
// } linkedList;
typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    // declare head, tail, cur and other variables you need
    struct node *head;
    struct node *tail;
    struct node *cur;
    int size;

} linkedList;

void init(linkedList *list);

void free_list(linkedList *list);

void print(linkedList *list);

void insert(int item, linkedList *list);

int delete_cur(linkedList *list);

void append(int item, linkedList *list);

int size(linkedList *list);

void prev(int n, linkedList *list);

void next(int n, linkedList *list);

int is_present(int n, linkedList *list);

void clear(linkedList *list);

int delete_item(int item, linkedList *list);

void swap_ind(int ind1, int ind2, linkedList *list);

int search(int item, linkedList *list);

int find(int ind, linkedList *list);

int update(int ind, int value, linkedList *list);

int trim(linkedList *list);

void reverse(linkedList *list);

// you can define helper functions you need