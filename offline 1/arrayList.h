#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
//     int *array;
//     // declare variables you need
// } arrayList;

typedef struct
{
    int *array;
    // declare variables you need
    int size;
    int capacity;
    int cur;
} arrayList;
void init(arrayList *list);

// implement initialization

void free_list(arrayList *list);

void increase_capacity(arrayList *list);

void decrease_capacity(arrayList *list);

void print(arrayList *list);

void insert(int item, arrayList *list);

int delete_cur(arrayList *list);

void append(int item, arrayList *list);

int size(arrayList *list);

void prev(int n, arrayList *list);

void next(int n, arrayList *list);

// implement next function

int is_present(int n, arrayList *list);

void clear(arrayList *list);

int delete_item(int item, arrayList *list);

void swap_ind(int ind1, int ind2, arrayList *list);

int search(int item, arrayList *list);

int find(int ind, arrayList *list);

// implement find function

int update(int ind, int value, arrayList *list);

// implement update function at metioned index position
int trim(arrayList *list);

// implement trim function
void reverse(arrayList *list);

// implement reverse function

// you can define helper functions you need