#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new;

    new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;

    return SUCCESS;
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;

    return SUCCESS;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *temp;

    for (temp = head1; temp; temp = temp->next)
        len1++;

    for (temp = head2; temp; temp = temp->next)
        len2++;

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;
        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}


