#include<bits\stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "linkedList.h"

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
    bool nextisinsert;

} linkedList;

void init(linkedList *list)
{
    // implement initialization
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->nextisinsert = true;
    list->size = 0;
}

void free_list(linkedList *list)
{
    // implement destruction of list
    node *temp;
    while (list->head)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void print(linkedList *list)
{
    // implement list printing
    printf("[");
    if(list->head==NULL)
    {
        printf(".]\n");
        return;
    }
    node *temp = list->head;
    while (temp)
    {
        if(temp == list->cur)
        {
            printf("|");
        }
        printf("%d ",temp->element);
        temp = temp->next;
    }
    printf(" ]\n");
}

void insert(int item, linkedList *list)
{
    // implement insert function
    node *newNode = (node *)malloc(sizeof(node));
    newNode->element = item;
    node *temp = list->head;
    node *nextNode = NULL;
    if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        list->head = list->tail = list->cur = newNode;
        newNode->next = newNode->prev = NULL;
        list->size++;
    }
    else if (list->cur == list->tail)
    {
        newNode->prev = list->cur;
        list->cur->next = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        list->cur = list->tail;
        list->size++;
    }
    else
    {

        temp = list->cur;
        nextNode = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        nextNode->prev = newNode;
        newNode->next = nextNode;

        list->cur = newNode;
        list->size++;
    }
}

int delete_cur(linkedList *list)
{
    // implement deletion of current index function

    if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        return -1;
    }
    else if (list->cur == list->head)
    {
        if (list->tail == list->head)
        {
            node *temp = list->head;
            int x = temp->element;
            list->head = list->tail = list->cur = NULL;
            free(temp);
            list->size--;
            return x;
        }
        node *temp = list->head;
        node *newHead = temp->next;
        int x = temp->element;

        newHead->prev = NULL;

        list->head = newHead;
        list->cur = list->head;

        list->size--;
        free(temp);

        return x;
    }
    else if (list->cur == list->tail)
    {

        node *temp = list->tail;

        int x = temp->element;

        temp->prev->next = NULL;

        list->tail = temp->prev;
        list->cur = list->tail;

        list->size--;
        free(temp);

        return x;
    }
    else
    {
        node *temp = list->cur;
        int x = temp->element;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        list->cur = temp->next;
        list->size--;
        free(temp);
        return x;
    }
}

void append(int item, linkedList *list)
{
    // implement append function
    node *newTail = (node *)malloc(sizeof(node));
    newTail->element = item;
    if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        list->head = list->tail = list->cur = newTail;
        newTail->next = newTail->prev = NULL;
        list->size++;
    }
    else
    {

        list->tail->next = newTail;
        newTail->prev = list->tail;
        newTail->next = NULL;
        list->tail = newTail;
        list->cur = list->tail;
        list->size++;
    }
}

int size(linkedList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, linkedList *list)
{
    // implement prev function
    if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        return;
    }
    else if (list->head == list->tail)
        return;
    else if (list->cur == list->head)
    {
        return;
    }
    else
    {
        node *temp = list->cur;
        int count = 0;

        while (count < n)
        {
            if (temp == NULL || temp->prev == NULL)
            {
                list->cur = list->head;
                return;
            }

            temp = temp->prev;
            count++;
        }
        list->cur = temp;
    }
}

void next(int n, linkedList *list)
{
    // implement next function
    if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        return;
    }
    else if (list->head == list->tail)
        return;
    else if (list->cur == list->tail)
    {
        return;
    }
    else
    {
        node *temp = list->cur;
        int count = 0;

        while (count < n)
        {
            if (temp == NULL || temp->next == NULL)
            {
                list->cur = list->tail;
                return;
            }

            temp = temp->next;
            count++;
        }
        list->cur = temp;
    }
}

int is_present(int n, linkedList *list)
{
    // implement presence checking function
    node *temp = list->head;

    while (temp)
    {
        if (temp->element == n)
            return 1;
        temp = temp->next;
    }

    return 0;
}

void clear(linkedList *list)
{
    // implement list clearing function
    free_list(list);
    list->head = NULL;
    list->cur = NULL;
    list->tail = NULL;
    list->size = 0;
}

int delete_item(int item, linkedList *list)
{
    // implement item deletion function
    node *temp = list->head;
    while (temp)
    {
        list->cur = temp;
        if (temp->element == item)
        {
            delete_cur(list);
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    // implement swap function

    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
        return;

    if (ind1 == ind2)
        return;

    node *n1 = list->head;
    node *n2 = list->head;

    for (int i = 0; i < ind1; i++)
        n1 = n1->next;

    for (int i = 0; i < ind2; i++)
        n2 = n2->next;

    int temp = n1->element;
    n1->element = n2->element;
    n2->element = temp;
}

int search(int item, linkedList *list)
{
    // implement search function

    node *temp = list->head;
    int index = 0;
    while (temp)
    {
        if (temp->element == item)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int find(int ind, linkedList *list)
{
    // implement find function
    if (ind < 0 || ind >= list->size)
        return -1;

    node *n1 = list->head;
    int index = 0;
    for (int i = 0; i < ind; i++)
    {
        n1 = n1->next;
        index++;
    }
    return n1->element;

    
}

int update(int ind, int value, linkedList *list)
{
    // implement update function at metioned index position

 if (ind < 0 || ind >= list->size)
        return -1;

    node *n1 = list->head;
    int index = 0;
    for (int i = 0; i < ind; i++)
    {
        n1 = n1->next;
        index++;
    }
    int x=n1->element;
    n1->element=value;
    return x;
      

}

int trim(linkedList *list)
{
    // implement trim function
     node *n1 = list->tail;
      if (list->head == NULL && list->tail == NULL && list->cur == NULL)
    {
        return -1;
    }
    else if(list->head==list->tail)
    {
         int x=list->tail->element;
         list->head=list->tail=list->cur=NULL;
         list->size--;
         free(n1);
         return x;
    }
    else{

    

    int x=list->tail->element;
    list->tail=n1->prev;
    list->tail->next=NULL;
    list->cur=list->tail;
    free(n1);
    list->size--;

    return x;


    }


}

void reverse(linkedList *list)
{
    // implement reverse function
    if(list->head==NULL)
    {
        return;
    }
    if(list->head==list->tail)
    {
        return;
    }
    node* n1=list->head;
    node* n2=list->tail;
    while(n1!=n2  && n2->next !=n1)
    {
        int temp=n1->element;
        n1->element=n2->element;
        n2->element=temp;

        n1=n1->next;
        n2=n2->prev;
    }




}

// ----------- Function 11 (A1_A2): reverse_pos(ind1, ind2) -----------
// safest way: swap node values (not links)
void reverse_pos(int ind1, int ind2) {
    while (ind1 < ind2) {
        node* left = list->head;
        node* right = list->head;

        for (int i = 0; i < ind1; i++) left = left->next;
        for (int i = 0; i < ind2; i++) right = right->next;

        int temp = left->element;
        left->element = right->element;
        right->element = temp;

        ind1++;
        ind2--;
    }
}

// ----------- Function 11 (B1_B2): surprise_insert(item) -----------
void surprise_insert(int item, linkedList *list) {
    if (list->nextisinsert) insert(item, list);
    else append(item, list);

    list->nextisinsert = !list->nextisinsert;
}

// ----------- Function 11 (C1_C2): combine() -----------
void combine(linkedList *list) {
    // need current, current->next, current->next->next
    if (list->cur == nullptr || list->cur->next == nullptr || list->cur->next->next == nullptr) {
        printf("Invalid\n");
        return;
    }

    node* a = list->cur;
    node* b = list->cur->next;
    node* c = list->cur->next->next;

    a->element = a->element + b->element + c->element;

    a->next = c->next;

    free(b);
    free(c);

    list->size -= 2;
}


// you can define helper functions you need