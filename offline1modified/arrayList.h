#include <stdio.h>
#include <stdlib.h>
//#include "arrayList.h"

typedef struct
{
    int *array;
    // declare variables you need
    int size;
    int capacity;
    int cur;
    int nextIsInsert;
} arrayList;

void init(arrayList *list)
{
    // implement initialization
    list->capacity = 2;
    list->size = 0;
    list->cur = -1;
    list->nextIsInsert = 1;
    list->array = (int *)malloc(list->capacity * sizeof(int));
}

void free_list(arrayList *list)
{

    free(list->array); 
    list->array = NULL;
    list->size = 0;
    list->capacity = 0;
    list->cur = -1;
}

// void increase_capacity(arrayList *list)
// {
//     // implement capacity increase
//     if (list->size+1 > list->capacity)
//     {
//         list->capacity *= 2;
//         list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
//     }

void increase_capacity(arrayList *list)
{

    if (list->size > list->capacity / 2)
    {
        list->capacity *= 2;

        list->array = (int *)realloc(
            list->array,
            list->capacity * sizeof(int));

        if (list->array == NULL)
        {

            return;
        }
    }
}

void decrease_capacity(arrayList *list)
{
    // implement capacity decrease

    if (list->size == 0)
    {
        if (list->capacity != 2)
        {
            list->capacity = 2;
            list->array = (int *)realloc(list->array,
                                         list->capacity * sizeof(int));
        }
        return;
    }

    if (list->size < list->capacity / 4 && list->capacity > 2)
    {
        list->capacity /= 2;
        list->array = (int *)realloc(list->array,
                                     list->capacity * sizeof(int));
    }
}

void print(arrayList *list)
{
    // implement list printing
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void insert(int item, arrayList *list)
{
    // implement insert function
   // printf("DEBUG insert: size=%d cur=%d\n", list->size, list->cur);
    increase_capacity(list);

    if (list->size == 0)
    {

        list->array[0] = item;
        list->size = 1;
        list->cur = 0;
        return;
    }

    for (int i = list->size - 1; i >= list->cur + 1; i--)
    {
        list->array[i + 1] = list->array[i];
    }
    list->array[list->cur + 1] = item;
    list->cur = list->cur + 1;
    list->size++;
}

int delete_cur(arrayList *list)
{
    // implement deletion of element at current index position
    //printf("DEBUG: delete_cur called, size=%d cur=%d\n", list->size, list->cur);

    if (list->size == 0 || list->cur == -1)
    {
        return -1;
    }

    int x = list->array[list->cur];
    for (int i = list->cur; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;

    if (list->size == 0)
    {
        list->cur = -1;
    }
    else if (list->cur >= list->size)
    {
        list->cur = list->size - 1;
    }
    else if (list->cur < list->size)

    {

        list->cur = list->cur - 1;
    }
    else
    {
        list->cur = 0;
    }

    decrease_capacity(list);

    return x;
}

void append(int item, arrayList *list)
{
    // implement append function

    increase_capacity(list);

    list->array[list->size] = item;
    list->size++;

    list->cur = list->size - 1;
}

int size(arrayList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList *list)
{
    // implement prev function
    if (list->size == 0 || list->cur == -1)
    {
        list->cur = -1;
        return;
    }
    else if (list->cur != -1 && list->cur < n)
    {
        list->cur = 0;
        return;
    }
    else
    {
        list->cur = list->cur - n;
    }
}

void next(int n, arrayList *list)
{
    // implement next function

    if (list->size == 0 || list->cur == -1)
    {
        list->cur = -1;
        return;
    }
    else if (list->cur + n >= list->size)
    {
        list->cur = list->size - 1;
        return;
    }
    else
    {
        list->cur = list->cur + n;
    }
}

int is_present(int n, arrayList *list)
{
    // implement presence checking function
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

void clear(arrayList *list)
{
    // implement list clearing function
    list->size = 0;
    list->cur = -1;
    decrease_capacity(list);
}

int delete_item(int item, arrayList *list)
{
    // implement item deletion function
    int ind = -1;
    int x;
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        return -1;
    }
    x = list->array[ind];
    for (int i = ind; i < list->size - 1; i++)

    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->size == 0)
    {
        list->cur = -1;
    }
    else if (list->cur >= list->size)
    {
        list->cur = list->size - 1;
    }
    else
    {
        list->cur = ind;
    }
    decrease_capacity(list);
    return x;
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    // implement swap function at metioned index position
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
    {
        return;
    }
    else if (list->size == 0)
    {
        return;
    }
    else
    {
        int temp = list->array[ind1];
        list->array[ind1] = list->array[ind2];
        list->array[ind2] = temp;
    }
}

int search(int item, arrayList *list)
{
    // implement search function

    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            return i;
        }
    }

    return -1;
}

int find(int ind, arrayList *list)
{
    // implement find function
    if (ind < 0 || ind >= list->size)

    {
        return -1;
    }

    return list->array[ind];
}

int update(int ind, int value, arrayList *list)
{
    // implement update function at metioned index position
    if (ind < 0 || ind >= list->size)

    {
        return -1;
    }
    int x = list->array[ind];
    list->array[ind] = value;

    return x;
}

int trim(arrayList *list)
{
    // implement trim function
    if (list->size == 0)
        return -1;
    int x = list->array[list->size - 1];
    list->size--;
    if (list->size == 0)
        list->cur = -1;
    else if (list->cur >= list->size)
        list->cur = list->size - 1;
    else
    {
        list->cur = list->size - 1;
    }
    decrease_capacity(list);
    return x;
}

void reverse(arrayList *list)
{
    // implement reverse function

    int left = 0;
    int right = list->size - 1;
    while (left < right)
    {
        int temp = list->array[left];
        list->array[left] = list->array[right];
        list->array[right] = temp;
        left++;
        right--;
    }
}

// ----------- Function 11 (A1_A2): reverse_pos(ind1, ind2) -----------
void reverse_pos(int ind1, int ind2, arrayList *list) {
    while (ind1 < ind2) {
        int temp = list->array[ind1];
        list->array[ind1] = list->array[ind2];
        list->array[ind2] = temp;
        ind1++;
        ind2--;
    }
}

// ----------- Function 11 (B1_B2): surprise_insert(item) -----------
void surprise_insert(int item, arrayList *list) {
    if (list->nextIsInsert) insert(item, list);
    else append(item, list);

    list->nextIsInsert = !list->nextIsInsert;
}

// ----------- Function 11 (C1_C2): combine() -----------
void combine(arrayList *list) {
    if (list->cur >= list->size - 2) {
        printf("Invalid\n");
        return;
    }

    int sum = list->array[list->cur] + list->array[list->cur + 1] + list->array[list->cur + 2];
    list->array[list->cur] = sum;

    // remove curr+1 and curr+2 by shifting left
    for (int i = list->cur + 1; i < list->size - 2; i++) {
        list->array[i] = list->array[i + 2];
    }

    list->size -= 2;
    decrease_capacity(list);
}


// you can define helper functions you need