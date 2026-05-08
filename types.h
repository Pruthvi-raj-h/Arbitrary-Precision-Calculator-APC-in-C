#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;

/* Doubly Linked List Node */
typedef struct node
{
    data_t data;
    struct node *prev;
    struct node *next;
} Dlist;

// insert the data at last of double linked list
int dl_insert_last(Dlist **head, Dlist **tail, int data);

// insert the data at first of double linked list
int dl_insert_first(Dlist **head, Dlist **tail, int data);

// Addition operation
int Addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **resh,  Dlist **rest);

// substraction operation
int Substraction(Dlist **head1, Dlist **tail1,
                 Dlist **head2, Dlist **tail2,
                 Dlist **resh,  Dlist **rest);

// compare list
int compare_lists(Dlist *head1, Dlist *head2);

// multiplication operation
int Multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **resh,  Dlist **rest);

// division operation
int Division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **resh,  Dlist **rest);




#endif
